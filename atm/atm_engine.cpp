#include "atm_engine.h"
#include "file_storage.h"
#include "recovery.h"
#include <iostream>
// Инициализируем журнал файлом "journal.bin". В начале сессии карты нет, суточный лимит по нулям.
ATMEngine::ATMEngine() 
    : currentCard(nullptr), journal("journal.bin"), dailyWithdrawn(0.0) {
    
    // ВАЖНО: При запуске банкомата сразу накатываем историю из файла для восстановления баланса!
    RecoverySystem::restoreAccountState(currentAccount, journal);
}

ATMEngine::~ATMEngine() {
    ejectCard(); // Если банкомат выключается, принудительно выплевываем карту.
}

bool ATMEngine::insertCard(const std::string& cardNumber) {
    if (currentCard != nullptr) {
        std::cout << "Ошибка: Карточка уже внутри банкомата!\n";
        return false;
    }
    
    currentCard = FileStorage::loadCard(cardNumber);
    if (currentCard == nullptr) {
        std::cout << "Ошибка: Карта не найдена в системе.\n";
        return false;
    }
    
    if (currentCard->checkIfBlocked()) {
        std::cout << "Ошибка: Данная карта заблокирована банком!\n";
        currentCard = nullptr;
        return false;
    }
    return true;
}

bool ATMEngine::enterPIN(const std::string& pin) {
    if (currentCard == nullptr) return false;

    if (currentCard->verifyPIN(pin)) {
        std::cout << "Авторизация успешна!\n";
        return true;
    } else {
        std::cout << "Неверный PIN-код!\n";
        if (currentCard->checkIfBlocked()) {
            std::cout << "Внимание! Вы трижды ввели неверный PIN. Карта заблокирована!\n";
            FileStorage::saveCardStatus(*currentCard); // Сохраняем блокировку.
            currentCard = nullptr; // Выкидываем её.
        }
        return false;
    }
}

void ATMEngine::checkBalance() const {
    std::cout << "Текущий баланс счета: " << currentAccount.getBalance() << " руб.\n";
}

void ATMEngine::depositMoney(double amount) {
    if (amount <= 0) {
        std::cout << "Ошибка: Некорректная сумма пополнения.\n";
        return;
    }

    // Создаем транзакцию пополнения
    Transaction tx{ TransactionType::DEPOSIT, amount, std::time(nullptr) };
    
    currentAccount.deposit(amount); // Меняем баланс в памяти.
    journal.logTransaction(tx);      // Пишем транзакцию в бинарный append-only файл.
    currentAccount.addTransaction(tx); // Добавляем в историю сессии.

    std::cout << "Счет успешно пополнен на " << amount << " руб.\n";
}

void ATMEngine::withdrawMoney(double amount) {
    // 1. Проверка базовой корректности
    if (amount <= 0) {
        std::cout << "Ошибка: Некорректная сумма.\n";
        return;
    }
    // 2. Лимит на разовое снятие (не более 10 000 руб)
    if (amount > MAX_SINGLE_WITHDRAWAL) {
        std::cout << "Отказ: Нельзя снять более " << MAX_SINGLE_WITHDRAWAL << " руб. за один раз.\n";
        return;
    }
    // 3. Проверка суточного лимита (не более 50 000 руб)
    if (dailyWithdrawn + amount > MAX_DAILY_LIMIT) {
        std::cout << "Отказ: Превышен суточный лимит снятия (" << MAX_DAILY_LIMIT << " руб.). "
                  << "Вы уже сняли: " << dailyWithdrawn << " руб.\n";
        return;
    }

    // 4. Считаем комиссию: 1%, но не меньше 30 руб.
    double commission = amount * COMMISSION_RATE;
    if (commission < MIN_COMMISSION) {
        commission = MIN_COMMISSION;
    }

    double totalDeduction = amount + commission; // Общая сумма, которую надо списать.
    std::cout << "Комиссия за операцию составит: " << commission << " руб.\n";

    // 5. Пытаемся списать деньги со счета
    if (currentAccount.withdraw(totalDeduction)) {
        // Создаем транзакцию. В журнал пишем ЧИСТУЮ сумму изменения баланса (с учетом комиссии)!
        Transaction tx{ TransactionType::WITHDRAWAL, totalDeduction, std::time(nullptr) };
        
        journal.logTransaction(tx); // Логируем на диск.
        currentAccount.addTransaction(tx); // Логируем в память.
        dailyWithdrawn += amount; // Накапливаем суточный счетчик.

        std::cout << "Успешно снято: " << amount << " руб. (Списано с комиссией: " << totalDeduction << " руб.)\n";
    } else {
        std::cout << "Ошибка: Недостаточно средств на счете (Требуется " << totalDeduction << " руб.).\n";
    }
}

void ATMEngine::printHistory() {
    std::cout << "=== ПОСЛЕДНИЕ 5 ОПЕРАЦИЙ ===\n";
    // Запрашиваем ровно 5 штук
    std::vector<Transaction> history = currentAccount.getLastTransactions(5);

    if (history.empty()) {
        std::cout << "История операций пуста.\n";
        return;
    }

    for (const auto& tx : history) {
    std::string typeStr = (tx.type == TransactionType::DEPOSIT) ? "Пополнение" : "Снятие (с ком.)";
    
    std::time_t tempTime = tx.timestamp;
    // Используем стандартный ctime, который понимает GCC
    std::string dateStr = std::ctime(&tempTime); 
    
    // Чистим перенос строки на конце
    if (!dateStr.empty() && dateStr.back() == '\n') {
        dateStr.pop_back(); 
    }

    std::cout << "[" << dateStr << "] " << typeStr << ": " << tx.amount << " руб.\n";
}
}

void ATMEngine::ejectCard() {
    if (currentCard != nullptr) {
        delete currentCard; // Освобождаем память кучи, выделенную под карту.
        currentCard = nullptr;
        std::cout << "Карта успешно извлечена. Всего хорошего!\n";
    }
}
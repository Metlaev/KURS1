#include <iostream>
#include "atm_engine.h"
#include "tests/tests.h" // 1. Подключаем заголовок тестов

// Нам нужна локализация, чтобы консоль не выводила иероглифы вместо русского языка.
int main() {
    std::setlocale(LC_ALL, "Russian");

    runAllTests(); // 2. Запускаем тесты ПЕРЕД запуском самого банкомата
    ATMEngine atm; // Создаем объект банкомата. В этот момент срабатывает система восстановления!
    std::cout << "[СИСТЕМА] Банкомат запущен. Состояние баланса успешно синхронизировано с journal.bin.\n";

    std::string cardNum, pin;
    
    // Шаг 1: Имитируем "Вставьте карту"
    std::cout << "=== ДОБРО ПОЖАЛОВАТЬ В КОНСОЛЬНЫЙ БАНКОМАТ ===\n";
    std::cout << "Введите номер карты (Попробуйте '1111'): ";
    std::cin >> cardNum;

    if (!atm.insertCard(cardNum)) {
        return 0; // Если карту не нашли или она забанена — тушим программу.
    }

    // Шаг 2: Ввод пин-кода (у нас есть 3 попытки внутри класса Card)
    bool authenticated = false;
    while (atm.hasCard() && !authenticated) {
        std::cout << "Введите PIN-код (Правильный '1234'): ";
        std::cin >> pin;
        if (atm.enterPIN(pin)) {
            authenticated = true;
        }
    }

    // Если трижды ошиблись, нас выкинуло из цикла и карта сбросилась
    if (!authenticated) {
        std::cout << "Сессия завершена из-за блокировки карты.\n";
        return 0;
    }

    // Шаг 3: Главное меню операций
    int choice = 0;
    do {
        std::cout << "\n--- ГЛАВНОЕ МЕНЮ ---\n";
        std::cout << "1. Проверить баланс\n";
        std::cout << "2. Пополнить счет\n";
        std::cout << "3. Снять наличные\n";
        std::cout << "4. История операций (последние 5)\n";
        std::cout << "5. Завершить работу и вернуть карту\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2: {
                double depAmount;
                std::cout << "Введите сумму для пополнения: ";
                std::cin >> depAmount;
                atm.depositMoney(depAmount);
                break;
            }
            case 3: {
                double withdrawAmount;
                std::cout << "Введите сумму для снятия (Макс. 10000 за раз): ";
                std::cin >> withdrawAmount;
                atm.withdrawMoney(withdrawAmount);
                break;
            }
            case 4:
                atm.printHistory();
                break;
            case 5:
                atm.ejectCard();
                std::cout << "Сессия закрыта.\n";
                break;
            default:
                std::cout << "Неверный пункт меню! Попробуйте снова.\n";
        }
    } while (choice != 5 && atm.hasCard());

    return 0;
}
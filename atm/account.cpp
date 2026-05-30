#include "account.h"

// Стартуем с нулевым балансом.
Account::Account() : balance(0.0) {}

// Просто отдаем текущие деньги.
double Account::getBalance() const { 
    return balance; 
}

// Пополнение счета. Просто прибавляем сумму к балансу. Проще некуда!
void Account::deposit(double amount) {
    if (amount > 0) { // Проверка на дурака, чтобы нельзя было пополнить на отрицательную сумму.
        balance += amount;
    }
}

// Снятие денег.
bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) { // Если сумма корректная и денег хватает:
        balance -= amount; // Вычитаем из баланса.
        return true;       // Успешно!
    }
    return false; // Либо денег мало, либо ты ввел бред. Операция отклонена.
}

// Закидываем транзакцию в наш вектор истории.
void Account::addTransaction(const Transaction& tx) {
    history.push_back(tx);
}

// Самое интересное: выгребаем последние 5 (или сколько попросят) операций.
std::vector<Transaction> Account::getLastTransactions(int count) const {
    std::vector<Transaction> lastTx;
    // Если транзакций в истории меньше, чем попросили, берем сколько есть.
    int startIdx = history.size() - count;
    if (startIdx < 0) startIdx = 0;

    // Бежим циклом с конца истории и копируем элементы.
    for (size_t i = startIdx; i < history.size(); ++i) {
        lastTx.push_back(history[i]);
    }
    return lastTx;
}
#pragma once
#include <vector>
#include "transaction.h"

class Account {
private:
    double balance; // Текущий баланс на счете.
    std::vector<Transaction> history; // Вектор (динамический массив) для хранения истории транзакций.

public:
    Account(); // Конструктор по умолчанию (баланс = 0).
    
    double getBalance() const; // Посмотреть баланс.
    void deposit(double amount); // Метод пополнения.
    bool withdraw(double amount); // Метод снятия денег (возвращает false, если не хватило баланса).
    void addTransaction(const Transaction& tx); // Добавить транзакцию в историю.
    std::vector<Transaction> getLastTransactions(int count) const; // Получить последние N транзакций.
};
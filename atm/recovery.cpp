#include "recovery.h"

void RecoverySystem::restoreAccountState(Account& account, Journal& journal) {
    // Вытаскиваем из файла абсолютно все транзакции, которые там накопились.
    std::vector<Transaction> allTransactions = journal.readAllTransactions();

    // Накатываем транзакции по очереди.
    for (const auto& tx : allTransactions) {
        if (tx.type == TransactionType::DEPOSIT) {
            account.deposit(tx.amount); // Если было пополнение — добавляем к балансу.
        } else if (tx.type == TransactionType::WITHDRAWAL) {
            account.withdraw(tx.amount); // Если было снятие — вычитаем.
        }
        // И не забываем добавить эту транзакцию в историю самого объекта аккаунта!
        account.addTransaction(tx);
    }
}
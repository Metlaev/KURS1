#pragma once
#include <string>
#include <vector>
#include "transaction.h"

class Journal {
private:
    std::string filename; // Имя файла, куда пишем логи (например, "journal.bin").

public:
    Journal(std::string file); // Конструктор принимает имя файла.
    void logTransaction(const Transaction& tx); // Запись одной транзакции в конец файла.
    std::vector<Transaction> readAllTransactions(); // Чтение вообще всех транзакций из файла (для восстановления).
};
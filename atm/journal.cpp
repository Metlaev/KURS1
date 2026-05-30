#include "journal.h"
#include <fstream> // Для работы с файловыми потоками.

Journal::Journal(std::string file) : filename(file) {}

// Запись транзакции в файл.
void Journal::logTransaction(const Transaction& tx) {
    // Открываем файл: out (на запись), binary (в бинарном виде), app (дописывать в конец!).
    std::ofstream out(filename, std::ios::out | std::ios::binary | std::ios::app);
    
    if (out.is_open()) {
        // reinterpret_cast превращает указатель на структуру в указатель на сырые байты (char*).
        // sizeof(Transaction) говорит компилятору, сколько именно байт нужно вытолкнуть в файл.
        out.write(reinterpret_cast<const char*>(&tx), sizeof(Transaction));
        out.close(); // Обязательно закрываем файл, чтобы данные сбросились с буфера на диск.
    }
}

// Чтение всех транзакций. Это нужно, если банкомат «упал» и хочет воскреснуть.
std::vector<Transaction> Journal::readAllTransactions() {
    std::vector<Transaction> txList;
    // Открываем файл на чтение (in) в бинарном режиме (binary).
    std::ifstream in(filename, std::ios::in | std::ios::binary);

    if (in.is_open()) {
        Transaction tx;
        // Читаем из файла кусками размером со структуру Transaction.
        // Цикл крутится, пока метод read не наткнется на конец файла (EOF).
        while (in.read(reinterpret_cast<char*>(&tx), sizeof(Transaction))) {
            txList.push_back(tx); // Складываем прочитанную транзакцию в вектор.
        }
        in.close(); // Закрываем за собой дверь.
    }
    return txList; // Возвращаем собранный список транзакций.
}
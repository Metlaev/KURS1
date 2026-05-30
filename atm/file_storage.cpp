#include "file_storage.h"
#include <iostream>

Card* FileStorage::loadCard(const std::string& cardNumber) {
    // Для простоты жестко пропишем тестовую карту. Номер "1111", PIN "1234".
    if (cardNumber == "1111") {
        return new Card("1111", "1234");
    }
    return nullptr; // Если ввели другой номер — такой карты "нет в базе".
}

void FileStorage::saveCardStatus(const Card& card) {
    if (card.checkIfBlocked()) {
        // Имитируем запись в базу данных о том, что карта забанена.
        std::cout << "[СИСТЕМА] Статус карты " << card.getNumber() << " обновлен: ЗАБЛОКИРОВАНА.\n";
    }
}
#pragma once
#include "card.h"

class FileStorage {
public:
    // Ищем карту по ее номеру. Если нашли — возвращаем указатель на объект Card.
    static Card* loadCard(const std::string& cardNumber);
    // Сохраняем статус карты (например, если заблокировали).
    static void saveCardStatus(const Card& card);
};
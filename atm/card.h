#pragma once
#include <string>

class Card {
private:
    std::string cardNumber; // Номер карты. Используем string, чтобы не потерять ведущие нули.
    std::string pinCode;    // PIN-код. Тоже строка.
    bool isBlocked;         // Флаг: true — карта заблокирована, false — всё ок.
    int pinAttempts;        // Счетчик неудачных попыток ввода PIN-кода.

public:
    // Конструктор: инициализируем карту номером и пином, попыток 0, не заблокирована.
    Card(std::string number, std::string pin);

    std::string getNumber() const; // Метод для получения номера карты (константный, ничего не меняет).
    bool checkIfBlocked() const;  // Проверить, заблокирована ли карта.
    bool verifyPIN(const std::string& inputPin); // Проверка PIN-кода.
    void block(); // Принудительная блокировка.
};
#include "card.h"

// Конструктор просто копирует переданные данные в скрытые поля класса.
Card::Card(std::string number, std::string pin) 
    : cardNumber(number), pinCode(pin), isBlocked(false), pinAttempts(0) {}

// Возвращаем номер карты. Запомни, const в конце значит, что метод не ломает данные внутри объекта.
std::string Card::getNumber() const { 
    return cardNumber; 
}

// Возвращаем статус блокировки. Если true — клиенту не повезло.
bool Card::checkIfBlocked() const { 
    return isBlocked; 
}

// А вот тут главная логика авторизации. Слушай внимательно!
bool Card::verifyPIN(const std::string& inputPin) {
    if (isBlocked) return false; // Если карта уже заблокирована, даже проверять не будем.

    if (pinCode == inputPin) { // Если введенный пин совпал с правильным:
        pinAttempts = 0; // Сбрасываем счетчик ошибок в ноль. Ты же вспомнил пароль!
        return true;     // Доступ разрешен.
    } else { // Если юзер ошибся:
        pinAttempts++; // Увеличиваем счетчик ошибок на 1.
        if (pinAttempts >= 3) { // Опа! Три ошибки!
            isBlocked = true; // Блокируем карту к чертям.
        }
        return false; // Доступ закрыт.
    }
}

// Метод ручной блокировки (например, если нам из хранилища пришло, что она уже забанена).
void Card::block() { 
    isBlocked = true; 
}
#pragma once
#include "card.h"
#include "account.h"
#include "journal.h"

class ATMEngine {
private:
    Card* currentCard;       // Указатель на карту, которая сейчас торчит в банкомате.
    Account currentAccount;  // Аккаунт, привязанный к текущей сессии.
    Journal journal;         // Объект для ведения журнала.
    double dailyWithdrawn;   // Сколько денег уже сняли за текущие сутки в рамках сессии.

    // Константы ограничений, как просили в задании:
    const double MAX_SINGLE_WITHDRAWAL = 10000.0; // Макс за один раз.
    const double MAX_DAILY_LIMIT = 50000.0;       // Макс за сутки.
    const double COMMISSION_RATE = 0.01;         // Комиссия 1%.
    const double MIN_COMMISSION = 30.0;          // Но не менее 30 руб.

public:
    ATMEngine(); // Конструктор ядра.
    ~ATMEngine(); // Деструктор для очистки памяти.

    bool insertCard(const std::string& cardNumber); // Вставить карту.
    bool enterPIN(const std::string& pin);          // Ввести ПИН.
    void checkBalance() const;                     // Проверить баланс.
    void depositMoney(double amount);              // Пополнить счет.
    void withdrawMoney(double amount);             // Снять деньги (с расчетом комиссии).
    void printHistory();                           // Показать последние 5 операций.
    void ejectCard();                              // Вытащить карту и закрыть сессию.
    bool hasCard() const { return currentCard != nullptr; } // Проверка, внутри ли карта.
};
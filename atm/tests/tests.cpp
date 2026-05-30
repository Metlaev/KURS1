#include "tests.h"
#include "../card.h"      // Поднимаемся на уровень выше, чтобы взять классы банкомата
#include "../account.h"
#include <iostream>
#include <cassert>        // Библиотека для функции assert

// Тест 1: Проверяем, что карта правильно считает попытки PIN и блокируется
void testCardBlocking() {
    Card testCard("7777", "5555");
    
    // Проверяем, что изначально карта не заблокирована
    assert(testCard.checkIfBlocked() == false);
    
    // Вводим неверный PIN первый раз
    assert(testCard.verifyPIN("1111") == false);
    assert(testCard.checkIfBlocked() == false); // Еще не должна заблокироваться
    
    // Вводим неверный PIN второй раз
    testCard.verifyPIN("2222");
    
    // Вводим неверный PIN третий раз — БАМ!
    testCard.verifyPIN("3333");
    assert(testCard.checkIfBlocked() == true); // Вот теперь обязана быть заблокирована!
    
    std::cout << "[TEST] Тест блокировки карты: ПРОЙДЕН\n";
}

// Тест 2: Проверяем баланс и логику списания денег
void testAccountOperations() {
    Account acc;
    
    // Изначально баланс должен быть нулевым
    assert(acc.getBalance() == 0.0);
    
    // Пополняем на 500 рублей
    acc.deposit(500.0);
    assert(acc.getBalance() == 500.0);
    
    // Пробуем снять 200 рублей — должно сработать
    bool success = acc.withdraw(200.0);
    assert(success == true);
    assert(acc.getBalance() == 300.0);
    
    // Пробуем снять миллион — должно отказать (false) и баланс не должен измениться
    bool failure = acc.withdraw(1000000.0);
    assert(failure == false);
    assert(acc.getBalance() == 300.0);
    
    std::cout << "[TEST] Тест операций по счету: ПРОЙДЕН\n";
}

// Главный запускальщик тестов
void runAllTests() {
    std::cout << "\n=== ЗАПУСК АВТОМАТИЧЕСКИХ ТЕСТОВ ===\n";
    testCardBlocking();
    testAccountOperations();
    std::cout << "=== ВСЕ ТЕСТЫ УСПЕШНО ПРОЙДЕНЫ! ===\n\n";
}

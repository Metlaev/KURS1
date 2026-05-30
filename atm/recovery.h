#pragma once
#include "account.h"
#include "journal.h"

class RecoverySystem {
public:
    // Статический метод. Передаем ссылку на аккаунт и журнал, чтобы восстановить состояние денег.
    static void restoreAccountState(Account& account, Journal& journal);
};
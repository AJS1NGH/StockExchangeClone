//
// Created by Alamjeet Singh on 2019-06-05.
//

#ifndef STOCKEXCHANGE_TRADER_H
#define STOCKEXCHANGE_TRADER_H


#include "../BankAccount/BankAccount.h"
#include "../TradingSystem/TradingSystem.h"
#include "../Portfolio/Portfolio.h"

using namespace std;

class Trader {
private:
    BankAccount bankAccount;
    TradingSystem tradingSystem;
    Portfolio portfolio;
};


#endif //STOCKEXCHANGE_TRADER_H

//
// Created by Alamjeet Singh on 2019-06-05.
//

#ifndef STOCKEXCHANGE_BANKACCOUNT_H
#define STOCKEXCHANGE_BANKACCOUNT_H

#include <mutex>
using namespace std;
class BankAccount {
private:
    double balance;
    mutex mx;
public:
    BankAccount();
    BankAccount(double balance);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
};


#endif //STOCKEXCHANGE_BANKACCOUNT_H

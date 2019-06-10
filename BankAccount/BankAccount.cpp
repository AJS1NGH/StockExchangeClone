//
// Created by Alamjeet Singh on 2019-06-05.
//

#include "BankAccount.h"
#include <iostream>
#include <mutex>
using namespace std;
BankAccount::BankAccount() {
    balance = 0.0;
}

BankAccount::BankAccount(double balance) {
    if (balance>0) {
        this->balance = balance;
    }
    else {
        BankAccount();
    }
}

void BankAccount::deposit(double amount) {
    mx.lock();
    if (amount>0) {
        balance+=amount;
    }
    cout<<"Deposit successful"<<endl;
    cout<<"New balance is: "<<balance<<endl;
    mx.unlock();
}

void BankAccount::withdraw(double amount) {
    mx.lock();
    if (amount<=balance) {
        balance-=amount;
        cout<<"Withdrawal successful"<<endl;
        cout<<"New balance is: "<<balance<<endl;

    }
    else {
        cout<<"Not enough balance to withdraw"<<endl;
        cout<<"Current balance is: "<<balance<<endl;
    }
    mx.unlock();
}

double BankAccount::getBalance() {
    return balance;
}
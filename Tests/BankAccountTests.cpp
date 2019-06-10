//
// Created by Alamjeet Singh on 2019-06-05.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../BankAccount/BankAccount.h"
#include <thread>
#include <numeric>

int it = 10;
vector<int> withdrawdeposit(it);
vector<thread> threads;
vector<double> amounts(it);
auto w = &BankAccount::withdraw;
auto d = &BankAccount::deposit;
BankAccount *b1;
BankAccount *b2;

void setupMain() {
    b1 = new BankAccount();
    b2 = new BankAccount(250000);
    for (int i = 0; i < it; ++i) {
        if (i%2==0) {
            withdrawdeposit[i] = 0;
            amounts[i] = 485948*-1*(i+1);
        }
        else {
            withdrawdeposit[i] = 1;
            amounts[i] = 33043*(i+1);
        }
    }
}

void setupDeposit() {
    b1 = new BankAccount();
    b2 = new BankAccount(250000);
    for (int i = 0; i < it; ++i) {
        withdrawdeposit[i] = 1;
        amounts[i] = 485948*i;
    }
}

void setupWithddraw() {
    b1 = new BankAccount();
    b2 = new BankAccount(250000);
    for (int i = 0; i < it; ++i) {
        withdrawdeposit[i] = 0;
        amounts[i] = 485948*i;
    }
}
void reset(){
    threads.clear();
    withdrawdeposit.clear();
    amounts.clear();
    delete b1;
    delete b2;
    b1 = NULL;
    b2 = NULL;
}

TEST(TBankAccount, constructor1) {
    b1 = new BankAccount();
    EXPECT_DOUBLE_EQ(b1->getBalance(),0.0);
    reset();
}

TEST(TBankAccount, tconstructor2) {
    b2 = new BankAccount(250000);
    EXPECT_DOUBLE_EQ(b2->getBalance(),250000);
    reset();
}

TEST(TBankAccount, tparallel1) {
    setupMain();
    for (int i = 0; i < it; ++i) {
        if (withdrawdeposit[i]==0) {
            threads.emplace_back(thread(w, b1,amounts[i]));
        }
        else {
            threads.emplace_back(thread(d, b1,amounts[i]));
        }
    }
    for (int i = 0; i < it; ++i) {
        threads[i].join();
    }
    EXPECT_GT(b1->getBalance(),(double)accumulate(amounts.begin(),amounts.end(),0));
    EXPECT_GT(b1->getBalance(), 0);
    reset();
}

TEST(TBankAccount, tparallelD) {
    setupDeposit();
    for (int i = 0; i < it; ++i) {
        threads.emplace_back(thread(d, b1,amounts[i]));
    }
    double sum = 0;
    for (int i = 0; i < it; ++i) {
        sum+=amounts[i];
        threads[i].join();
    }
    EXPECT_DOUBLE_EQ(b1->getBalance(),sum);
    reset();
}

TEST(TBankAccount, tparallelW) {
    setupWithddraw();
    for (int i = 0; i < it; ++i) {
        threads.emplace_back(thread(w, b1,amounts[i]));
    }
    for (int i = 0; i < it; ++i) {
        threads[i].join();
    }
    EXPECT_DOUBLE_EQ(b1->getBalance(),0);
    reset();
}

TEST(TBankAccount, tparallelW2) {
    setupWithddraw();
    for (int i = 0; i < it; ++i) {
        threads.emplace_back(thread(w, b2,amounts[i]));
    }
    for (int i = 0; i < it; ++i) {
        threads[i].join();
    }
    EXPECT_DOUBLE_EQ(b2->getBalance(),250000);
    reset();
}


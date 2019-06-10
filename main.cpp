#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include "BankAccount/BankAccount.h"
#include "Stock/Stock.h"
#include <time.h>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace std::placeholders;

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();
//    clock_t t;
//    default_random_engine generatorV;
//    default_random_engine generatorP;
//    normal_distribution<float> d(23000,3000);
//    lognormal_distribution<float> p(30,12);
//    t = clock();
//    Stock *AAPL = new Stock();
//
//    cout<<"StockFacts:"<<endl;
//    cout<<"Vol:"<<AAPL->getVolume()<<endl;
//    cout<<"MC:"<<AAPL->getmarketCap()<<endl;
//    cout<<"low:"<<AAPL->getLow()<<endl;
//    cout<<"High:"<<AAPL->getHigh()<<endl;
//
//    vector<int> volume(20);
//    vector<double> prices(20);
//    vector<thread> threads;
//
//    for (int i = 0; i<20; i++) {
//        volume[i] = (int)d(generatorV);
//        prices[i] = (double)p(generatorP);
//    }
//
//    auto func = &Stock::updatePriceVolume;
//    for (int i =0; i<20; i++) {
//        threads.emplace_back(thread(func,AAPL,prices[i],volume[i]));
//    }
//    for (int i = 0; i<20; i++) {
//        threads[i].join();
//    }
//    cout<<"StockFacts:"<<endl;
//    cout<<"Vol:"<<AAPL->getVolume()<<endl;
//    cout<<"MC:"<<AAPL->getmarketCap()<<endl;
//    cout<<"low:"<<AAPL->getLow()<<endl;
//    cout<<"High:"<<AAPL->getHigh()<<endl;
//
//    t = clock()-t;
//    cout<<"Time taken: "<<t<<endl;
    return 0;
}
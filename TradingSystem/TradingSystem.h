//
// Created by Alamjeet Singh on 2019-06-05.
//

#ifndef STOCKEXCHANGE_TRADINGSYSTEM_H
#define STOCKEXCHANGE_TRADINGSYSTEM_H


#include "../OrderBook/OrderBook.h"
#include <iostream>
using namespace std;
class OrderBook;
class TradingSystem {
private:
    OrderBook *orderBook;
public:
    TradingSystem() {
        cout<<"trading system created"<<endl;
    }
};


#endif //STOCKEXCHANGE_TRADINGSYSTEM_H

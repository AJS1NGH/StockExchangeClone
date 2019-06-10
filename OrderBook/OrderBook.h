//
// Created by Alamjeet Singh on 2019-06-05.
//

#ifndef STOCKEXCHANGE_ORDERBOOK_H
#define STOCKEXCHANGE_ORDERBOOK_H


#include "../TradingSystem/TradingSystem.h"
#include "../Stock/Stock.h"
#include "../Order/Order.h"
#include <vector>
#include <iostream>


using namespace std;
class TradingSystem;
class OrderBook {
private:
    vector<Stock> stocks;
    vector<TradingSystem> tradingSystems;
    vector<Order> order;

public:
    OrderBook() {
        cout<<"order book created"<<endl;
    }
};


#endif //STOCKEXCHANGE_ORDERBOOK_H

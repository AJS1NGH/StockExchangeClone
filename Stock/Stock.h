//
// Created by Alamjeet Singh on 2019-06-05.
//

#ifndef STOCKEXCHANGE_STOCK_H
#define STOCKEXCHANGE_STOCK_H

#include <iostream>
#include <string>
#include <mutex>
#include <atomic>

using namespace std;

class Stock {
private:
    int sharesOutstanding, volume;
    double ipoPrice, price, marketCap, high, low;
    string name;
    string ticker;
    mutex mx;
    void updateHighLow(double newPrice);

public:
    Stock();
    Stock(int _sharesOutstanding, double _ipoPrice, string _name, string _ticker);
    void updatePriceVolume(double newPrice, int sharesTraded);
    double getHigh();
    double getLow();
    double getmarketCap();
    int getVolume();
    string getTicker() const;
    string getName();
    bool operator==(const Stock &rhs) const;
    bool operator!=(const Stock &rhs) const;
    Stock(const Stock &stk);
};

namespace std {
    template<>
    struct hash<Stock> {
        size_t operator()(const Stock &obj) const;
    };
};

#endif //STOCKEXCHANGE_STOCK_H

//
// Created by Alamjeet Singh on 2019-06-05.
//

#include "Stock.h"
#include <iostream>
using namespace std;

Stock::Stock() {
    sharesOutstanding = 1000000;
    ipoPrice = price = 30.0;
    marketCap = 30.0*1000000;
    volume = 0;
    high = low = 30.0;
}
Stock::Stock(int _sharesOutstanding, double _ipoPrice, string _name, string _ticker) {
    if (_sharesOutstanding <= 0 || _ipoPrice <= 0.0 || _name.empty() || _ticker.empty()) {
        Stock();
    }
    else {
        sharesOutstanding = _sharesOutstanding;
        ipoPrice = price = high = low = _ipoPrice;
        name = _name;
        ticker = _ticker;
        marketCap = sharesOutstanding*ipoPrice;
        volume = 0;
    }
}
void Stock::updateHighLow(double newPrice) {
    if (newPrice > high) {
        high = newPrice;
        cout<<"New High:  "<<high<<endl;
    }
    else if (newPrice < low) {
        low = newPrice;
        cout<<"New Low:  "<<low<<endl;
    }
}
void Stock::updatePriceVolume(double newPrice, int sharesTraded) {
    mx.lock();
    if (newPrice > 0) {
        price = newPrice;
        cout<<"New Price:  "<<price<<endl;
    }
    if (sharesTraded>=0) {
        volume+=sharesTraded;
        cout<<"New Volume:  "<<volume<<endl;
    }
    updateHighLow(price);
    marketCap = price*sharesOutstanding;
    mx.unlock();
}



double Stock::getHigh() {
    return high;
}
double Stock::getLow() {
    return low;
}
double Stock::getmarketCap() {
    return marketCap;
}
int Stock::getVolume() {
    return volume;
}

bool Stock::operator==(const Stock &rhs) const {
    return this->ticker == rhs.ticker;
}

bool Stock::operator!=(const Stock &rhs) const {
    return !(rhs == *this);
}

string Stock::getTicker() const {
    return this->ticker;
}

string Stock::getName() {
    return this->name;
}

size_t hash<Stock>::operator()(const Stock &obj) const {
    return hash<string>()(obj.getTicker());
}


Stock::Stock(const Stock &stk) {
    this->sharesOutstanding = stk.sharesOutstanding;
    this->volume = stk.volume;
    this->ipoPrice = stk.ipoPrice;
    this->price = stk.price;
    this->marketCap = stk.marketCap;
    this->high = stk.high;
    this->low = stk.low;
    this->name = stk.name;
    this->ticker = stk.ticker;
}

//
// Created by Alamjeet Singh on 2019-06-05.
//

#include "Portfolio.h"

Portfolio::Portfolio() {
    cash = holdingsValue = PnL = 0;
}

Portfolio::Portfolio(unordered_map<Stock, pair<int, double>> stks, double cash) {
    this->stocks = stks;
    this->cash = cash;
    holdingsValue = cash;
    for (pair<Stock,pair<int,double>> s: stks) {
        holdingsValue += (s.second.first*s.second.second);
    }
    PnL = 0;
}

void Portfolio::updatePrices() {

}

double Portfolio::getCash() {
    return 0;
}

void Portfolio::addStock(Stock s, int numShares, double avgPrice) {

}

void Portfolio::removeStock(Stock s) {

}

void Portfolio::addShares(Stock s, int numShares, double avgPrice) {

}

void Portfolio::removeShares(Stock s, int numShares) {

}

double Portfolio::getHoldingsValue() {
    return 0;
}

double Portfolio::getProfitLoss() {
    return 0;
}

double Portfolio::getStockPrice(Stock s) {
    return 0;
}

int Portfolio::getStockShares(Stock s) {
    return 0;
}

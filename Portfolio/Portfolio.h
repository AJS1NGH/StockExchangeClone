//
// Created by Alamjeet Singh on 2019-06-05.
//

#ifndef STOCKEXCHANGE_PORTFOLIO_H
#define STOCKEXCHANGE_PORTFOLIO_H

#include <vector>
#include <unordered_map>
#include "../Stock/Stock.h"

using namespace std;

class Portfolio {
private:
    //stock and <number of shares,avg buy price>
    unordered_map<Stock,pair<int,double>> stocks;
    //weight of each stock, for portfolio optimization later
    //unordered_map<Stock, int> weights;//TODO
    double cash, holdingsValue, PnL;
    void updatePrices();
public:
    Portfolio();
    Portfolio(unordered_map<Stock,pair<int, double>> stks, double cash);
    double getCash();
    double getHoldingsValue();
    double getProfitLoss();
    double getStockPrice(Stock s);
    int getStockShares(Stock s);
    void addStock(Stock s, int numShares, double avgPrice);
    void removeStock(Stock s);
    void addShares(Stock s, int numShares, double avgPrice);
    void removeShares(Stock s, int numShares);
};


#endif //STOCKEXCHANGE_PORTFOLIO_H

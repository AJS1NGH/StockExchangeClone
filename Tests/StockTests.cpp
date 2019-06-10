//
// Created by Alamjeet Singh on 2019-06-05.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Stock/Stock.h"

Stock *s = new Stock();
Stock *s2 = new Stock(150,350.0,"berk","brkb");

TEST(testStock, tconstructor) {
    EXPECT_EQ(s->getVolume(),0);
    EXPECT_EQ(s->getHigh(),30.0);
    EXPECT_EQ(s->getLow(),30.0);
    EXPECT_EQ(s->getmarketCap(),30.0*1000000);
    
}

TEST(testStock, tconstructor2) {
    EXPECT_EQ(s2->getVolume(),0);
    EXPECT_EQ(s2->getHigh(),350.0);
    EXPECT_EQ(s2->getLow(),350.0);
    EXPECT_EQ(s2->getmarketCap(),350*150);

}


cmake_minimum_required(VERSION 3.13)
project(StockExchange)

set(CMAKE_CXX_STANDARD 17)

add_executable(StockExchange main.cpp OrderType/OrderType.cpp OrderType/OrderType.h OrderType/Market.cpp OrderType/Market.h OrderType/Limit.cpp OrderType/Limit.h Order/Buy.cpp Order/Buy.h Order/Sell.cpp Order/Sell.h OrderBook/OrderBook.cpp OrderBook/OrderBook.h Trader/Trader.cpp Trader/Trader.h BankAccount/BankAccount.cpp BankAccount/BankAccount.h Portfolio/Portfolio.cpp Portfolio/Portfolio.h TradingSystem/TradingSystem.cpp TradingSystem/TradingSystem.h Stock/Stock.cpp Stock/Stock.h Order/Order.cpp Order/Order.h Tests/StockTests.cpp Tests/BankAccountTests.cpp)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(StockExchange gtest gtest_main)
#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain{
    public:
        MerkelMain();
        /** Call this to start the sim*/
        void init();
        

    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void goToNextFrame();
        int getUserOption();
        void processUserOption(int UserOption);

        std::string currentTime;

        OrderBook orderBook{"20200317.csv"};

        Wallet wallet;
};
#pragma once
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook {
    public:
        /** construct, reading a csv data file */
        OrderBook(std::string filename);
        /** return vector of all know products in the dataset*/
        std::vector<std::string> getKnownProducts();
        /** return vector of Orders according to the sent filters*/
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                            std::string product,
                                            std::string timestamp);
        /** return the earliest time in the orderbook */
        std::string getEarliestTime();
        /** returns the next time after
         *  the sent time in the orderbook 
         * If there is no next timestamp, wraps around to start
         * */
        std::string getNextTime(std::string timestamp);

        void insertOrder(OrderBookEntry& order);
        
        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

        /** return the price of the highest bid in the sent set */
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /** return the price of the lowest bid in the sent set */
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

        

    private:
        std::vector<OrderBookEntry> orders;
};
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, float> csv;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void exc_input(std::string input);
        void exc(std::string date, float value);
};

#endif
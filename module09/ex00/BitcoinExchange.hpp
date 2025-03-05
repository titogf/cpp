#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdexcept>
#include <climits>

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
        float string_to_float(const std::string& str);
        int string_to_int(const std::string& str);
        bool is_valid_date(const std::string& date);
};

#endif
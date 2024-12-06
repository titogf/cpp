#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Error: Two arguments are expected in " << argv[0] << std::endl;
        return 0;
    }

    BitcoinExchange btc;
    btc.exc_input(argv[1]);
}
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::ifstream file("data.csv");
    if (!file.is_open()){
        std::cout << "Error: Could not open file" << std::endl;
        return ;
    }

    std::string line;

    if (std::getline(file, line)){
        while (std::getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos == std::string::npos) {
                throw std::runtime_error("Formato incorrecto en el archivo");
            }

            std::string date = line.substr(0, commaPos);
            std::string price = line.substr(commaPos + 1);

            try {
                float p = std::stof(price);
                csv[date] = p;
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Precio no válido: " + price);
            } catch (const std::out_of_range& e) {
                throw std::runtime_error("Precio fuera de rango: " + price);
            } 
        }
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : csv(other.csv) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        csv = other.csv;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

bool is_valid_date(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (!std::isdigit(year[0]) || !std::isdigit(year[1]) || !std::isdigit(year[2]) || !std::isdigit(year[3]) ||
        !std::isdigit(month[0]) || !std::isdigit(month[1]) ||
        !std::isdigit(day[0]) || !std::isdigit(day[1])) {
        return false;
    }

    int m = std::stoi(month);
    int d = std::stoi(day);

    if (m < 1 || m > 12 || d < 1 || d > 31) {
        return false;
    }

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false; // Abril, Junio, Septiembre, Noviembre
    if (m == 2 && d > 28) return false; // Febrero

    return true;
}

void BitcoinExchange::exc(std::string date, float value) {
    if (csv.find(date) != csv.end()) {
        float price = value * csv[date];
        std::cout << date << " => " << price << std::endl;
        return;
    }

    std::map<std::string, float>::const_iterator it = csv.lower_bound(date);

    // Si no existe la fecha exacta y no estamos en el principio del mapa, retrocede
    if (it != csv.begin()) {
        --it;
        float price = value * it->second;
        std::cout << it->first << " => " << price << std::endl;
        return;
    }

    // Si estás en el principio y no hay fechas válidas, imprime error
    std::cerr << "Error: No hay fechas disponibles más antiguas." << std::endl;
}



void BitcoinExchange::exc_input(std::string input) {
    std::ifstream file(input);
    if (!file.is_open()) {
        std::cout << "Error: Could not open input file" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    if (line != "date | value") {
        std::cout << "Error: Bad input file header" << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string value = line.substr(sep + 3);

        if (!is_valid_date(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        try {
            float val = std::stof(value);

            if (val < 0) {
                std::cout << "Error: not a positive number." << std::endl;
            } else if (val > 1000) {
                std::cout << "Error: too large a number." << std::endl;
            } else {
                exc(date, std::stof(value));
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Error: bad input => " << value << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Error: too large a number." << std::endl;
        }
    }

    file.close();
}

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file" << std::endl;
        return;
    }

    std::string line;

    if (std::getline(file, line)) {
        while (std::getline(file, line)) {
            size_t commaPos = line.find(',');
            if (commaPos == std::string::npos) {
                throw std::runtime_error("Incorrect format file");
            }

            std::string date = line.substr(0, commaPos);
            std::string price = line.substr(commaPos + 1);

            float p = string_to_float(price);
            if (p < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            else
                csv[date] = p;

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

bool BitcoinExchange::is_valid_date(const std::string& date) {
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

    int m = string_to_int(month.c_str());
    int d = string_to_int(day.c_str());

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
        std::cout << date << " => " << value << " = " << price << std::endl;
        return;
    }

    std::map<std::string, float>::const_iterator it = csv.lower_bound(date);

    // Si no existe la fecha exacta y no estamos en el principio del mapa, retrocede
    if (it != csv.begin()) {
        --it;
        float price = value * it->second;
        std::cout << date << " => " << value << " = " << price << std::endl;
        return;
    }

    // Si estás en el principio y no hay fechas válidas, imprime error
    std::cerr << "Error: No older dates available." << std::endl;
}



void BitcoinExchange::exc_input(std::string input) {
    std::ifstream file(input.c_str());
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

        float val = string_to_float(value);
        if (val < 0) {
            std::cout << "Error: not a positive number." << std::endl;
        } else if (val > 1000) {
            std::cout << "Error: too large a number." << std::endl;
        } else {
            exc(date, val);
        }
    }

    file.close();
}

float BitcoinExchange::string_to_float(const std::string& str) {
    float result = 0.0f;
    float decimal = 0.1f;
    bool has_decimal = false;
    size_t i = 0;

    while (i < str.length() && std::isspace(str[i])) {
        i++;
    }

    if (i < str.length() && str[i] == '-') {
        return -1.0f;
    }

    for (; i < str.length(); i++) {
        if (str[i] == '.') {
            has_decimal = true;
            i++;
            break;
        }
        if (!std::isdigit(str[i])) {
            return -1.0f;
        }
        result = result * 10 + (str[i] - '0');
    }

    if (has_decimal) {
        for (; i < str.length(); i++) {
            if (!std::isdigit(str[i])) {
                return -1.0f;
            }
            result += (str[i] - '0') * decimal;
            decimal *= 0.1f;
        }
    }

    return result;
}

int BitcoinExchange::string_to_int(const std::string& str) {
    int result = 0;
    size_t i = 0;

    while (i < str.length() && std::isspace(str[i]))
        i++;

    if (i < str.length() && str[i] == '-')
        return -1;


    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return -1; 

        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return -1;
        }

        result = result * 10 + (str[i] - '0');
    }
    return result;
}
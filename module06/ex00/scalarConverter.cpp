#include "scalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) { *this = src; }
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) { (void) src; return *this; }
ScalarConverter::~ScalarConverter() {}

void tochar(long double value, int check){
    std::cout << "char: ";
    if (check > 1 || value < 0 || value > 127)
        std::cout << "impossible";
    else if (value == 127 || (value >= 0 && value <= 31))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";

    std::cout << std::endl;
}
void toint(long double value, int check){
    std::cout << "int: ";
    if (check > 1 || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);

    std::cout << std::endl;
}
void tofloat(long double value, int check){
    std::cout << "float: ";

    if (value < FLT_MAX * -1 || value > FLT_MAX)
        std::cout << "impossible";
    else if(check == 2)
		std::cout << "nanf";
	else if (check == 3)
		std::cout << "+inff";
	else if (check == 4)
		std::cout << "-inff";
    else{
        std::cout << static_cast<float>(value);
        if (check == 1 && value < 1000000)
            std::cout << ".0";
        std::cout << "f";
    }

    std::cout << std::endl;
}
void todouble(long double value, int check){
    std::cout << "double: ";
    if (value > DBL_MAX || value < DBL_MAX * -1)
        std::cout << "impossible";
    if(check == 2)
		std::cout << "nan";
	else if (check == 3)
		std::cout << "+inf";
	else if (check == 4)
		std::cout << "-inf";
    else {
        std::cout << static_cast<double>(value);
        if (check == 1 && value < 1000000)
            std::cout << ".0";
    }

    std::cout << std::endl;
}

static int checkSymbol(std::string value)
{
	if (value.compare("nan") == 0 || value.compare("nanf") == 0)
		return (2);
	else if (value.compare("+inf") == 0)
		return (3);
	else if (value.compare("-inf") == 0)
		return (4);
	return (0);
}

bool decimal(std::string value){
    size_t pos;
    std::string s;

    pos = value.find(".");
    if (pos == std::string::npos)
        return false;
    else{
        while (value[++pos]){
            if (value[pos] != '0' && value[pos] != 'f')
                return true;
        }
    }
    return false;
}

void ScalarConverter::convert(std::string value){
    int check = checkSymbol(value);
    std::stringstream new_v;
    long double num = 0;

    if (value == "-nan" || value == "-nanf"){
        std::cout << "Bad input" << std::endl;
        return ;
    }
    if (!check){
        if (!decimal(value))
            check = 1;
        if (value[value.size() - 1] == 'f')
            value = value.substr(0, value.size() - 1);
        
        new_v << value;
        new_v >> num;
        if (new_v.fail()) {
            std::cout << "Bad input" << std::endl;
            return;
        }
        if (!new_v.eof()){
            std::cout << "Bad input" << std::endl;
            return ;
        }
    }

    tochar(num, check);
    toint(num, check);
    tofloat(num, check);
    todouble(num, check);
}
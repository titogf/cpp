#include "RPN.hpp"

RPN::RPN() : stck() {}

RPN::RPN(std::string notation){
    for (size_t i = 0; i < notation.size(); i++){
        if (notation[i] == ' ')
            continue;
        if (std::isdigit(notation[i])){
            int nb = notation[i];
            stck.push(nb - 48);
        }
        else if (stck.size() < 2){
            std::cout << RED << "Error: extra simbol" << NOC << std::endl;
            return ;
        }
        else {
            int b = stck.top(); stck.pop();
            int a = stck.top(); stck.pop();

            if (notation[i] == '+') stck.push(a + b);
            else if (notation[i] == '-') stck.push(a - b);
            else if (notation[i] == '*') stck.push(a * b);
            else if (notation[i] == '/') {
                if (b == 0){
                    std::cout << RED << "Error: division by zero" << NOC << std::endl;
                    return ;
                }
                stck.push(a / b);
            }
        }
    }
    if (stck.size() != 1){
        std::cout << RED << "Error: extra numbers" << NOC << std::endl;
        return ;
    }
    std::cout << stck.top() << std::endl;
    return ;
}

RPN::RPN(const RPN& other) : stck(other.stck) {}
RPN& RPN::operator=(const RPN& other){
    if (this != &other)
        stck = other.stck;
    return *this;
}
RPN::~RPN() {}
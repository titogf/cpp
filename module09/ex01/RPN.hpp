#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>

#define NOC	"\033[0m"
#define GREEN "\033[1;32m"
#define RED	"\033[1;31m"

class RPN{
    private:
        std::stack<int> stck;
    public:
        RPN();
        RPN(std::string notation);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
};

#endif
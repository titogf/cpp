#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::complain(std::string level)
{
    void (Harl::*fun[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level){
            (this->*fun[i])();
            return ;
        }
        if (i == 3)
            std::cout << "Level [" << level << "] not found" << std::endl;
    }
}

void    Harl::debug(void)
{
    std::cout <<"[DEBUG]" <<" This is a debug message" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[INFO]" << " This is a info message" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[WARNING]" << " This is a warning message" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ERROR]" << " This is a error message" << std::endl;
}
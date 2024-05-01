#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::complain(std::string level)
{
    void (Harl::*fun[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            switch (i)
            {
                case 0:
                    (this->*fun[0])();
                    (this->*fun[1])();
                    (this->*fun[2])();
                    (this->*fun[3])();
                    break;
                case 1:
                    (this->*fun[1])();
                    (this->*fun[2])();
                    (this->*fun[3])();
                    break;
                case 2:
                    (this->*fun[2])();
                    (this->*fun[3])();
                    break;
                case 3:
                    (this->*fun[3])();
                    break;
                default:
                    break;
            }
            return;
        }
    }
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
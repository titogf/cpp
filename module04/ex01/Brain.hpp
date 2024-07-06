#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain{
    private:
        std::string _ideas;
    public:
        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& original);
        ~Brain();

        std::string getIdeas() const;
};

#endif
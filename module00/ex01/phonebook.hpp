#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "contact.hpp"

class PhoneBook{
    private :
        Contact _contact[8];
        int     _nb;
        int     _current_index;
    public :
        PhoneBook();
        void    set_contact();
        void    add_new_contact(std::string first_name, std::string last_name, std::string nickname, 
                std::string phone_number, std::string darkest_secret);
        void    search_contact(int index);
        void    display_contacts();
        std::string dot(std::string s);
};

#endif
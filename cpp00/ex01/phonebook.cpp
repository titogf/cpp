#include "phonebook.hpp"

PhoneBook::PhoneBook(){
    this->_contact = new Contact[8];
    this->_nb = 0;
    this->_current_index = 0;
}

void    PhoneBook::add_new_contact(std::string first_name, std::string last_name, std::string nickname, 
                std::string phone_number, std::string darkest_secret){

    if (_current_index == 8)
        _current_index = 0;
    _contact[_current_index].set_index(_current_index);
    _contact[_current_index].set_first_name(first_name);
    _contact[_current_index].set_last_name(last_name);
    _contact[_current_index].set_nickname(nickname);
    _contact[_current_index].set_phone_number(phone_number);
    _contact[_current_index].set_darkest_secret(darkest_secret);
    if (_nb < 8)
        _nb++;
    _current_index++;
    std::cout << "\nSaved contact!\n" << std::endl;
}

void    PhoneBook::set_contact(){
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    std::cout << "first name: "; std::getline(std::cin, first_name);
    std::cout << "last name: "; std::getline(std::cin, last_name);
    std::cout << "nickname: "; std::getline(std::cin, nickname);
    std::cout << "phone number: "; std::getline(std::cin, phone_number);
    std::cout << "darkest secret: "; std::getline(std::cin, darkest_secret);
    add_new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void    PhoneBook::display_contacts(){
    std::cout << std::endl;
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << "|" << std::endl;

    for (int i = 0; i < _nb; i++){
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << dot(_contact[i].get_first_name()) << "|";
        std::cout << std::setw(10) << dot(_contact[i].get_last_name()) << "|";
        std::cout << std::setw(10) << dot(_contact[i].get_nickname()) << "|" << std::endl;
    }
}

std::string PhoneBook::dot(std::string s){
    if (s.length() > 10){
        s.resize(9);
        s.append(".");
    }
    return s;
}

void    PhoneBook::search_contact(int index){
    std::cout << "\nfirst name: " << _contact[index].get_first_name() << std::endl;
    std::cout << "last name: " << _contact[index].get_last_name() << std::endl;
    std::cout << "nickname: " << _contact[index].get_nickname() << std::endl;
    std::cout << "phone number: " << _contact[index].get_phone_number() << std::endl;
    std::cout << "darkest secret: " << _contact[index].get_darkest_secret() << "\n" << std::endl;
}
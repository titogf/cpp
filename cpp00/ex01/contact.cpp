#include "contact.hpp"

Contact::Contact(){
    this->_index = -1;
    this->_first_name = "Uknown";
    this->_last_name = "Uknown";
    this->_nickname = "Uknown";
    this->_phone_number = "Uknown";
    this->_darkest_secret = "Uknown";
}

int Contact::get_index(){
    return (this->_index);
}

std::string Contact::get_first_name(){
    return (this->_first_name);
}

std::string Contact::get_last_name(){
    return (this->_last_name);
}

std::string Contact::get_nickname(){
    return (this->_nickname);
}

std::string Contact::get_phone_number(){
    return (this->_phone_number);
}

std::string Contact::get_darkest_secret(){
    return (this->_darkest_secret);
}

void    Contact::set_index(int index){
    this->_index = index;
}

void    Contact::set_first_name(std::string first_name){
    this->_first_name = first_name;
}

void    Contact::set_last_name(std::string last_name){
    this->_last_name = last_name;
}

void    Contact::set_nickname(std::string nickname){
    this->_nickname = nickname;
}

void    Contact::set_phone_number(std::string phone_number){
    this->_phone_number = phone_number;
}

void    Contact::set_darkest_secret(std::string darkest_secret){
    this->_darkest_secret = darkest_secret;
}
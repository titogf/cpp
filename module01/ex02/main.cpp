#include <iostream>

int main(void){
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
  
    std::cout << "\n----- PRINT ADDRESS -----" << std::endl;
    std::cout << "STR: " << &string << std::endl;
    std::cout << "PTR: " << stringPTR << std::endl;
    std::cout << "REF: " << &stringREF << std::endl;
    std::cout << "------------------------\n" << std::endl;

    std::cout << "\n----- PRINT VALUES -----" << std::endl;
    std::cout << "STR: " << string << std::endl;
    std::cout << "PTR: " << *stringPTR << std::endl;
    std::cout << "REF: " << stringREF << std::endl;
    std::cout << "------------------------\n" << std::endl;


    return (0);
}
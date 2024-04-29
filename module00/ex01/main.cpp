#include "phonebook.hpp"

void    header()
{
    std::cout << "-------------  WELCOME TO YOUR PHONEBOOK  -------------\n" << std::endl;
    std::cout << "       --   Type 'ADD' to save a new contact   --" << std::endl;
    std::cout << "      --   Type 'EXIT' to quit the phonebook    --" << std::endl;
    std::cout << "  --   Type 'SEARCH' to display a specific contact   --\n" << std::endl;
}

int     check_input(std::string input){
    if (input == "")
        return (0); 
    for(int i = 0 ; input[i] ; i++)
        if (std::isdigit(input[i]) == 0) return (0);
    if (std::stoi(input) > 7)
        return (0);
    return (1);
}

int main()
{
    PhoneBook *phonebook = new PhoneBook();
    std::string input;

    header();
    while (1)
    {
        std::cout << "PhoneBook > ";
        std::getline(std::cin, input);
        if (!input.compare("EXIT")){
            delete phonebook;
            break;
        }
        else if (!input.compare("ADD"))
            phonebook->set_contact();
        else if (!input.compare("SEARCH")){
            phonebook->display_contacts();
            std::cout << "\nEnter a index for display the contact information\n" << std::endl;
            do{
                std::cout << "Index: ";
                std::getline(std::cin, input);
                if (!check_input(input))
                    std::cout << "Enter a valid number" << std::endl;
            }while (!check_input(input));
            phonebook->search_contact(std::stoi(input));
        }
        else
            std::cout << "\nEnter a valid command ('ADD' 'SEARCH' 'EXIT')\n" << std::endl;
    }
    return 0;
}
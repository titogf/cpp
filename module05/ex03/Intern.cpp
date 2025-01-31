#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& copy){*this = copy;}

Intern& Intern::operator=(const Intern& original){
    (void) original;
    return (*this);
}

Intern::~Intern(){std::cout << "Intern delete"<< std::endl;}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string array[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    createFormFunction form[3] = {&Intern::createRobotomyRequest, &Intern::createShrubberyCreation, &Intern::createPresidentialPardon};

    for (int i = 0; i < 3; i++){
        if (formName == array[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*form[i])(target);
        }
    }
    std::cout << "No matching form to create." << std::endl;
    return NULL;
}

AForm* Intern::createPresidentialPardon(std::string const &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequest(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreation(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

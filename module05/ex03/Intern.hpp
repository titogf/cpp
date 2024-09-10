#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    private:
        const std::string _formName;
        const std::string _target;
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& original);
        ~Intern();

        AForm* makeForm(std::string formName, std::string target);

        AForm* createShrubberyCreation(std::string const &target);
        AForm* createRobotomyRequest(std::string const &target);
        AForm* createPresidentialPardon(std::string const &target);
};

typedef AForm* (Intern::*createFormFunction)(std::string const & target);

#endif
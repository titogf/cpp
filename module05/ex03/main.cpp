#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try {
		Bureaucrat a("Gon", 16);

		std::cout << "----" << std::endl;
		Intern intern;
		AForm* iform = intern.makeForm("robotomy request", "R");

		std::cout << "--------------------" << std::endl;

		if (iform != NULL){
			iform->beSigned(a);
			try {
				a.executeForm(*iform);
			} catch (const std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}

		std::cout << "----" << std::endl;
		delete iform;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    return (0);
}
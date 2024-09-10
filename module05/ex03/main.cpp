#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat a("Gon", 16);

	std::cout << "----" << std::endl;
	Intern intern;
	AForm* iform = intern.makeForm("robotomy request", "s");

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

    return (0);
}
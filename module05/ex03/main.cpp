#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat a("Gon", 46);
	Bureaucrat b("Pedro", 1);

	std::cout << "----" << std::endl;
	ShrubberyCreationForm	s("Shrubbery");
	RobotomyRequestForm		r("Robotomy");
	PresidentialPardonForm	p("Presidential");

	std::cout << "---------OK-----------" << std::endl;
	s.beSigned(a);
	try {
		a.executeForm(s);
	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}

	std::cout << "---------KO-----------" << std::endl;
	r.beSigned(b);
	try {
		b.executeForm(r);
	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}
	try {
		a.executeForm(r);
	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}

	

	
	std::cout << "----" << std::endl;

    return (0);
}
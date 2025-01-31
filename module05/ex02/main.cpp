#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try {
		Bureaucrat a("Gon", 34);
		Bureaucrat b("Pedro", 150);

		std::cout << "----" << std::endl;
		ShrubberyCreationForm	s("Shrubbery");
		RobotomyRequestForm		r("Robotomy");
		PresidentialPardonForm	p("Presidential");

		std::cout << "---------OK-----------" << std::endl;
		s.beSigned(a);
		a.executeForm(s);


		std::cout << "---------KO-----------" << std::endl;
		r.beSigned(a);
		b.executeForm(r);
		a.executeForm(r);
	} catch (const std::exception &e) {
    	std::cout << e.what() << std::endl;
	}
	
	std::cout << "----" << std::endl;

    return (0);
}
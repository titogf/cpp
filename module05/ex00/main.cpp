#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("High", 0);
	Bureaucrat b("Low", 160);

	std::cout << "----" << std::endl;
	Bureaucrat Jesus("Jesus", 100);
	std::cout << Jesus << std::endl;
	Jesus.incrementGrade(90);
	std::cout << Jesus << std::endl;
	Jesus.decrementGrade(90);
	std::cout << Jesus << std::endl;


	std::cout << "----" << std::endl;
	Jesus.incrementGrade(150);
	std::cout << Jesus << std::endl;
	Jesus.decrementGrade(150);
	std::cout << Jesus << std::endl;

	std::cout << "----" << std::endl;

    return (0);
}
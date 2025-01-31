#include "Bureaucrat.hpp"

int main()
{
	try {
    	Bureaucrat a("High", 0);
		Bureaucrat b("Low", 160);

		std::cout << "----" << std::endl;
		Bureaucrat Jesus("Jesus", 150);
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
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    return (0);
}
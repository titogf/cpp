#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat a("Gon", 34);
		Bureaucrat b("Pedro", 150);

		std::cout << "----" << std::endl;
		std::cout << a << std::endl;
		a.incrementGrade(10);
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << "----" << std::endl;
		Form f("hoja", 80, 80);
		b.signForm(f);
		a.signForm(f);

		std::cout << "----" << std::endl;
		Form e("Exam", 150, 150);
		e.beSigned(b);


		std::cout << "----" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

    return (0);
}
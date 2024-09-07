#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("Gon", 34);
	Bureaucrat b("Pedro", 100);

	std::cout << "----" << std::endl;
	std::cout << a << std::endl;
	a.incrementGrade(10);
	std::cout << a << std::endl;
	b.decrementGrade(100);
	std::cout << b << std::endl;

	std::cout << "----" << std::endl;
	Form f("hoja", 80, 80);
	b.decrementGrade(1);
	b.signForm(f);
	a.signForm(f);

	std::cout << "----" << std::endl;
	Form e("Exam", 80, 80);
	e.beSigned(a);


	std::cout << "----" << std::endl;

    return (0);
}
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
	    const int _gradeToSign;
	    const int _gradeToExecute;
        Form();

    public:
        Form(std::string, int, int);
        Form(const Form& copy);
        Form& operator=(const Form& original);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void setSigned(bool b);

        void beSigned(Bureaucrat & b);

    class GradeTooHighException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("-Form- grade is too high (smaller than 1).");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("-Form- grade is too low (bigger than 150).");
		}
	};  
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif
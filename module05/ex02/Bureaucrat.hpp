#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
        Bureaucrat();

    public:
        Bureaucrat(std::string, int);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& original);
        ~Bureaucrat();

        void incrementGrade(int);
        void decrementGrade(int);

        std::string getName() const;
        int getGrade() const;
        void setGrade(int);

        void signForm(AForm& form);

    class GradeTooHighException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("Grade is too high (smaller than 1).");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("Grade is too low (bigger than 150).");
		}
	};  
};
std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif
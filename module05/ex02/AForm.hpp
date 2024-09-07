#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
	    const int _gradeToSign;
	    const int _gradeToExecute;
        AForm();

    public:
        AForm(std::string, int, int);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& original);
        ~AForm();

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
			return ("-AForm- grade is too high (smaller than 1).");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char * what () const throw ()
		{
			return ("-AForm- grade is too low (bigger than 150).");
		}
	};  
};

std::ostream& operator<<(std::ostream& o, const AForm& AForm);

#endif
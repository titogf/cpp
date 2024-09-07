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
		virtual void execute(Bureaucrat const & executor) const = 0;


    class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what () const throw ()
		{
			return ("-AForm- grade is too high (smaller than 1).");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what () const throw ()
		{
			return ("-AForm- grade is too low (bigger than 150).");
		}
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char * what () const throw ()
			{
				return ("Form not signed.");
			}
	};

	class LowGradeForExecute : public std::exception
	{
	public:
		virtual const char * what () const throw ()
		{
			return ("Grade of bureaucrat is lower than form execute grade.");
		}
	};
	class LowGradeForSign : public std::exception
	{
	public:
		virtual const char * what () const throw ()
		{
			return ("Grade of bureaucrat is lower than form sign grade.");
		}
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& AForm);

#endif
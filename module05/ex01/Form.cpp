#include "Form.hpp"

Form::Form() : _name("null"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToSign > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form created: " << _name << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    *this = copy;
    std::cout << "Form, copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& original)
{
    if (this != &original)
    {
        this->_signed = original._signed;
    }
    return *this;
}

Form::~Form(){}

std::string Form::getName() const {return (_name);}
bool Form::getSigned() const{return (_signed);}
int Form::getGradeToSign() const {return (_gradeToSign);}
int Form::getGradeToExecute() const {return (_gradeToExecute);}
void Form::setSigned(bool b){
    this->_signed = b;
    return ;
}

void Form::beSigned(Bureaucrat& b){
    if (b.getGrade() <= _gradeToSign){
        _signed = true;
        std::cout << "Form: " << this->_name << " is signed by " << b.getName() << std::endl;
    }
    else
        std::cout << b.getName() << " couldn´t sign " << this->_name << " because grade of bureaucrat is too low"  << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Form &form) {
	if (form.getSigned())
		o << "Form <" << form.getName() << "> is signed.";
	else
		o << "Form <" << form.getName() << "> is not signed.";
	return o;
}
#include "AForm.hpp"

AForm::AForm() : _name("null"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    try{
        if (gradeToExecute < 1 || gradeToSign < 1)
            throw AForm::GradeTooHighException();
        else if (gradeToSign > 150 || gradeToSign > 150)
            throw AForm::GradeTooLowException();
    }
    catch (const GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "AForm created: " << _name << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    *this = copy;
    std::cout << "AForm, copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& original)
{
    if (this != &original)
    {
        this->_signed = original._signed;
    }
    return *this;
}

AForm::~AForm(){}

std::string AForm::getName() const {return (_name);}
bool AForm::getSigned() const{return (_signed);}
int AForm::getGradeToSign() const {return (_gradeToSign);}
int AForm::getGradeToExecute() const {return (_gradeToExecute);}
void AForm::setSigned(bool b){
    this->_signed = b;
    return ;
}

void AForm::beSigned(Bureaucrat& b){
    if (b.getGrade() <= _gradeToSign){
        _signed = true;
        std::cout << "Form: " << this->_name << " is signed by " << b.getName() << std::endl;
    }
    else
        std::cout << b.getName() << " couldn´t sign " << this->_name << " because grade of bureaucrat is too low"  << std::endl;
}

std::ostream &operator<<(std::ostream &o, const AForm &AForm) {
	if (AForm.getSigned())
		o << "AForm <" << AForm.getName() << "> is signed.";
	else
		o << "AForm <" << AForm.getName() << "> is not signed.";
	return o;
}
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat created: " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade())
{
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
    if (this != &original)
        _grade = original.getGrade();
    std::cout << "Assignation constructor called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::setGrade(int grade){
    _grade = grade;
}

void Bureaucrat::incrementGrade(int amount){
	if (this->getGrade() - amount < 1)
		throw Bureaucrat::GradeTooHighException();
    this->setGrade(getGrade() - amount);
}

void Bureaucrat::decrementGrade(int amount){
	if (this->getGrade() + amount > 150)
		throw Bureaucrat::GradeTooLowException();
    this->setGrade(getGrade() + amount);
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & i){
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}

void Bureaucrat::signForm(AForm& form){
    if (form.getGradeToSign() >= this->_grade){
        form.setSigned(true);
		std::cout<< "<" << this->getName() << "> signs <" << form.getName() << ">" << std::endl;
    }
    else
        std::cout << "<" << this->_name << "> can´t firm <" << form.getName() << "> because the bureaucrat's grade is lower than the form's grade to sign" << std::endl;
}

void Bureaucrat::executeForm(const AForm& form){
    try
	{
		form.execute(*this);
		std::cout << this->_name << " executes form " << form.getName() << std::endl;
	}
	catch (AForm::LowGradeForExecute &e)
	{
		std::cout << e.what() << std::endl;
	}
}
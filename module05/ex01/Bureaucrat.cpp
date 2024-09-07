#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    try{
        if (_grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (_grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }
    catch (const GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    catch (const GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
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
    try {
		if (this->getGrade() - amount < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
		return;
	}
    this->setGrade(getGrade() - amount);
}

void Bureaucrat::decrementGrade(int amount){
	try {
		if (this->getGrade() + amount > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
		return;
	}
    this->setGrade(getGrade() + amount);
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & i){
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}

void Bureaucrat::signForm(Form& form){
    if (form.getGradeToSign() >= this->_grade){
        form.setSigned(true);
		std::cout<< "<" << this->getName() << "> signs <" << form.getName() << ">" << std::endl;
    }
    else
        std::cout << "<" << this->_name << "> can´t firm <" << form.getName() << "> because the bureaucrat's grade is lower than the form's grade to sign" << std::endl;
}
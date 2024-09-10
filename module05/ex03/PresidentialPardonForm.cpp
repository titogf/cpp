#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &original) {
    if (this != &original){
        AForm::operator=(original);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(const Bureaucrat& executor)const {
    if (!this->getSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw LowGradeForExecute();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
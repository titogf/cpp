#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &original) {
    if (this != &original){
        AForm::operator=(original);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw LowGradeForExecute();
    }

    std::cout << "* Drilling noises *" << std::endl;
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << _target << " has failed." << std::endl;
    }
}

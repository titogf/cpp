#ifndef     ROBOTOMYREQUESTFORM_HPP
# define    ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &original);
        virtual ~RobotomyRequestForm();

        void execute(const Bureaucrat& execute) const;
};

#endif
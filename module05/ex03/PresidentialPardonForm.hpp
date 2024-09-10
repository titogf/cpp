#ifndef   PRESIDENTIALPARDONFORM_HPP
#define   PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &original);
        virtual ~PresidentialPardonForm();

        void execute(const Bureaucrat& execute) const;
};

#endif
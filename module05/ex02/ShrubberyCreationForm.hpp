#ifndef     SHRUBBERYCREATIONFORM_HPP
# define    SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &original);
        virtual ~ShrubberyCreationForm();

        void execute(const Bureaucrat& execute) const;
};

#endif
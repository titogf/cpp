#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
    if (this != &original) {
        AForm::operator=(original);
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
    if (!this->getSigned())
        throw FormNotSignedException();
    if (this->getGradeToExecute() < executor.getGrade())
        throw LowGradeForExecute();

    std::string const name_tarjet = _target + "_shrubbery";
	std::ofstream file(name_tarjet.c_str());

    if (file.is_open()) {
        file << "      ccee88oo\n"
             << "  C8O8O8Q8PoOb o8oo\n"
             << " dOB69QO8PdUOpugoO9bD\n"
             << "CgggbU8OU qOp qOdoUOdcb\n"
             << "   6OuU  /p u gcoUodpP\n"
             << "      \\\\//  /douUP\n"
             << "        \\\\////\n"
             << "         |||/\\\n"
             << "         |||\\/ \n"
             << "         |||||   \n"
             << "   .....//||||\\....\n";
        file.close();
    } else {
        std::cerr << "Error creating file" << std::endl;
    }
}
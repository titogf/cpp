#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {}

Cure::Cure(std::string const & type) : AMateria(type) {}

Cure::Cure(const Cure& original) : AMateria(original) {}

Cure& Cure::operator=(const Cure& original) {
    if (this != &original) {
        AMateria::operator=(original);
    }
    return *this;
}

Cure::~Cure() {}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}
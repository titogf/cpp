#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria*   inventory[4];

    public :
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource& operator=(const MateriaSource& original);
        ~MateriaSource();

        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const& type);
};

#endif
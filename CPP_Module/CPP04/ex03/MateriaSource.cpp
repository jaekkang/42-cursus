#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    new (this)(MateriaSource)(obj);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj) {
    new (this)(MateriaSource)(obj);
    return (*this);
}

MateriaSource::~MateriaSource() {}

void MateriaSource::learnMateria(AMateria *obj) { 
    
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    if (type == "Ice") {
        AMateria *ret = new Ice();
        return (ret);
    } else if (type == "Cure") {
        AMateria *ret = new Cure();
        return (ret);
    }
    return (0);
}
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _type("Default type") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "MateriaSource default constructor called." << std::endl;
};
MateriaSource::MateriaSource(std::string const & type) : _type(type) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "MateriaSource parameterized constructor called." << std::endl;
};
MateriaSource::MateriaSource(const MateriaSource& other) : _type(other._type) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called." << std::endl;
};
MateriaSource &MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        _type = other._type;
        for (int i = 0; i < 4; i++) { // liberar memoria
            if (_inventory[i])
                delete _inventory[i];
        }
        // copiar nuevas materias
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    std::cout << "MateriaSource assigment operator called." << std::endl;
    return *this;
};
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    std::cout << "MateriaSource destructor called." << std::endl;
};

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) return;

    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) { // encontrar primer slot vacio
            _inventory[i] = materia->clone(); // copiar la materia como template
            return;
        }
    }
};
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] && _inventory[i]->getType() == type) {
            return (_inventory[i]->clone()); // crear nueva materia
        }
    }
    return NULL;
};
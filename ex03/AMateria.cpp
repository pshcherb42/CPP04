#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown") {
    std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria parameterized constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
    std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        // NO copiar _type según el subject
    }
    std::cout << "AMateria assignment operator called." << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called." << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}
#include "Cure.hpp"

Cure::Cure() {
    _type = "cure";
    std::cout << "Cure default constructor called." << std::endl;
}

AMateria* Cure::clone() const {
    AMateria* clone = new Cure;
    return (clone);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "´s wounds *" << std::endl;
}
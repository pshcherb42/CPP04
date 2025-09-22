#include "Ice.hpp"

Ice::Ice() {
    _type = "ice";
    std::cout << "Ice default constructor called." << std::endl;
}

AMateria* Ice::clone() const {
    AMateria* clone = new Ice;
    return (clone);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << name << " *" << std::endl;
};
#include "Ice.hpp"

Ice::Ice() {
    _type = "ice";
    std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type) {
    std::cout << "Ice parameterized constructor called." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    std::cout << "Ice assignment operator called." << std::endl;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const {
    AMateria* clone = new Ice;
    return (clone);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
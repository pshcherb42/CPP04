#include "Cure.hpp"

Cure::Cure() {
    _type = "cure";
    std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type) {
    std::cout << "Cure parameterized constructor called." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "Cure copy constructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    std::cout << "Cure assignment operator called." << std::endl;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const {
    AMateria* clone = new Cure;
    return (clone);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
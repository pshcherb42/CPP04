#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
};

Cat::Cat(std::string _type) {
    type = _type;
    std::cout << "Cat parameterized constructor called." << std::endl;
};

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
};

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat assignment operator called." << std::endl;
    return *this;
};

void Cat::makeSound() {
    std::cout << "Meow!" << std::endl;
};

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}
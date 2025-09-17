#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
};

Dog::Dog(std::string _type) {
    type = _type;
    std::cout << "Dog parameterized constructor called." << std::endl;
};

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog assignment operator called." << std::endl;
};

void Dog::makeSound() {
    std::cout << "Wuf!" << std::endl;
};

Dog::~Dog() {
    std::cout << "Dog destructor called." << std::endl;
}
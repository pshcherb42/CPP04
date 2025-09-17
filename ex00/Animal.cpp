#include "Animal.hpp"

Animal::Animal() {
    type = "Animal";
    std::cout << "Animal default constructor called." << std::endl;
};

Animal::Animal(std::string _type) {
    type = _type;
    std::cout << "Animal parameterized constructor called." << std::endl;
};

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Animal assignment operator called." << std::endl;
};

void Animal::makeSound() {
    std::cout << "Default animal sound!" << std::endl;
};

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}
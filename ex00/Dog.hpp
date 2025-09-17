#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(std::string _type);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);

        void makeSound();

        ~Dog();
};

#endif
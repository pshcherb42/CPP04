#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* Archi;
    public:
        Dog();
        Dog(std::string _type);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);

        virtual void makeSound() const;
        void show_data();

        ~Dog();
};

#endif
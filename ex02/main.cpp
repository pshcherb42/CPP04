#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    int N = 4;
    //Animal s; error: cannot create object of abstract class
    Animal* arr[N];

    // create cats
    for (int i = 0; i < N/2; i++) {
        arr[i] = new Cat();
        arr[i]->show_data();
    }

    // create dogs
    for (int i = N/2; i < N; i++) {
        arr[i] = new Dog();
        arr[i]->show_data();
    }

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* h = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << h->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound(); // will output dog sound!
    h->makeSound();

    delete j;
    delete i;
    delete h;

    for (int i = 0; i < N; i++) {
        delete arr[i];
    }

    return 0;
}
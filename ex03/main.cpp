#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
    // Create a MateriaSource and learn Materias
    std::cout << "Creating MateriaSource and learning Materias..." << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create a Character and equip Materias
    std::cout << "\nCreating Character 'me' and equipping Materias..." << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    std::cout << "Equipping Ice Materia to 'me'." << std::endl;
    me->equip(tmp);

    tmp = src->createMateria("cure");
    std::cout << "Equipping Cure Materia to 'me'." << std::endl;
    me->equip(tmp);

    // Create another Character and use Materias
    std::cout << "\nCreating Character 'bob' and using Materias on him..." << std::endl;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob); // Use Ice on bob
    me->use(1, *bob); // Use Cure on bob

    // Use or unequip nonexistent items
    std::cout << "\nAttempting to use and unequip nonexistent items..." << std::endl;
    me->use(2, *bob); // Should do nothing
    me->unequip(2);   // Should do nothing

    // Test unequip functionality
    std::cout << "\nUnequipping Materias from 'me'..." << std::endl;
    me->unequip(0); // Ice goes to the floor
    std::cout << "Unequipped Ice Materia. It is now on the floor." << std::endl;
    me->unequip(1); // Cure goes to the floor
    std::cout << "Unequipped Cure Materia. It is now on the floor." << std::endl;

    // Test inventory limits
    std::cout << "\nTesting inventory limits for 'me'..." << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    std::cout << "Attempting to equip another Ice Materia (should not be added)..." << std::endl;
    me->equip(src->createMateria("ice")); // Should not be added

    std::cout << "\nFloor contains " << Character::getFloorSize() << " Materias." << std::endl;

    // Test deep copy of Character
    std::cout << "\nTesting deep copy of Character 'me'..." << std::endl;
    Character* clone = new Character(*(dynamic_cast<Character*>(me)));
    clone->use(0, *bob); // Should not crash even though me unequipped Materias
    clone->use(1, *bob);

    // Test assignment operator
    std::cout << "\nTesting assignment operator for Character..." << std::endl;
    Character assigned("assigned");
    assigned = *(dynamic_cast<Character*>(me));
    assigned.use(0, *bob);
    assigned.use(1, *bob);

    // Clean up
    std::cout << "\nCleaning up dynamically allocated objects..." << std::endl;
    delete bob;
    delete me;
    delete clone;
    delete src;

    // Clean the floor
    std::cout << "Cleaning the floor of unequipped Materias..." << std::endl;
    Character::cleanFloor();

    std::cout << "Program finished successfully!" << std::endl;
    return 0;
}
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <vector>

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria* _inventory[4];
        static std::vector<AMateria*> _floor; // Materias en el suelo
    public :
        Character();
        Character(std::string const & type);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        virtual std::string const & getName() const;
        static size_t getFloorSize(); // Getter for the size of the _floor
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        static void cleanFloor(); // para limpiar el suelo al final
};

#endif
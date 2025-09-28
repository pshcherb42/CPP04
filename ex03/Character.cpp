#include "Character.hpp"
std::vector<AMateria*> Character::_floor; // definir la variable estatica

Character::Character() : _name("Default name") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character default constructor called." << std::endl;
};

Character::Character(std::string const & type) : _name(type) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "Character parameterized constructor called." << std::endl;
};

Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called." << std::endl;
};

Character &Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) { // liberar memoria
            if (_inventory[i])
                delete _inventory[i];
        }
        // copiar nuevas materias
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    std::cout << "Character assigment operator called." << std::endl;
    return *this;
};

std::string const & Character::getName() const {
    return (_name);
};

size_t Character::getFloorSize() {
    return (_floor.size());
};

void Character::equip(AMateria* m) {
    if (!m) return;

   for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
   }
   // si llegamos aqui y el inventario esta lleno no hacer nada
};

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) return;

    if (_inventory[idx]) {
        // delete _inventory[idx]; no hacer delete solo remover del inventario
        _floor.push_back(_inventory[idx]); // guardar en el suelo
        _inventory[idx] = NULL;           // remover del inventario
    }
};

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3) return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
};

void Character::cleanFloor() {
    for (size_t i = 0; i < _floor.size(); i++) {
        delete _floor[i];
    }
    _floor.clear();
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
    }
    std::cout << "Character destructor called." << std::endl;
};
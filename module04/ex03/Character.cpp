#include "Character.hpp"

Character::Character(std::string name) : name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& copy) : name(copy.name) {
    for (int i = 0; i < 4; i++){
        if (inventory[i] != NULL)
            inventory[i] = copy.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& original) {
    if (this != &original){
        name = original.name;
        for (int i = 0; i < 4; i++){
            if (inventory[i] != NULL)
                delete inventory[i];
            if (original.inventory[i] != NULL)
                inventory[i] = original.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        if (inventory[i] != NULL)
        delete inventory[i];
    }
}
// Author: Timothy Kiyui (4316886)
// File: Player.h

#ifndef PLAYER
#define PLAYER

#include "GameObject.h"
#include "Inventory.h"
#include "IHaveInventory.h"
#include <string>

// Player class, inherits from GameObject
class Player: public GameObject, public IHaveInventory
{
    private:
        // All items will be stored here.
        Inventory *_inventory;
    public:
        // Constructor as _inventory need memory to be allocated
        Player(string name, string desc);
        // Destructor method
        virtual ~Player();
        // Downcasts a found item in inventory
        GameObject *locate(string id);
        // Gets the player's full description
        string get_full_description();
        // Gets the player's inventory memory
        Inventory *get_inventory();
};
#endif

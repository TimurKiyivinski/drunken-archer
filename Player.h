// Author: Timothy Kiyui (4316886)
// File: Player.h

#ifndef PLAYER
#define PLAYER

#include "GameObject.h"
#include "Inventory.h"
#include "IHaveInventory.h"
#include "Location.h"
#include <string>

// Player class, inherits from GameObject
class Player: public GameObject, public IHaveInventory
{
    private:
        // All items will be stored here.
        Inventory *_inventory;
        // Player's current location
        Location *_location;
        // Player's last location
        Location *_last_location;
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
        // Get and set methods for location
        Location* get_location();
        void set_location(Location* location);
        // Player can leave a location
        void leave_location();
};
#endif

// Author: Timothy Kiyui (4316886)
// File: Location.h

#ifndef LOCATION
#define LOCATION

#include "GameObject.h"
#include "Inventory.h"
#include "Item.h"
#include "IHaveInventory.h"
#include "Path.h"
#include <string>
#include <vector>

using namespace std;

class Path;

class Location: public GameObject, public IHaveInventory
{
    private:
        // Inventory to store Items
        Inventory *_inventory;
        // A location has paths to other locations
        Path *_path;
    public:
        // Constructor
        Location(vector<string> ids, string name, string desc);
        // Destructor
        ~Location();
        // Returns located item as GameObject
        GameObject *locate(string id);
        // Returns location name and description
        string get_full_description();
        // Returns memory of _inventory
        Inventory *get_inventory();
        // Get and set methods for path
        void set_path(Path *p);
        Path* get_path();
};
#endif

// Author: Timothy Kiyui (4316886)
// File: Bag.h

#ifndef BAG
#define BAG

#include "GameObject.h"
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <vector>

class Bag: public Item
{
    private:
        // Inventory to store Items
        Inventory *_inventory;
    public:
        // Constructor
        Bag(vector<string> ids, string name, string desc);
        // Not sure why this is not in design?
        ~Bag();
        // Returns located item as GameObject
        GameObject *locate(string id);
        // Returns description and bag items
        string get_full_description();
        // Returns memory of _inventory
        Inventory *get_inventory();
};
#endif

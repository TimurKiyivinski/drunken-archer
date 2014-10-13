// Author: Timothy Kiyui (4316886)
// File: Inventory.h

#ifndef INVENTORY
#define INVENTORY

#include "Item.h"
#include <vector>

class Inventory
{
    private:
        // List of item memory in inventory
        vector<Item*> _items;
    public:
        // Constructor
        Inventory();
        // Destructor
        ~Inventory();
        // Returns true if inventory contains an item
        bool has_item(string id);
        // Adds an item to inventory
        void put(Item *itm);
        // Take and remove item from inventory
        Item *take(string id);
        // Take item
        Item *fetch(string id);
        // Returns a tab separated item list
        string get_item_list();
};
#endif

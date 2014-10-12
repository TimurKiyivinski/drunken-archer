// Author: Timothy Kiyui (4316886)
// File: Inventory.h

#ifndef INVENTORY
#define INVENTORY

#include "Item.h"
#include <vector>

class Inventory
{
    private:
        vector<Item*> _items;
    public:
        Inventory();
        ~Inventory();
        bool has_item(string id);
        void put(Item *itm);
        Item *take(string id);
        Item *fetch(string id);
        string get_item_list();
};
#endif

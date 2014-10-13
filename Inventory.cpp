// Author: Timothy Kiyui (4316886)
// File: Inventory.cpp

#include "Inventory.h"

// Nothing has to be initialised
Inventory::Inventory():
    _items(vector<Item*>())
{
}

// Removes all items in the inventory
Inventory::~Inventory()
{
    for (int i = 0; i < _items.size(); i++)
    {
        Item *itm = _items[i];
        delete itm;
    }
}

bool Inventory::has_item(string id)
{
    // Loops through all items in the inventory
    // and returns true if the item returns true to are_you()
    for (Item *itm: _items)
        if (itm->are_you(id)) return true;
    return false;
}

void Inventory::put(Item *itm)
{
    // Add the item memory to inventory
    _items.push_back(itm);
}

Item* Inventory::take(string id)
{
    // Iterate the vector C++98 style
    for (int i = 0; i < _items.size(); i++)
    {
        Item *itm = _items[i];
        if (itm->are_you(id))
        {
            // Erase an item from memory if is identified
            _items.erase(_items.begin() + i);
            return itm; // Returns item
        }
    }
    return NULL;
}

Item* Inventory::fetch(string id)
{
    // Uses a range based loop to return the identified item
    for (Item *itm: _items)
        if (itm->are_you(id)) return itm;
    // Returns NULL if the item is not identified
    return NULL;
}

string Inventory::get_item_list()
{
    // Initial return string
    string returnStr("");
    // Adds all items separated by tabs
    for (Item *itm: _items)
        returnStr += itm->get_short_description() + "\t";
    return returnStr;
}

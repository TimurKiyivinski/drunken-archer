// Author: Timothy Kiyui (4316886)
// File: Inventory.cpp

#include "Inventory.h"

Inventory::Inventory():
    _items(vector<Item*>())
{
}

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
    for (Item *itm: _items)
        if (itm->are_you(id)) return true;
    return false;
}

void Inventory::put(Item *itm)
{
    _items.push_back(itm);
}

Item* Inventory::take(string id)
{
    for (int i = 0; i < _items.size(); i++)
    {
        Item *itm = _items[i];
        if (itm->are_you(id))
        {
            _items.erase(_items.begin() + i);
            return itm;
        }
    }
    return NULL;
}

Item* Inventory::fetch(string id)
{
    for (Item *itm: _items)
        if (itm->are_you(id)) return itm;
    return NULL;
}

string Inventory::get_item_list()
{
    string returnStr("");
    for (Item *itm: _items)
        returnStr += itm->get_short_description() + "\t";
    return returnStr;
}

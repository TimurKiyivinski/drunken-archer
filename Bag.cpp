#include "Bag.h"
#include "GameObject.h"
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <vector>
#include <algorithm>

Bag::Bag(vector<string> ids, string name, string desc):
    Item(ids, name, desc)
{   
    // Allocates memory for Inventory
    _inventory = new Inventory();
}

// Having to delete from get_inventory() is odd
Bag::~Bag()
{
    delete _inventory;
}

GameObject* Bag::locate(string id)
{
    // Locates an item using are_you and returns it
    if (are_you(id)) return this;
    return _inventory->fetch(id);
}

string Bag::get_full_description()
{   
    // Create the return string
    string returnStr("In the " +
            get_name() +
            " you can see:\n" +
            _inventory->get_item_list());
    // Switch tabs to newlines for proper output
    replace(returnStr.begin(), returnStr.end(), '\t', '\n');
    return returnStr;
}

Inventory* Bag::get_inventory()
{
    // Returns memory of _inventory
    return _inventory;
}

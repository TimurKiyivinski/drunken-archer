// Author: Timothy Kiyui (4316886)
// File: Location.cpp

#include "Location.h"
#include "GameObject.h"
#include "Inventory.h"
#include "Item.h"
#include "IHaveInventory.h"
#include "Path.h"
#include <string>
#include <vector>
#include <algorithm>

Location::Location(vector<string> ids, string name, string desc):
    GameObject(ids, name, desc), IHaveInventory()
{   
    // Allocates memory for Inventory and Path
    _inventory = new Inventory();
    _path = new Path(vector<string>());
    // Identifiable by these tags
    add_identifier("here");
    add_identifier("surroundings");
}

// Free inventory
Location::~Location()
{
    delete _inventory;
}

GameObject* Location::locate(string id)
{
    // Locates an item using are_you and returns it
    if (are_you(id)) return this;
    return _inventory->fetch(id);
}

string Location::get_full_description()
{   
    // Create the return string
    string returnStr(GameObject::get_name() + 
            " " + 
            GameObject::get_full_description() +
            "\ncontains:\n" +
            _inventory->get_item_list());
    // Switch tabs to newlines for proper output
    replace(returnStr.begin(), returnStr.end(), '\t', '\n');
    return returnStr;
}

Inventory* Location::get_inventory()
{
    // Returns memory of _inventory
    return _inventory;
}


void Location::set_path(Path *p)
{
    // Sets _path to p if not NULL
    if (p != NULL)
        _path = p;
}

// Returns path pointer
Path* Location::get_path()
{
    return _path;
}

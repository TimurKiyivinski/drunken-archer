// Author: Timothy Kiyui (4316886)
// File: Player.cpp

#include "Player.h"
#include <algorithm>
#include <string>

    Player::Player(string name, string desc)
:GameObject(vector<string>(), name, desc),
    IHaveInventory()
{
    // Allocates memory for Inventory
    _inventory = new Inventory();
    // Adds default identifiers for Player
    add_identifier("me");
    add_identifier("inventory");
    _location = NULL;
    _last_location = NULL;
}

// Free allocated memory
Player::~Player()
{
    delete _inventory;
}

GameObject* Player::locate(string id)
{
    // Returns self if is id
    if (are_you(id)) return this;
    // Defaults to returning a value from inventory
    GameObject *_locate = _inventory->fetch(id);
    if (_locate == NULL) _locate = _location->locate(id);
    return _locate;
}

string Player::get_full_description()
{
    // Create the return string
    string returnStr("you are " +
            GameObject::get_name() + 
            " " + 
            GameObject::get_full_description() +
            "\nyou are carrying:\n" +
            _inventory->get_item_list());
    // Switch tabs to newlines for proper output
    replace(returnStr.begin(), returnStr.end(), '\t', '\n');
    return returnStr;
}

Inventory* Player::get_inventory()
{
    // Return memory of _inventory to be manipulated.
    return _inventory;
}

Location* Player::get_location() { return _location; }

// Sets a player's location if not NULL
void Player::set_location(Location *location)
{
    if (location != NULL)
    {
        if (_location == NULL)
            _last_location == location;
        else
            _last_location = _location;
        _location = location;
    }
}

// Players returns to previous location
void Player::leave_location()
{
    _location = _last_location;
}

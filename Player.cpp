// Author: Timothy Kiyui (4316886)
// File: Player.cpp

#include "Player.h"
#include <algorithm>
#include <string>

Player::Player()
    :GameObject(vector<string>(), "", "")
{
    _inventory = new Inventory();
    add_identifier("me");
    add_identifier("inventory");
}

Player::~Player()
{
    delete _inventory;
}

GameObject* Player::locate(string id)
{
    if (are_you(id)) return this;
    return _inventory->take(id);
}

string Player::get_full_description()
{
    string returnStr("You are carrying:\n");
    returnStr += _inventory->get_item_list();
    replace(returnStr.begin(), returnStr.end(), '\t', '\n');
    return returnStr;
}

Inventory* Player::get_inventory()
{
    return _inventory;
}

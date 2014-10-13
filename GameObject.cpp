// Author: Timothy Kiyui (4316886)
// File: GameObject.cpp

#include "Identifiable.h"
#include "GameObject.h"

GameObject::GameObject(vector<string> ids, string name, string desc):
    IdentifiableObject(ids), _name(name), _description(desc)
{
    add_identifier(_name); // GameObjects are identified by their names
}

// Nothing to free
GameObject::~GameObject()
{
}

// Returns _name
string GameObject::get_name()
{
    return _name;
}

// Short description, a combination of the name
// and the first id in parentheses
string GameObject::get_short_description()
{
    return _name + " (" + first_id() + ")";
}

string GameObject::get_full_description()
{
    return _description;
}

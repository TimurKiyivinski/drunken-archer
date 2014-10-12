// Author: Timothy Kiyui (4316886)
// File: GameObject.cpp

#include "Identifiable.h"
#include "GameObject.h"

GameObject::GameObject(vector<string> ids, string name, string desc):
    IdentifiableObject(ids), _name(name), _description(desc)
{
    add_identifier(_name);
}

GameObject::~GameObject()
{
}

string GameObject::get_name()
{
    return _name;
}

string GameObject::get_short_description()
{
    return _name + " (" + first_id() + ")";
}

string GameObject::get_full_description()
{
    return _description;
}

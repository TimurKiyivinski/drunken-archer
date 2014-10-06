// Author: Timothy Kiyui (4316886)
// File: Identifiable.cpp

#include "Identifiable.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

// Converts a string to lowercase
string toLower(string id)
{
    transform(id.begin(), id.end(), id.begin(), ::tolower);
    return id;
}

// Constructor
IdentifiableObject::IdentifiableObject(vector<string> idents)
{
    // Use method add_identifier as it converts to lowercase
    // before adding a contact
    for (string i : idents)
        add_identifier(i);
}

// Empty destructor
IdentifiableObject::~IdentifiableObject() {}

// Adds an identifier to the object
void IdentifiableObject::add_identifier(string id)
{
    // Don't add an existing id
    if (are_you(id))
        return;
    id = toLower(id); // Non case-sensitive ids
    _identifiers.push_back(id); // Add the id
}

// Tests if the objects is identifiable by a certain string
bool IdentifiableObject::are_you(string id)
{
        // Uses vector iterators to check if the id exists
        return find(_identifiers.begin(), _identifiers.end(),
                    toLower(id)) - _identifiers.begin() < _identifiers.size();
}

// Returns the first identifiable id
string IdentifiableObject::first_id()
{
    return _identifiers[0]; // First should be at index 0
}

#ifdef EXTRA
// Extra: Returns the value of an identifier at an index
string IdentifiableObject::get_at(int i)
{
    if (i < _identifiers.size())
        return _identifiers[i];
    // String throw is okay here as I know I'm catching a string
    else throw string("Out of bounds!"); // Gives errors so I don't access wrong areas
}
#endif

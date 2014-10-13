// Author: Timothy Kiyui (4316886)
// File: Item.h

#ifndef ITEM
#define ITEM

#include "GameObject.h"

// Game Item class
class Item: public GameObject
{
    public:
        // Constructor for GameObject parent
        Item(vector<string> ids, string name, string desc);
};
#endif

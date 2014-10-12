// Author: Timothy Kiyui (4316886)
// File: Item.h

#ifndef ITEM
#define ITEM

#include "GameObject.h"

class Item: public GameObject
{
    public:
        Item(vector<string> ids, string name, string desc);
};
#endif

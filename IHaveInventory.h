// Author: Timothy Kiyui (4316886)
// File: IHaveInventory.h

#ifndef IHAVEINVENTORY
#define IHAVEINVENTORY

#include "GameObject.h"
#include <string>

class IHaveInventory
{
    public:
        // All children must be able to locate
        virtual GameObject* locate(string id)=0;
        // All children must have a get method for name
        virtual string get_name();
};
#endif

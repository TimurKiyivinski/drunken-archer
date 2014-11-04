#include "GameObject.h"
#include <string>

#ifndef IHAVEINVENTORY_H
#define IHAVEINVENTORY_H

class IHaveInventory
{
    public:
        virtual GameObject* locate(string id)=0;
        virtual string get_name();
};
#endif

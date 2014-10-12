// Author: Timothy Kiyui (4316886)
// File: Player.h

#ifndef PLAYER
#define PLAYER

#include "GameObject.h"
#include "Inventory.h"
#include <string>

class Player: public GameObject
{
    private:
        Inventory *_inventory;
    public:
        Player();
        virtual ~Player();
        GameObject *locate(string id);
        string get_full_description();
        Inventory *get_inventory();
};
#endif

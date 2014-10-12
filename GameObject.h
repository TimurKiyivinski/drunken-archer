// Author: Timothy Kiyui (4316886)
// File: GameObject.h

#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "Identifiable.h"

// Abstract class for all objects in the game
class GameObject: public IdentifiableObject
{
    private:
        // GameObject description
        string _description;
        // GameObject name
        string _name;
    public:
        // Constructor, initializes IdentifiableObject
        GameObject(vector<string> ids, string name, string desc);
        // Virtual desctructor
        virtual ~GameObject();
        // Returns the name
        string get_name();
        // Returns the short description
        string get_short_description();
        // Returns the full description
        // method is virtual because Item uses this
        // default method wheras Player will
        // override this method.
        virtual string get_full_description();
};
#endif

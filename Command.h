// Author: Timothy Kiyui (4316886)
// File: Command.h

#ifndef COMMAND
#define COMMAND

#include "Identifiable.h"
#include "Player.h"
#include <vector>
#include <string>

// The command class must be able to interpret different kinds of commands
class Command: public IdentifiableObject
{
    public:
        // Constructor
        Command(vector<string> ids);
        // All chilren must implement an execute interface
        virtual string execute(Player *p, vector<string> text)=0;
};
#endif

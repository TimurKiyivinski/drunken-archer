#include "Identifiable.h"
#include "Player.h"
#include <vector>
#include <string>

#ifndef COMMAND_H
#define COMMAND_H

class Command: public IdentifiableObject
{
    public:
        Command(vector<string> ids);
        virtual string execute(Player *p, vector<string> text)=0;
};

#endif

// Author: Timothy Kiyui (4316886)
// File: LookCommand.h

#ifndef LOOKCOMMAND
#define LOOKCOMMAND

#include "Command.h"
#include "Player.h"

class LookCommand: public Command
{
    private:
        // Looks at items and returns the description
        string look_at_in(Player *p, string id, string container_id);
    public:
        // Constructor
        LookCommand();
        // Overrides Command
        string execute(Player *p, vector<string> text);
};
#endif

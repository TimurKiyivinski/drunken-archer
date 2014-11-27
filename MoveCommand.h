// Author: Timothy Kiyui (4316886)
// File: MoveCommand.h

#ifndef MOVECOMMAND
#define MOVECOMMAND

#include "Command.h"
#include "Player.h"

class MoveCommand: public Command
{
    private:
        // Moves the player and returns the description
        string move_player_to(Player *p, string id);
    public:
        // Constructor
        MoveCommand();
        // Overrides Command
        string execute(Player *p, vector<string> text);
};
#endif

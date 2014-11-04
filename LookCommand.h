#include "Command.h"
#include "Player.h"

#ifndef LOOKCOMMAND_H
#define LOOKCOMMAND_H

class LookCommand: public Command
{
    private:
        string look_at_in(Player *p, string id, string container_id);
    public:
        LookCommand();
        string execute(Player *p, vector<string> text);
};
#endif

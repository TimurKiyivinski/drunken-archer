#include "Identifiable.h"
#include "Player.h"
#include <vector>
#include <string>

class Command: public IdentifiableObject
{
    public:
        Command(vector<string> ids);
        virtual string execute(Player *p, vector<string> text);
};
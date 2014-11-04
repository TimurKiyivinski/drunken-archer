#include "Command.h"
#include <vector>
#include <string>

Command::Command(vector<string> ids): IdentifiableObject(ids)
{
}

string Command::execute(Player *p, vector<string> text)
{
}

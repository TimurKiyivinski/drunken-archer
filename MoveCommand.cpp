// Author: Timothy Kiyui (4316886)
// File: MoveCommand.cpp

#include "MoveCommand.h"
#include "Location.h"
#include "Path.h"
#include <string>
#include <vector>

using namespace std;

MoveCommand::MoveCommand():Command(vector<string>())
{
    // All move identifiers
    add_identifier("move");
    add_identifier("go");
    add_identifier("head");
    add_identifier("leave");
}

string MoveCommand::execute(Player *p, vector<string> text)
{
    if (text.size() == 1 && text[0] != "leave" || text.size() > 3)
        return "i don't know how to move like that";
    // First word must be look to indicate the look command
    if (text[0] != "move" &&
            text[0] != "go" &&
            text[0] != "head" &&
            text[0] != "leave")
        return "error in move input";
    string moveStr("");
    // Proper syntax requires to
    if (text[0] != "leave")
    {
        if (text[1] != "to" || text.size() < 3)
            return "where do you want to go?";
        else
            return MoveCommand::move_player_to(p, text[2]);
    }
    else
        return MoveCommand::move_player_to(p, "leave");
}

string MoveCommand::move_player_to(Player *p, string id)
{
    // Leaves using player leave method
    if (id == "leave")
    {
        p->leave_location();
        Location *_location = p->get_location();
        return _location->get_full_description();
    }
    // Gets the location from the current path and returns the description
    Location *_location = p->get_location();
    Path *_path = _location->get_path();
    if (_path == NULL)
        return "location has no path";
    _location = _path->get_location(id);
    if (_location == NULL)
        return "path not found";
    p->set_location(_location);
    return _location->get_full_description();
}

// Author: Timothy Kiyui (4316886)
// File: Path.cpp

#include "Path.h"
#include "Location.h"
#include <vector>
#include <string>

using namespace std;

Path::Path(vector<string> idents):IdentifiableObject(idents)
{
    _north = NULL;
    _south = NULL;
    _east = NULL;
    _west = NULL;
    _north_east = NULL;
    _north_west = NULL;
    _south_east = NULL;
    _south_west = NULL;
}

Path::~Path() {}

void Path::set_location(char direction, Location *location)
{
    if (location == NULL) return;
    switch(direction)
    {
        case 'n':
            _north = location;
            break;
        case 's':
            _south = location;
            break;
        case 'e':
            _east = location;
            break;
        case 'w':
            _west = location;
            break;
        case 'a':
            _north_east = location;
            break;
        case 'b':
            _north_west = location;
            break;
        case 'c':
            _south_east = location;
            break;
        case 'd':
            _south_west = location;
            break;
    }
}

Location* Path::get_location(string direction)
{
    // Check which direction the player intends to go
    if (direction == "n" || direction == "up" || direction == "north")
        return _north;
    else if (direction == "s" || direction == "down" || direction == "south")
        return _south;
    else if (direction == "e" || direction == "east")
        return _east;
    else if (direction == "w" || direction == "west")
        return _west;
    else if (direction == "a" || direction == "north_east")
        return _north_east;
    else if (direction == "b" || direction == "north_west")
        return _north_west;
    else if (direction == "c" || direction == "south_east")
        return _south_east;
    else if (direction == "d" || direction == "south_west")
        return _south_west;
    else
    {
        // If player decides to input the name of the Location for whatever
        // reason, we handle it here.
        if (_north != NULL)
            if (_north->are_you(direction)) return _north;
        if (_south != NULL)
            if (_south->are_you(direction)) return _south;
        if (_east != NULL)
            if (_east->are_you(direction)) return _east;
        if (_west != NULL)
            if (_west->are_you(direction)) return _west;
        if (_north_east != NULL)
            if (_north_east->are_you(direction)) return _north_east;
        if (_north_west != NULL)
            if (_north_west->are_you(direction)) return _north_west;
        if (_south_east != NULL)
            if (_south_east->are_you(direction)) return _south_east;
        if (_south_west != NULL)
            if (_south_west->are_you(direction)) return _south_west;
        // Otherwise, return NULL
        return NULL;
    }
}

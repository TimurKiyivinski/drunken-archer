// Author: Timothy Kiyui (4316886)
// File: Path.h

#ifndef PATH
#define PATH

#include "Identifiable.h"
#include "Location.h"
#include <vector>
#include <string>

using namespace std;

class Location;

class Path: public IdentifiableObject
{
    private:
        // All possible paths
        Location *_north;
        Location *_south;
        Location *_east;
        Location *_west;
        Location *_north_east;
        Location *_north_west;
        Location *_south_east;
        Location *_south_west;
    public:
        // Constructor
        Path(vector<string> idents);
        // Destructor
        ~Path();
        void set_location(char direction, Location *location);
        Location* get_location(string direction);
};
#endif

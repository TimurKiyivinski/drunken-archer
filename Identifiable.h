// Author: Timothy Kiyui (4316886)
// File: Identifiable.h

#ifndef IDENTIFIABLE
#define IDENTIFIABLE

#include <string>
#include <vector>

using namespace std;

class IdentifiableObject
{
    private:
        // A vector of identifiers, easier to iterate
        vector<string> _identifiers;
    public:
        // Class constructor
        IdentifiableObject(vector<string> idents);
        // Destructor
        ~IdentifiableObject();
        // Adds an identifier to _identifiers
        void add_identifier(string id);
        // Returns true if id is in _identifiers
        bool are_you(string id);
        // Returns the first identifier
        string first_id();
#ifdef EXTRA
        // Returns the identifier at a certain index
        string get_at(int i);
#endif
};
#endif

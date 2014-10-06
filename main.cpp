// Author: Timothy Kiyui (4316886)
// File: main.cpp

#include <iostream>
#include <string>
#include <vector>
#include "Identifiable.h"

// No std::
using namespace std;

// IdentifiableObject is too long
#define IdObj IdentifiableObject
// Laziness strikes 10 lines in.
#define y "Yes"
#define n "No"

int main(void)
{
    // Create an initial vector.
    vector<string> myIDs;
    // Add values to initial vector.
    myIDs.push_back("FrEd");
    myIDs.push_back("boB");
    // Declare an IdentifiableObject with the vector passed to the constructor.
    IdObj *myID = new IdObj(myIDs);
    // A string for are_you() returns.
    string str_are_you;
    // Set are_you for fRed.
    str_are_you = myID->are_you("fRed") ? y : n;
    // Test output.
    cout << "Testing id " << myIDs[0] << " for fRed: " << str_are_you << endl;
    // Set are_you for BOB.
    str_are_you = myID->are_you("BOB") ? y : n;
    // Test output.
    cout << "Testing id " << myIDs[1] << " for BOB: " << str_are_you << endl;
    // Test first_id.
    cout << "First ID is: " << myID->first_id() << endl;
    // Add WiLMa
    myID->add_identifier("WiLMa");
#ifdef EXTRA
    // Extra, list all items and throw exception when reach out of bounds.
    try
    {
        for (int i = 0; i < 5; i++)
        {
            cout << myID->get_at(i) << endl;
        }
    }
    catch(const string ex)
    {
        cout << "Caught exception: " << ex << endl;
    }
#endif
    // Free memory.
    delete myID;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

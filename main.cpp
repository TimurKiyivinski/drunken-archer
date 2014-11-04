// Author: Timothy Kiyui (4316886)
// File: main.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "Bag.h"
#include "LookCommand.h"

// No std::
using namespace std;

vector<string> splitCommand(string strCommand)
{
    stringstream commandStream(strCommand);
    string splitString;
    vector<string> commandVector;
    while (commandStream.good())
    {
        commandStream >> splitString;
        commandVector.push_back(splitString);
    }
    return commandVector;
}

int main(void)
{
    // Create a player
    Player *timur = new Player("Timur", "who likes to meow");
    Inventory *timurInventory = timur->get_inventory();
    // Create a look command!
    LookCommand commands;
    // Dummy text for commands
    string commandText("look at inventory");
    vector<string> commandVector = splitCommand(commandText);
    // Test look at me
    cout << commands.execute(timur, commandVector) << endl;
    // Add Gem!
    Item *gem = new Item(vector<string>(), "gem", "it is pretty!");
    timurInventory->put(gem);
    // Test look at unknown
    commandText = "look at something_that_does_not_exist";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at gem
    commandText = "look at gem";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at gem in me
    commandText = "look at gem in inventory";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Kill timur
    delete timur;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

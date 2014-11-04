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
    cout << "Test look at me" << endl;
    cout << commands.execute(timur, commandVector) << endl;
    // Add Gem!
    Item *gem = new Item(vector<string>(), "gem", "it is pretty!");
    timurInventory->put(gem);
    // Test look at unknown
    cout << "Test look at unknown" << endl;
    commandText = "look at something_that_does_not_exist";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at gem
    cout << "Test look at gem" << endl;
    commandText = "look at gem";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at gem in me
    cout << "Test look at gem in me" << endl;
    commandText = "look at gem in inventory";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at no bag
    cout << "Test look at no bag" << endl;
    commandText = "look at gem in chest";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at gem in bag
    cout << "Test look at gem in bag" << endl;
    Bag *timurBag = new Bag(vector<string>(), "chest", "contains stuff");
    Inventory *bagInventory = timurBag->get_inventory();
    bagInventory->put(timurInventory->take("gem"));
    timurInventory->put(timurBag);
    commandText = "look at gem in chest";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test look at no gem in bag
    cout << "Test look at no gem in bag" << endl;
    Item* stolen_gem = bagInventory->take("gem");
    commandText = "look at gem in chest";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Test invalid commands!
    cout << "Test invalid commands" << endl;
    commandText = "live the dreams my lovely hero";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    commandText = "meow meow meow";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    commandText = "look meow meow";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    commandText = "look at meow inside meow";
    commandVector = splitCommand(commandText);
    cout << commands.execute(timur, commandVector) << endl;
    // Kill timur
    delete timur;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

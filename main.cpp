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
    //Ask to create a player!
    string playerName, playerDesc;
    cout << "Please input a player name:" << endl;
    cin >> playerName;
    cout << "Please input a player description:" << endl;
    cin.ignore();
    getline(cin, playerDesc);
    Player *player = new Player(playerName, playerDesc);
    // Check if player is succesfully created
    if (player == NULL) return 1;
    else cout << "Player successfully created:" << endl;
    // Create items!
    Item *bread = new Item(vector<string>(), "bread", "made with yeast!");
    Item *sword = new Item(vector<string>(), "sword", "lvl 1 n00bz lel");
    Item *fish = new Item(vector<string>(), "fish", "smelly stuff");
    Item *something = new Item(vector<string>(), "something", "divisible by 0");
    Bag *chest = new Bag(vector<string>(), "chest", "has space!");
    Bag *pocket = new Bag(vector<string>(), "pocket", "in me pants they are!");
    Inventory *playerInventory = player->get_inventory();
    Inventory *chestInventory = chest->get_inventory();
    Inventory *pocketInventory = pocket->get_inventory();
    chestInventory->put(bread);
    chestInventory->put(sword);
    pocketInventory->put(something);
    playerInventory->put(fish);
    playerInventory->put(chest);
    playerInventory->put(pocket);
    // Infinite command loop
    string commandText("");
    vector<string> commandVector;
    LookCommand commands;
    while (1)
    {
        cout << endl << player->get_full_description() << endl;
        cout << "Input || quit:" << endl;
        getline(cin, commandText);
        if (commandText == "quit") return 0;
        commandVector = splitCommand(commandText);
        cout << endl << "Output:" << endl;
        cout << commands.execute(player, commandVector) << endl;
    }
    // Kill timur
    delete player;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

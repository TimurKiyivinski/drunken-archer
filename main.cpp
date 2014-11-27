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
#include "MoveCommand.h"
#include "CommandProcessor.h"
#include "Location.h"
#include "Path.h"

// No std::
using namespace std;

#define println(a) cout << a << endl;

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
    // Create items
    Item *player_note = new Item(vector<string>(), "readme", "remember your mission.. find out clues on what happened to the islanders");
    Item *intel = new Item(vector<string>(), "intel", "the islanders were attacked by pirates, find out about them");
    Item *note = new Item(vector<string>(), "note", "hide the gold before the pirates arrive");
    Item *compass = new Item(vector<string>(), "compass", "the gold you seek is in the pouch in the chest");
    Item *horse = new Item(vector<string>(), "horse", "the carcass of the dead animal");
    Item *hay = new Item(vector<string>(), "hay", "this poisoned hay killed the horse");
    Item *peanuts = new Item(vector<string>(), "peanuts", "kind of rotten now");
    Item *fish = new Item(vector<string>(), "fish", "looks fresh");
    Item *shrimp = new Item(vector<string>(), "shrimp", "the finest kind");
    Item *noodles = new Item(vector<string>(), "noodles", "looks eaten");
    Item *gold = new Item(vector<string>(), "gold", "to be hidden from the pirates");
    Item *ruby = new Item(vector<string>(), "ruby", "precious to pirates");
    Item *gems = new Item(vector<string>(), "gems", "not to be mistaken for lozenges");
    Item *head = new Item(vector<string>(), "head", "the rotting head of brian sim");
    Item *pirate_note = new Item(vector<string>(), "arrrrr", "the leader is gone, our debt is settled");
    // Create bags
    Bag *bag = new Bag(vector<string>(), "bag", "belongs to brian");
    Bag *box = new Bag(vector<string>(), "box", "slightly damp");
    Bag *bucket = new Bag(vector<string>(), "bucket", "made of metal");
    Bag *cup = new Bag(vector<string>(), "cup", "says cup noodles on it");
    Bag *chest = new Bag(vector<string>(), "chest", "the treasure");
    Bag *pouch = new Bag(vector<string>(), "pouch", "less precious");
    Bag *sack = new Bag(vector<string>(), "sack", "the gold");
    // Create locations
    Location *barn = new Location(vector<string>(), "barn", "partially burnt");
    Location *altar = new Location(vector<string>(), "altar", "covered in blood");
    Location *harbour = new Location(vector<string>(), "harbour", "left by the islanders after the pirates attacked");
    Location *deck = new Location(vector<string>(), "deck", "partially broken");
    Location *ship = new Location(vector<string>(), "ship", "half sunk and in ruins");
    Location *cell = new Location(vector<string>(), "cell", "the leader of the islanders was murdered here");
    // Create paths
    Path *p_barn = barn->get_path();
    p_barn->set_location('w', altar);
    p_barn->set_location('n', harbour);
    Path *p_altar = altar->get_path();
    p_altar->set_location('e', barn);
    p_altar->set_location('a', harbour);
    Path *p_harbour = harbour->get_path();
    p_harbour->set_location('s', barn);
    p_harbour->set_location('d', altar);
    p_harbour->set_location('n', deck);
    p_harbour->set_location('a', ship);
    Path *p_deck = deck->get_path();
    p_deck->set_location('s', harbour);
    p_deck->set_location('e', ship);
    p_deck->set_location('a', cell);
    Path *p_ship = ship->get_path();
    p_ship->set_location('w', deck);
    p_ship->set_location('n', cell);
    p_ship->set_location('d', harbour);
    Path *p_cell = cell->get_path();
    p_cell->set_location('s', ship);
    p_cell->set_location('d', deck);
    // Put items in inventory
    Inventory *i_player = player->get_inventory();
    i_player->put(player_note);
    i_player->put(intel);
    Inventory *i_bag = bag->get_inventory();
    i_bag->put(note);
    i_bag->put(compass);
    Inventory *i_box = box->get_inventory();
    i_box->put(hay);
    i_box->put(peanuts);
    Inventory *i_bucket = bucket->get_inventory();
    i_bucket->put(fish);
    i_bucket->put(shrimp);
    Inventory *i_cup = cup->get_inventory();
    i_cup->put(noodles);
    Inventory *i_chest = chest->get_inventory();
    i_chest->put(pouch);
    i_chest->put(sack);
    Inventory *i_pouch = pouch->get_inventory();
    i_pouch->put(ruby);
    i_pouch->put(gems);
    Inventory *i_sack = sack->get_inventory();
    i_sack->put(gold);
    Inventory *i_barn = barn->get_inventory();
    i_barn->put(box);
    i_barn->put(horse);
    Inventory *i_altar = altar->get_inventory();
    i_altar->put(bag);
    Inventory *i_harbour = harbour->get_inventory();
    i_harbour->put(bucket);
    Inventory *i_deck = deck->get_inventory();
    i_deck->put(cup);
    Inventory *i_ship = ship->get_inventory();
    i_ship->put(chest);
    Inventory *i_cell = cell->get_inventory();
    i_cell->put(head);
    i_cell->put(pirate_note);
    // Put player in barn
    player->set_location(barn);
    // Create commands
    Command *look_command = new LookCommand();
    Command *move_command = new MoveCommand();
    CommandProcessor *myCommands = new CommandProcessor(vector<string>());
    myCommands->add_command(look_command);
    myCommands->add_command(move_command);
    // Infinite command loop
    string commandText("");
    vector<string> commandVector;
    LookCommand commands;
    while (1)
    {
        cout << endl << player->get_full_description() << endl;
        cout << "Input: ";
        getline(cin, commandText);
        if (commandText == "quit") return 0;
        commandVector = splitCommand(commandText);
        cout << myCommands->execute(player, commandVector) << endl;
    }
    // Free memory
    delete player;
    delete barn;
    delete altar;
    delete harbour;
    delete deck;
    delete ship;
    delete cell;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

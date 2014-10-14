// Author: Timothy Kiyui (4316886)
// File: main.cpp

#include <iostream>
#include <string>
#include <vector>
#include "Identifiable.h"
#include "GameObject.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"

// No std::
using namespace std;

// IdentifiableObject is too long
#define IdObj IdentifiableObject

int main(void)
{
    // Create initial list of ids
    vector<string> ids;
    ids.push_back("shovel");
    ids.push_back("spade");
    // Create an item with these ids
    Item *shovel = new Item(ids, "a shovel",
            "this be eh mighty fine shovel!");
    // Test if the item is identifiable
    shovel->are_you("spade") ?
        (cout << "Identified shovel." << endl):
        (cout << "Me no comprendo." << endl);
    // Gets item short description
    cout << shovel->get_short_description() << endl;
    // Gets item long description
    cout << shovel->get_full_description() << endl;
    // Test Player
    Player *timur = new Player("Timur", "the guy who wears GEEK shirts a lot!");
    // Create an inventory!
    Inventory *bag = timur->get_inventory();
    bag->put(shovel);
    // Test if inventory has an item
    bag->has_item("shovel") ?
        (cout << "Bag has a shovel." << endl):
        (cout << "No shovel found!" << endl);
    // Fetch item from bag
    Item *shovel_mem = bag->fetch("shovel");
    shovel_mem->are_you("shovel") ?
        (cout << "Identified shovel_mem." << endl):
        (cout << "Me no comprendo." << endl);
    // Test that shovel is still in bag
    bag->has_item("shovel") ?
        (cout << "Bag has a shovel." << endl):
        (cout << "No shovel found!" << endl);
    // Take item from bag
    Item *stolen = bag->take("shovel");
    stolen->are_you("shovel") ?
        (cout << "Identified stolen." << endl):
        (cout << "Me no comprendo." << endl);
    // Test that shovel is still in bag
    bag->has_item("shovel") ?
        (cout << "Bag has a shovel." << endl):
        (cout << "No shovel found!" << endl);
    // Add items to bag to test
    vector<string> iv1;
    vector<string> iv2;
    iv1.push_back("sword");
    iv1.push_back("weapon");
    iv2.push_back("food");
    iv2.push_back("delicious");
    Item *sword = new Item(iv1, "sword", 
            "legend has it that this sword is part of a legend!");
    Item *kebab = new Item(iv2, "kebab", 
            "the programmer of this item was hungry grrrr");
    bag->put(sword);
    bag->put(kebab);
    // Reclaim what is stolen!
    bag->put(stolen);
    // Test the bag's inventory
    cout << bag->get_item_list() << endl;
    // Test player identifiers
    timur->are_you("me") ?
        (cout << "Identified timur with me." << endl):
        (cout << "Me no comprendo." << endl);
    timur->are_you("inventory") ?
        (cout << "Identified timur with inventory." << endl):
        (cout << "Me no comprendo." << endl);
    // Test player locate items
    Item *restolen_food = (Item *) timur->locate("food");
    restolen_food == NULL ?
        (cout << "Failed to steal food!" << endl):
        (cout << "Stole food again!" << endl);
    // Test player locate itself
    timur->locate("me") != NULL ?
        (cout << "Found myself!" << endl):
        (cout << "I can't find myself." << endl);
    // Test player locate nothing
    timur->locate("something_i_do_not_have") != NULL ?
        (cout << "I have something I don't" << endl):
        (cout << "I don't have something I don't have!" << endl);
    // Test player full description
    cout << timur->get_full_description() << endl;
    // Free memory
    delete timur;
    delete restolen_food;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

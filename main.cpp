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
#include "Bag.h"

// No std::
using namespace std;

// IdentifiableObject is too long
#define IdObj IdentifiableObject

int main(void)
{
    // A bag!
    Bag *b1 = new Bag(vector<string>(), "Chest", "stuff inside!");
    // Get the address of the bags inventory to be manipulated
    Inventory *myInventory = b1->get_inventory();
    // Create an item to add to the inventory
    Item *myItem = new Item(vector<string>(), "Mouse", "a digital one!");
    // Add item to the inventory
    myInventory->put(myItem);
    // Test locate item
    b1->locate("mouse") == NULL ?
        (cout << "Could not find mouse!" << endl):
        (cout << "Found mouse!" << endl);
    // Test locate itself
    b1->locate("chest") == NULL ?
        (cout << "Bag can't find itself!" << endl):
        (cout << "Bag found itself!" << endl);
    // Test locate nothing
    b1->locate("nothing") == NULL ?
        (cout << "Nothing does not exist!" << endl):
        (cout << "Blame dark matter!" << endl);
    // Test bag full description
    cout << b1->get_full_description() << endl;
    // Test bag in bag!
    Bag *b2 = new Bag(vector<string>(), "baggy", "oh, just some bag..");
    // Item for b2
    Item *myNewItem = new Item(vector<string>(), "wisdom", "2b||!(2b)");
    // Get b2's inventory
    Inventory *myNewInventory = b2->get_inventory();
    // Add item to b2
    myNewInventory->put(myNewItem);
    // Add b2 to b1
    myInventory->put(b2);
    // Locate b2
    cout << b1->locate("baggy")->get_name() << endl;
    // Locate items in b1 again?
    cout << b1->locate("mouse")->get_name() << endl;
    // b1 try locate items in b2
    b1->locate("wisdom") == NULL ?
        (cout << "b1 cannot locate items in b2" << endl):
        (cout << "b1 has done the impossible" << endl);
    delete b1;
    // Absolutely necessary comment for 'return 0;'.
    return 0;
}

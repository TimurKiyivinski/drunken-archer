#include <iostream>
#include "LookCommand.h"
#include "GameObject.h"
#include "Inventory.h"
#include "Player.h"
#include "Bag.h"
#include "IHaveInventory.h"

LookCommand::LookCommand(): Command(vector<string>())
{
    add_identifier("look");
}

string LookCommand::execute(Player *p, vector<string> text)
{
    // Command length must be 3 or 5
    if (text.size() != 3 && text.size() != 5)
        return "i don't know how to look like that";
    // First word must be look to indicate the look command
    if (text[0] != "look")
        return "error in look input";
    // Second word must be at to find item looked at
    if (text[1] != "at")
        return "what do you want to look at?";
    // Proper syntax requires container id
    if (text.size() == 5 && text[3] != "in")
        return "what do you want to look in?";
    else if (text.size() == 5)
        return LookCommand::look_at_in(p, text[2], text[4]); // With container
    else
        return LookCommand::look_at_in(p, text[2], ""); // Without container
}

string LookCommand::look_at_in(Player *p, string id, string container_id)
{
    // Return player if player is identifiable by id
    if (p->are_you(id)) return p->get_full_description();
    // Dummy object to hold item
    GameObject* wantedItem;
    IHaveInventory* wantedInventory;
    if (p->are_you(container_id) || container_id == "") wantedInventory = (IHaveInventory*) p;
    else wantedInventory = dynamic_cast<IHaveInventory *> (p->locate(container_id));
    if (wantedInventory == NULL) return "i cannot find the " + container_id;
    wantedItem = wantedInventory->locate(id);
    if (wantedItem == NULL)
    {
        // Better formatting
        string returnStr("");
        container_id == "" ?
            (returnStr = "i cannot find the " + id):
            (returnStr = "i cannot find the " + id + " in " + container_id);
        return returnStr;
    }
    return wantedItem->get_full_description();
}

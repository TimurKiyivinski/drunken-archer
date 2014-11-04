#include "LookCommand.h"
#include "Player.h"

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
    else
        return LookCommand::look_at_in(p, text[2], text[4]); // With container
    return LookCommand::look_at_in(p, text[2], ""); // Without container
}

string LookCommand::look_at_in(Player *p, string id, string container_id)
{
    // Dummy object to hold item
    GameObject* wantedItem;
    // If the item has no container, look for item directly
    if (container_id == "") wantedItem = p->locate(id);
    else
    {
        // If the item has a container, look for the container
        Bag wantedBag = p->locate(container_id);
        // Either get the item from container
        // or warn that the bag does not exist
        if (wantedBag != NULL) wantedItem = wantedBag->locate(id);
        else return "i cannot find the " + container_id;
    }
    // Warn user if there is no item found
    if (wantedItem == NULL)
    {
        // Better formatting
        container_id == "" ?
            (return "i cannot find the " + id):
            (return "i cannot find the " + id + " in " + container_id);
    }
    // Return the item description
    return wantedItem->get_full_description();
}

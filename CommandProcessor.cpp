// Author: Timothy Kiyui (4316886)
// File: CommandProcessor.h

#include "CommandProcessor.h"
#include <vector>

using namespace std;

// Initialize Command
CommandProcessor::CommandProcessor(vector<string> ids):
    Command(ids)
{
}

// Delete all contained commands
CommandProcessor::~CommandProcessor()
{
    for (Command *command: _commands)
        delete command;
    _commands.clear();
}

// Executes commands based on identifiers
string CommandProcessor::execute(Player *p, vector<string> text)
{
    for (Command *command: _commands)
        if (command->are_you(text[0]))
            return command->execute(p, text);
    return "no such command";
}

// Adds a command pointer
void CommandProcessor::add_command(Command *command)
{
    _commands.push_back(command);
}

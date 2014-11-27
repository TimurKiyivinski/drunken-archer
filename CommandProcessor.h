// Author: Timothy Kiyui (4316886)
// File: CommandProcessor.h

#ifndef COMMAND_PROCESSOR
#define COMMAND_PROCESSOR

#include "Command.h"
#include <vector>

// Acts as an interface to all commands
class CommandProcessor: public Command
{
    private:
        // Contains all commands
        vector<Command*> _commands;
    public:
        // Constructor
        CommandProcessor(vector<string> ids);
        // Destructor
        ~CommandProcessor();
        // Overrides from Command
        string execute(Player *p, vector<string> text);
        // Adds a command
        void add_command(Command *command);
};
#endif

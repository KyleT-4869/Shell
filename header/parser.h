#include "lexer.h"

struct Command {
    char *value;
    char *flag;
};

struct CommandTable {

};

struct Command *set_commands(struct Token *token, int length);

#include "lexer.h"

struct Command {
    char *value;
    char *flag;
};

void set_commands(struct Token *token, int tokens_length, struct Command *commands, int commands_length);
struct Command generate_commands(char *value, char *flag);
char match_approved_commands(char *value);
char validate_command(char *command);
char validate_flag(char *command, char *flag);

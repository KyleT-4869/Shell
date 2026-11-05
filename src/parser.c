#include <string.h>
#include "../header/parser.h"
#include "../header/util.h"

char validate_command(char *command) {
    int result = strcmp(command, "ls");
    if(result == 0) {
        return "ls";
    }
    else {
        return "null";
    }
}

struct Command generate_commands(char *value, char *flag) {
    struct Command command = {.value = value, .flag = flag};
    return command;
}

void set_commands(struct Token *tokens, int tokens_length, struct Command *commands, int commands_length) {
    if(tokens_length == 1) {
        char *result = validate_command(tokens[0].value);

        if(strcmp(result, "null") != 0) {
            return;
        }
        else {
            commands[0] = generate_commands(result, NULL);
        }
    }
    else {
        
    }
}




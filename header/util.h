#pragma once
#include "lexer.h"
#include "parser.h"

char *get_more_memory(char* array, int current_capacity, int for_end);
char *allocate_memory(void);
void free_tokens(struct Token *tokens);
void free_commands(struct Command *commands);
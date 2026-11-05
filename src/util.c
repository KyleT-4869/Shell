#include <stdlib.h>
#include "../header/util.h"

char *get_more_memory(char *array, int current_capacity, int for_end) {
    int new_capacity;

    if(for_end == 1) {
        new_capacity = current_capacity + 1;
    }
    else {
        new_capacity = current_capacity * 2;
    }

    char *new_array = realloc(array, new_capacity * sizeof *array);
    return new_array;
}

char *allocate_memory(void) {
    char *array = malloc(10 * sizeof(char));
    return array;
}

void free_tokens(struct Token *tokens) {}

void free_commands(struct Command *commands) {}
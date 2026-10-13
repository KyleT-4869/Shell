#include <stdlib.h>
#include <string.h>
#include "../header/lexer.h"
#include "../header/util.h"

struct Token *generate_token() {
    struct Token *newToken = malloc(sizeof *newToken);
    return newToken;
}
//TODO:
// - Add null check for all memory reallocation call
// - Add implementation to allocate more memory for token_arr
// - Add regex
void set_token(char *input, int input_length, struct Token *token_arr, int *length) {
    // Variable to track current index of input
    int i = 0;

    // Variables declare to track the value currently being examined by the input string
    char* current_token_value = allocate_memory();
    int capacity = 10;
    int j = 0;
    int has_value = 0;

    // Variables declared to track the newly created token and it's current position
    int l = 0;

    if(current_token_value == NULL) {
        return;
    }

    while(i <= input_length) {
        if(input[i] != ' ' && input[i] != '\0') {
            if(j == capacity - 1) {
                current_token_value = get_more_memory(current_token_value, capacity, 0);
                capacity *= 2;
            }
            current_token_value[j] = input[i];
            i++;
            j++;
            has_value++;
        }
        else if ((input[i] == ' ' || input[i] == '\0') && has_value != 0) {
            if(j == capacity - 1) {
                current_token_value = get_more_memory(current_token_value, capacity, 1);
            }
            current_token_value[j] = '\0';

            if(current_token_value[0] == '|') {
                token_arr[l].token_type = PIPE;
            }
            else if(current_token_value[0] == '<') {
                token_arr[l].token_type = REDIRECT_IN;
            }
            else if(current_token_value[0] == '>') {
                token_arr[l].token_type = REDIRECT_OUT;
            }
            else {
                token_arr[l].token_type = WORD;
            }

            token_arr[l].value = current_token_value;
            (*length)++;

            current_token_value = allocate_memory();
            l++;
            i++;
            j = 0;
            has_value = 0;
            capacity = 10;
        }
        else {
            i++;
        }
    }
    free(current_token_value);
    token_arr[l].token_type = END;
}
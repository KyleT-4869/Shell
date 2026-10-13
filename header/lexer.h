#pragma once

enum TokenType {
    WORD,
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    END
};

struct Token {
    enum TokenType token_type;
    char* value;
};

struct Token *generate_token(void);
void set_token(char *input, int input_length, struct Token *token_arr, int *length);
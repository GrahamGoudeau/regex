#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regex_lib.h"

#include <stdio.h>

typedef enum pattern_type_enum {
    LITERAL_PATTERN,
    RANGE,

} pattern_type;

typedef struct state_node {
    bool receive_any_character;
    char state_char;

    int num_connections;
    struct state_node *connections_list;

    bool state_fail;
    bool state_success;
} state_node;

typedef state_node *state_node_p;

/*
typedef struct compiled_regex_struct {
    bool is_successfully_compiled;
    state_node_p root_state;
} compiled_regex;
*/

static const char COMMAND_CHARS[] =
    {'\\', '^', '$', '{', '}', '[', ']', '(', ')', '.', '*', '+', '?',
        '|', '<', '>', '-', '&'};
static const int NUM_COMMAND_CHARS = 18;

static inline bool is_command_char(char test)
{
    int i;
    for (i = 0; i < NUM_COMMAND_CHARS; i++) {
        if (test == COMMAND_CHARS[i]) return true;
    }
    return false;
}

static state_node_p initialize_state_node(char state_char, bool any_char,
                                bool state_fail, bool state_success)
{
    state_node_p new_node = malloc(sizeof(state_node));
    new_node->receive_any_character = any_char;
    new_node->state_char = state_char;
    new_node->num_connections = 0;
    new_node->connections_list = NULL;
    new_node->state_fail = state_fail;
    new_node->state_success = state_success;

    return new_node;
}

void compile(char regex[])
{
    fprintf(stderr, "Compiling regex: '%s'\n", regex);
    size_t regex_len = strlen(regex);
    size_t i;

    state_node_p root = initialize_state_node('\0', false, false, false);
    state_node_p current_node = root;
    for (i = 0; i < regex_len; i++) {
        char cur_char = regex[i];
        if (!is_command_char(cur_char)) {
            current_node->num_connections = 1;
            l
        }
    }
}


bool does_match(char base_string[], char regex[])
{
    size_t base_len = strlen(base_string);
    size_t regex_len = strlen(regex);

    if (base_len < regex_len) return false;

    size_t i = 0;

    for (; i < base_len - regex_len + 1; i++) {
        size_t regex_char_matches = 0;
        size_t q = 0;
        for (; q < regex_len; q++) {
            char base_char = base_string[i + q];
            char regex_char = regex[q];

            if (base_char != regex_char) break;

            regex_char_matches++;
        }
        if (regex_char_matches == regex_len) return true;
    }
    return false;
}



int main(int argc, char **argv)
{
    //bool res = does_match(argv[1], argv[2]);
    compile(argv[1]);
    //fprintf(stderr, "Result: %d\n", res);
}

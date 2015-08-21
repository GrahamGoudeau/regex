#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "regex_lib.h"

#include <stdio.h>

typedef struct state_node {
    int num_connections;
    struct state_node *connections_list;
    bool fail;
    bool success;
} state_node;

typedef state_node *state_node_p;


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
    bool res = does_match(argv[1], argv[2]);
    fprintf(stderr, "Result: %d\n", res);
}

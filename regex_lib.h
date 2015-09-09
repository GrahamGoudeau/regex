#include <stdbool.h>

struct match_obj;

struct compiled_regex;

typedef struct match_obj *match_p;


bool does_match(char base_string[], char regex[]);

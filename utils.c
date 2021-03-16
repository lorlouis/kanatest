#include "utils.h"

int strim(char **str) {
    int trimmed_chars = 0;
    while(isspace(**str)) {
        (*str)++;
        trimmed_chars++;
    }
    char *end = *str;
    while(!isspace(*end)) end++;
    if(*end == '\0') {
        return trimmed_chars;
    }
    *end = '\0';
    end++;
    while(*end != '\0') {
        trimmed_chars++;
        end++;
    }
    return trimmed_chars;
}

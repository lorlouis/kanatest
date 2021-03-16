#ifndef UTILS_H
#define UTILS_H 1

#include <ctype.h>

/* moves *str to the first non space char
 * adds a '\0' at the end of the word
 * returns the number of chars trimmed (left + right) */
int strim(char **str);

#endif

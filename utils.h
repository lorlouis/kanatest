#ifndef UTILS_H
#define UTILS_H 1

#include <stdio.h>

/* reads size-1 onto s from stream
 * stops reading early it if
 * encounters EOF, \n, \t or \0
 * then flushes input stream
 * Returns:
 * (size-1) - chars in the buffer(minus new line)
 * < 0: more chars typed than what could fit into size-1
 * > 0: less chars read into s than size-1
 * = 0: exactly size-1 chars were read into s from input */
int freadn(char *s, int size, FILE *stream);

#endif

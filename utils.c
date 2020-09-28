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
int freadn(char *s, int size, FILE *stream) {
    int counter = 0;
    char *buff = s;
    char c;
    while(counter < size) {
        c = getc(stream);
        if(c == EOF || c == '\n' || c == '\t' || c == 0) {
            ungetc(c, stream);
            break;
        }
        buff[counter++] = c;
    }

    buff[counter++] = '\0';
    /* TODO flush input stream */
    while((c = getc(stream)) != EOF && c != '\n' && c != '\t' && c != 0) counter++;
    return size - counter;
}

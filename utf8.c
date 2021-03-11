#include "utf8.h"


/* assumes little endian
 * assumes bitshifting fills with zeroes */
void putc_utf8(uint32_t utf8_char_code, FILE *stream) {
    /*
     * UTF-8 encoding steps
     * https://en.wikipedia.org/wiki/UTF-8#Encoding
    */
    uint8_t buff;
    int nb_bytes;

    if(utf8_char_code <= 0x007f) {
        /* just a regular ascii char */
        putc(utf8_char_code & 127, stream);  /* 01111 1111 */
        return;
    }
    else if(utf8_char_code >= 0x10000) nb_bytes = 4;
    else if(utf8_char_code <= 0x07ff) nb_bytes = 2;
    else nb_bytes = 3;

    /* setting the number of bytes needed by the char */
    uint8_t mask = 0x1e;  /* 0001 1110 */
    mask <<=(7-nb_bytes);
    buff = mask;
    /* filling the remainder of the first byte */
    buff |= utf8_char_code>>(6*(nb_bytes-1));
    putc(buff, stream);
    /* printing the "follow" bytes */
    for(int i = 1; i < nb_bytes; i++) {
        /* setting 10 as the first 2 bytes
         * to flag them as "follow" bytes */
        buff = 0x80;  /* 1000 0000 */
        /* bitshifting to the relevent data from
         * the original char code to fill the byte */
        buff |= utf8_char_code>>(6*(nb_bytes-1-i)) & 0x3f;  /* 0011 1111 */
        putc(buff, stream);
    }
}

void fprint_utf8_seq_n(
        uint32_t *utf8_char_code_seq, size_t size, FILE *stream) {
    for(size_t i = 0; i < size; i++) putc_utf8(utf8_char_code_seq[i], stream);
}

void fprint_utf8_seq(uint32_t *utf8_char_code_seq, FILE *stream) {
    while(*utf8_char_code_seq != 0) putc_utf8(*utf8_char_code_seq++, stream);
}

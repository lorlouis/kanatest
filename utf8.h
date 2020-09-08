#ifndef UTF8_H
#define UTF8_H 1

#include <stdio.h>
#include <stdint.h>
#include <stdint.h>

#define putchar_utf8(utf8_char_code) putc_utf8(utf8_char_code, stdout)

#define print_utf8_seq_n(utf8_char_code_seq, size) \
    fprint_utf8_seq_n(utf8_char_code_seq, size, stdout)

#define print_utf8_seq(utf8_char_code_seq) \
    fprint_utf8_seq(utf8_char_code_seq, stdout)

void putc_utf8(uint32_t utf8_char_code, FILE *stream);

void fprint_utf8_seq_n(uint32_t *utf8_char_code_seq, size_t size, FILE *stream);

void fprint_utf8_seq(uint32_t *utf8_char_code_seq, FILE *stream);

#endif

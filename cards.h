#ifndef CARDS_H
#define CARDS_H 1

#include "utf8.h"

#define MAX_CARD_ANSWER_LEN 5
#define MAX_CARD_SEQ_LEN 3

struct card {
    uint32_t utf8_seq[MAX_CARD_SEQ_LEN];
    char answer[MAX_CARD_ANSWER_LEN];
};

struct stack {
    size_t size;
    struct card cards[5];
};

enum katakana_index {
    katakana_index_a,
    katakana_index_ha,
    katakana_index_ka,
    katakana_index_ma,
    katakana_index_sa,
    katakana_index_ya,
    katakana_index_ta,
    katakana_index_ra,
    katakana_index_na,
    katakana_index_wa,
    katakana_index_ga,
    katakana_index_za,
    katakana_index_da,
    katakana_index_ba,
    katakana_index_pa,
    katakana_index_combined_ky,
    katakana_index_combined_gy,
    katakana_index_combined_hy,
    katakana_index_combined_by,
    katakana_index_combined_py,
    katakana_index_combined_shy,
    katakana_index_combined_jy,
    katakana_index_combined_my,
    katakana_index_combined_chy,
    katakana_index_combined_dzy,
    katakana_index_combined_ry,
    katakana_index_combined_ny,
};


enum hiragana_index {
    hiragana_index_a,
    hiragana_index_ha,
    hiragana_index_ka,
    hiragana_index_ma,
    hiragana_index_sa,
    hiragana_index_ya,
    hiragana_index_ta,
    hiragana_index_ra,
    hiragana_index_na,
    hiragana_index_wa,
    hiragana_index_ga,
    hiragana_index_za,
    hiragana_index_da,
    hiragana_index_ba,
    hiragana_index_pa,
    hiragana_index_combined_ky,
    hiragana_index_combined_gy,
    hiragana_index_combined_hy,
    hiragana_index_combined_by,
    hiragana_index_combined_py,
    hiragana_index_combined_shy,
    hiragana_index_combined_jy,
    hiragana_index_combined_my,
    hiragana_index_combined_chy,
    hiragana_index_combined_dzy,
    hiragana_index_combined_ry,
    hiragana_index_combined_ny,
};


#endif

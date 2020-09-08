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
    struct card cards[];
};

enum katagana_index {
    katagana_index_a,
    katagana_index_ha,
    katagana_index_ka,
    katagana_index_ma,
    katagana_index_sa,
    katagana_index_ya,
    katagana_index_ta,
    katagana_index_ra,
    katagana_index_na,
    katagana_index_wa,
    katagana_index_ga,
    katagana_index_za,
    katagana_index_da,
    katagana_index_ba,
    katagana_index_pa,
    katagana_index_combined_ky,
    katagana_index_combined_gy,
    katagana_index_combined_hy,
    katagana_index_combined_by,
    katagana_index_combined_py,
    katagana_index_combined_shy,
    katagana_index_combined_jy,
    katagana_index_combined_my,
    katagana_index_combined_chy,
    katagana_index_combined_dzy,
    katagana_index_combined_ry,
    katagana_index_combined_ny,
};

static struct stack katagana_a = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30a2,0}, .answer = "a"},
        {.utf8_seq = {0x30a4,0}, .answer = "i"},
        {.utf8_seq = {0x30a6,0}, .answer = "u"},
        {.utf8_seq = {0x30a8,0}, .answer = "e"},
        {.utf8_seq = {0x30aa,0}, .answer = "o"}
    }
};

static struct stack katagana_ha = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30cf,0}, .answer = "ha"},
        {.utf8_seq = {0x30d2,0}, .answer = "hi"},
        {.utf8_seq = {0x30d5,0}, .answer = "fu"},
        {.utf8_seq = {0x30d8,0}, .answer = "he"},
        {.utf8_seq = {0x30db,0}, .answer = "ho"}
    }
};

static struct stack katagana_ka = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30ab,0}, .answer = "ka"},
        {.utf8_seq = {0x30ad,0}, .answer = "ki"},
        {.utf8_seq = {0x30af,0}, .answer = "ku"},
        {.utf8_seq = {0x30b1,0}, .answer = "ke"},
        {.utf8_seq = {0x30b3,0}, .answer = "ko"}
    }
};

static struct stack katagana_ma = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30de,0}, .answer = "ma"},
        {.utf8_seq = {0x30df,0}, .answer = "mi"},
        {.utf8_seq = {0x30e0,0}, .answer = "mu"},
        {.utf8_seq = {0x30e1,0}, .answer = "me"},
        {.utf8_seq = {0x30e2,0}, .answer = "mo"}
    }
};

static struct stack katagana_sa = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30b5,0}, .answer = "sa"},
        {.utf8_seq = {0x30b7,0}, .answer = "shi"},
        {.utf8_seq = {0x30b9,0}, .answer = "su"},
        {.utf8_seq = {0x30bb,0}, .answer = "se"},
        {.utf8_seq = {0x30bd,0}, .answer = "so"}
    }
};

static struct stack katagana_ya = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30e4,0}, .answer = "ya"},
        {.utf8_seq = {0x30e6,0}, .answer = "yu"},
        {.utf8_seq = {0x30e8,0}, .answer = "yo"}
    }
};

static struct stack katagana_ta = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30bf,0}, .answer = "ta"},
        {.utf8_seq = {0x30c1,0}, .answer = "chi"},
        {.utf8_seq = {0x30c4,0}, .answer = "tsu"},
        {.utf8_seq = {0x30c6,0}, .answer = "te"},
        {.utf8_seq = {0x30c8,0}, .answer = "to"}
    }
};

static struct stack katagana_ra = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30e9,0}, .answer = "ra"},
        {.utf8_seq = {0x30ea,0}, .answer = "ri"},
        {.utf8_seq = {0x30eb,0}, .answer = "ru"},
        {.utf8_seq = {0x30ec,0}, .answer = "re"},
        {.utf8_seq = {0x30ed,0}, .answer = "ro"}
    }
};

static struct stack katagana_na = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30ca,0}, .answer = "na"},
        {.utf8_seq = {0x30cb,0}, .answer = "ni"},
        {.utf8_seq = {0x30cc,0}, .answer = "nu"},
        {.utf8_seq = {0x30cd,0}, .answer = "ne"},
        {.utf8_seq = {0x30ce,0}, .answer = "no"}
    }
};

static struct stack katagana_wa = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ef,0}, .answer = "wa"},
        {.utf8_seq = {0x30f2,0}, .answer = "wo"},
        {.utf8_seq = {0x30f3,0}, .answer = "n"}
    }
};

static struct stack katagana_ga = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30ac,0}, .answer = "ga"},
        {.utf8_seq = {0x30ae,0}, .answer = "gi"},
        {.utf8_seq = {0x30b0,0}, .answer = "gu"},
        {.utf8_seq = {0x30b2,0}, .answer = "ge"},
        {.utf8_seq = {0x30b4,0}, .answer = "go"},
    }
};

static struct stack katagana_za = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30b6,0}, .answer = "za"},
        {.utf8_seq = {0x30b8,0}, .answer = "ji"},
        {.utf8_seq = {0x30ba,0}, .answer = "zu"},
        {.utf8_seq = {0x30bc,0}, .answer = "ze"},
        {.utf8_seq = {0x30be,0}, .answer = "zo"},
    }
};

static struct stack katagana_da = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30c0,0}, .answer = "da"},
        {.utf8_seq = {0x30c2,0}, .answer = "dzi"},
        {.utf8_seq = {0x30c5,0}, .answer = "dzu"},
        {.utf8_seq = {0x30c7,0}, .answer = "de"},
        {.utf8_seq = {0x30c9,0}, .answer = "do"},
    }
};

static struct stack katagana_ba = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30d0,0}, .answer = "ba"},
        {.utf8_seq = {0x30d3,0}, .answer = "bi"},
        {.utf8_seq = {0x30d6,0}, .answer = "bu"},
        {.utf8_seq = {0x30d9,0}, .answer = "be"},
        {.utf8_seq = {0x30dc,0}, .answer = "bo"},
    }
};

static struct stack katagana_pa = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30d1,0}, .answer = "pa"},
        {.utf8_seq = {0x30d4,0}, .answer = "pi"},
        {.utf8_seq = {0x30d7,0}, .answer = "pu"},
        {.utf8_seq = {0x30da,0}, .answer = "pe"},
        {.utf8_seq = {0x30dd,0}, .answer = "po"},
    }
};

static struct stack katagana_combined_ky = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ad, 0x30e3,0}, .answer = "kya"},
        {.utf8_seq = {0x30ad, 0x30e5,0}, .answer = "kyu"},
        {.utf8_seq = {0x30ad, 0x30e7,0}, .answer = "kyo"},
    }
};

static struct stack katagana_combined_gy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ae, 0x30e3,0}, .answer = "gya"},
        {.utf8_seq = {0x30ae, 0x30e5,0}, .answer = "gyu"},
        {.utf8_seq = {0x30ae, 0x30e7,0}, .answer = "gyo"},
    }
};

static struct stack katagana_combined_hy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30d2, 0x30e3,0}, .answer = "hya"},
        {.utf8_seq = {0x30d2, 0x30e5,0}, .answer = "hyu"},
        {.utf8_seq = {0x30d2, 0x30e7,0}, .answer = "hyo"},
    }
};

static struct stack katagana_combined_by = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30d3, 0x30e3,0}, .answer = "bya"},
        {.utf8_seq = {0x30d3, 0x30e5,0}, .answer = "byu"},
        {.utf8_seq = {0x30d3, 0x30e7,0}, .answer = "byo"},
    }
};

static struct stack katagana_combined_py = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30d4, 0x30e3,0}, .answer = "pya"},
        {.utf8_seq = {0x30d4, 0x30e5,0}, .answer = "pyu"},
        {.utf8_seq = {0x30d4, 0x30e7,0}, .answer = "pyo"},
    }
};

static struct stack katagana_combined_shy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30b7, 0x30e3,0}, .answer = "sha"},
        {.utf8_seq = {0x30b7, 0x30e5,0}, .answer = "shu"},
        {.utf8_seq = {0x30b7, 0x30e7,0}, .answer = "sho"},
    }
};

static struct stack katagana_combined_jy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30b8, 0x30e3,0}, .answer = "ja"},
        {.utf8_seq = {0x30b8, 0x30e5,0}, .answer = "ju"},
        {.utf8_seq = {0x30b8, 0x30e7,0}, .answer = "jo"},
    }
};

static struct stack katagana_combined_my = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30df, 0x30e3,0}, .answer = "mya"},
        {.utf8_seq = {0x30df, 0x30e5,0}, .answer = "myu"},
        {.utf8_seq = {0x30df, 0x30e7,0}, .answer = "myo"},
    }
};

static struct stack katagana_combined_chy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30c1, 0x30e3,0}, .answer = "cha"},
        {.utf8_seq = {0x30c1, 0x30e5,0}, .answer = "chu"},
        {.utf8_seq = {0x30c1, 0x30e7,0}, .answer = "cho"},
    }
};

static struct stack katagana_combined_dzy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30c2, 0x30e3,0}, .answer = "dja"},
        {.utf8_seq = {0x30c2, 0x30e5,0}, .answer = "dju"},
        {.utf8_seq = {0x30c2, 0x30e7,0}, .answer = "djo"},
    }
};

static struct stack katagana_combined_ry = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ea, 0x30e3,0}, .answer = "rya"},
        {.utf8_seq = {0x30ea, 0x30e5,0}, .answer = "ryu"},
        {.utf8_seq = {0x30ea, 0x30e7,0}, .answer = "ryo"},
    }
};

static struct stack katagana_combined_ny = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30cb, 0x30e3,0}, .answer = "nya"},
        {.utf8_seq = {0x30cb, 0x30e5,0}, .answer = "nyu"},
        {.utf8_seq = {0x30cb, 0x30e7,0}, .answer = "nyo"},
    }
};

struct stack *katagana_stacks[] = {
    /* base */
    &katagana_a, &katagana_ha,
    &katagana_ka, &katagana_ma,
    &katagana_sa, &katagana_ya,
    &katagana_ta, &katagana_ra,
    &katagana_na, &katagana_wa,
    /* dakuten/handakuten */
    &katagana_ga, &katagana_za,
    &katagana_da, &katagana_ba,
    &katagana_pa,
    /* combined */
    &katagana_combined_ky,
    &katagana_combined_gy,
    &katagana_combined_hy,
    &katagana_combined_by,
    &katagana_combined_py,
    &katagana_combined_shy,
    &katagana_combined_jy,
    &katagana_combined_my,
    &katagana_combined_chy,
    &katagana_combined_dzy,
    &katagana_combined_ry,
    &katagana_combined_ny,
};
#endif

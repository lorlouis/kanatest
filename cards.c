#include "cards.h"

static struct stack katakana_a = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30a2,0}, .answer = "a"},
        {.utf8_seq = {0x30a4,0}, .answer = "i"},
        {.utf8_seq = {0x30a6,0}, .answer = "u"},
        {.utf8_seq = {0x30a8,0}, .answer = "e"},
        {.utf8_seq = {0x30aa,0}, .answer = "o"}
    }
};

static struct stack katakana_ha = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30cf,0}, .answer = "ha"},
        {.utf8_seq = {0x30d2,0}, .answer = "hi"},
        {.utf8_seq = {0x30d5,0}, .answer = "fu"},
        {.utf8_seq = {0x30d8,0}, .answer = "he"},
        {.utf8_seq = {0x30db,0}, .answer = "ho"}
    }
};

static struct stack katakana_ka = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30ab,0}, .answer = "ka"},
        {.utf8_seq = {0x30ad,0}, .answer = "ki"},
        {.utf8_seq = {0x30af,0}, .answer = "ku"},
        {.utf8_seq = {0x30b1,0}, .answer = "ke"},
        {.utf8_seq = {0x30b3,0}, .answer = "ko"}
    }
};

static struct stack katakana_ma = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30de,0}, .answer = "ma"},
        {.utf8_seq = {0x30df,0}, .answer = "mi"},
        {.utf8_seq = {0x30e0,0}, .answer = "mu"},
        {.utf8_seq = {0x30e1,0}, .answer = "me"},
        {.utf8_seq = {0x30e2,0}, .answer = "mo"}
    }
};

static struct stack katakana_sa = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30b5,0}, .answer = "sa"},
        {.utf8_seq = {0x30b7,0}, .answer = "shi"},
        {.utf8_seq = {0x30b9,0}, .answer = "su"},
        {.utf8_seq = {0x30bb,0}, .answer = "se"},
        {.utf8_seq = {0x30bd,0}, .answer = "so"}
    }
};

static struct stack katakana_ya = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30e4,0}, .answer = "ya"},
        {.utf8_seq = {0x30e6,0}, .answer = "yu"},
        {.utf8_seq = {0x30e8,0}, .answer = "yo"}
    }
};

static struct stack katakana_ta = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30bf,0}, .answer = "ta"},
        {.utf8_seq = {0x30c1,0}, .answer = "chi"},
        {.utf8_seq = {0x30c4,0}, .answer = "tsu"},
        {.utf8_seq = {0x30c6,0}, .answer = "te"},
        {.utf8_seq = {0x30c8,0}, .answer = "to"}
    }
};

static struct stack katakana_ra = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30e9,0}, .answer = "ra"},
        {.utf8_seq = {0x30ea,0}, .answer = "ri"},
        {.utf8_seq = {0x30eb,0}, .answer = "ru"},
        {.utf8_seq = {0x30ec,0}, .answer = "re"},
        {.utf8_seq = {0x30ed,0}, .answer = "ro"}
    }
};

static struct stack katakana_na = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30ca,0}, .answer = "na"},
        {.utf8_seq = {0x30cb,0}, .answer = "ni"},
        {.utf8_seq = {0x30cc,0}, .answer = "nu"},
        {.utf8_seq = {0x30cd,0}, .answer = "ne"},
        {.utf8_seq = {0x30ce,0}, .answer = "no"}
    }
};

static struct stack katakana_wa = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ef,0}, .answer = "wa"},
        {.utf8_seq = {0x30f2,0}, .answer = "wo"},
        {.utf8_seq = {0x30f3,0}, .answer = "n"}
    }
};

static struct stack katakana_ga = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30ac,0}, .answer = "ga"},
        {.utf8_seq = {0x30ae,0}, .answer = "gi"},
        {.utf8_seq = {0x30b0,0}, .answer = "gu"},
        {.utf8_seq = {0x30b2,0}, .answer = "ge"},
        {.utf8_seq = {0x30b4,0}, .answer = "go"},
    }
};

static struct stack katakana_za = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30b6,0}, .answer = "za"},
        {.utf8_seq = {0x30b8,0}, .answer = "ji"},
        {.utf8_seq = {0x30ba,0}, .answer = "zu"},
        {.utf8_seq = {0x30bc,0}, .answer = "ze"},
        {.utf8_seq = {0x30be,0}, .answer = "zo"},
    }
};

static struct stack katakana_da = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30c0,0}, .answer = "da"},
        {.utf8_seq = {0x30c2,0}, .answer = "dzi"},
        {.utf8_seq = {0x30c5,0}, .answer = "dzu"},
        {.utf8_seq = {0x30c7,0}, .answer = "de"},
        {.utf8_seq = {0x30c9,0}, .answer = "do"},
    }
};

static struct stack katakana_ba = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30d0,0}, .answer = "ba"},
        {.utf8_seq = {0x30d3,0}, .answer = "bi"},
        {.utf8_seq = {0x30d6,0}, .answer = "bu"},
        {.utf8_seq = {0x30d9,0}, .answer = "be"},
        {.utf8_seq = {0x30dc,0}, .answer = "bo"},
    }
};

static struct stack katakana_pa = {
    .size = 5, .cards = {
        {.utf8_seq = {0x30d1,0}, .answer = "pa"},
        {.utf8_seq = {0x30d4,0}, .answer = "pi"},
        {.utf8_seq = {0x30d7,0}, .answer = "pu"},
        {.utf8_seq = {0x30da,0}, .answer = "pe"},
        {.utf8_seq = {0x30dd,0}, .answer = "po"},
    }
};

static struct stack katakana_combined_ky = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ad, 0x30e3,0}, .answer = "kya"},
        {.utf8_seq = {0x30ad, 0x30e5,0}, .answer = "kyu"},
        {.utf8_seq = {0x30ad, 0x30e7,0}, .answer = "kyo"},
    }
};

static struct stack katakana_combined_gy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ae, 0x30e3,0}, .answer = "gya"},
        {.utf8_seq = {0x30ae, 0x30e5,0}, .answer = "gyu"},
        {.utf8_seq = {0x30ae, 0x30e7,0}, .answer = "gyo"},
    }
};

static struct stack katakana_combined_hy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30d2, 0x30e3,0}, .answer = "hya"},
        {.utf8_seq = {0x30d2, 0x30e5,0}, .answer = "hyu"},
        {.utf8_seq = {0x30d2, 0x30e7,0}, .answer = "hyo"},
    }
};

static struct stack katakana_combined_by = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30d3, 0x30e3,0}, .answer = "bya"},
        {.utf8_seq = {0x30d3, 0x30e5,0}, .answer = "byu"},
        {.utf8_seq = {0x30d3, 0x30e7,0}, .answer = "byo"},
    }
};

static struct stack katakana_combined_py = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30d4, 0x30e3,0}, .answer = "pya"},
        {.utf8_seq = {0x30d4, 0x30e5,0}, .answer = "pyu"},
        {.utf8_seq = {0x30d4, 0x30e7,0}, .answer = "pyo"},
    }
};

static struct stack katakana_combined_shy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30b7, 0x30e3,0}, .answer = "sha"},
        {.utf8_seq = {0x30b7, 0x30e5,0}, .answer = "shu"},
        {.utf8_seq = {0x30b7, 0x30e7,0}, .answer = "sho"},
    }
};

static struct stack katakana_combined_jy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30b8, 0x30e3,0}, .answer = "ja"},
        {.utf8_seq = {0x30b8, 0x30e5,0}, .answer = "ju"},
        {.utf8_seq = {0x30b8, 0x30e7,0}, .answer = "jo"},
    }
};

static struct stack katakana_combined_my = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30df, 0x30e3,0}, .answer = "mya"},
        {.utf8_seq = {0x30df, 0x30e5,0}, .answer = "myu"},
        {.utf8_seq = {0x30df, 0x30e7,0}, .answer = "myo"},
    }
};

static struct stack katakana_combined_chy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30c1, 0x30e3,0}, .answer = "cha"},
        {.utf8_seq = {0x30c1, 0x30e5,0}, .answer = "chu"},
        {.utf8_seq = {0x30c1, 0x30e7,0}, .answer = "cho"},
    }
};

static struct stack katakana_combined_dzy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30c2, 0x30e3,0}, .answer = "dja"},
        {.utf8_seq = {0x30c2, 0x30e5,0}, .answer = "dju"},
        {.utf8_seq = {0x30c2, 0x30e7,0}, .answer = "djo"},
    }
};

static struct stack katakana_combined_ry = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30ea, 0x30e3,0}, .answer = "rya"},
        {.utf8_seq = {0x30ea, 0x30e5,0}, .answer = "ryu"},
        {.utf8_seq = {0x30ea, 0x30e7,0}, .answer = "ryo"},
    }
};

static struct stack katakana_combined_ny = {
    .size = 3, .cards = {
        {.utf8_seq = {0x30cb, 0x30e3,0}, .answer = "nya"},
        {.utf8_seq = {0x30cb, 0x30e5,0}, .answer = "nyu"},
        {.utf8_seq = {0x30cb, 0x30e7,0}, .answer = "nyo"},
    }
};

struct stack *katakana_stacks[] = {
    /* base */
    &katakana_a, &katakana_ha,
    &katakana_ka, &katakana_ma,
    &katakana_sa, &katakana_ya,
    &katakana_ta, &katakana_ra,
    &katakana_na, &katakana_wa,
    /* dakuten/handakute */
    &katakana_ga, &katakana_za,
    &katakana_da, &katakana_ba,
    &katakana_pa,
    /* combined */
    &katakana_combined_ky,
    &katakana_combined_gy,
    &katakana_combined_hy,
    &katakana_combined_by,
    &katakana_combined_py,
    &katakana_combined_shy,
    &katakana_combined_jy,
    &katakana_combined_my,
    &katakana_combined_chy,
    &katakana_combined_dzy,
    &katakana_combined_ry,
    &katakana_combined_ny,
};

static struct stack hiragana_a = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3042,0}, .answer = "a"},
        {.utf8_seq = {0x3044,0}, .answer = "i"},
        {.utf8_seq = {0x3046,0}, .answer = "u"},
        {.utf8_seq = {0x3048,0}, .answer = "e"},
        {.utf8_seq = {0x304a,0}, .answer = "o"}
    }
};

static struct stack hiragana_ha = {
    .size = 5, .cards = {
        {.utf8_seq = {0x306f,0}, .answer = "ha"},
        {.utf8_seq = {0x3072,0}, .answer = "hi"},
        {.utf8_seq = {0x3075,0}, .answer = "fu"},
        {.utf8_seq = {0x3078,0}, .answer = "he"},
        {.utf8_seq = {0x307b,0}, .answer = "ho"}
    }
};

static struct stack hiragana_ka = {
    .size = 5, .cards = {
        {.utf8_seq = {0x304b,0}, .answer = "ka"},
        {.utf8_seq = {0x304d,0}, .answer = "ki"},
        {.utf8_seq = {0x304f,0}, .answer = "ku"},
        {.utf8_seq = {0x3051,0}, .answer = "ke"},
        {.utf8_seq = {0x3053,0}, .answer = "ko"}
    }
};

static struct stack hiragana_ma = {
    .size = 5, .cards = {
        {.utf8_seq = {0x307e,0}, .answer = "ma"},
        {.utf8_seq = {0x307f,0}, .answer = "mi"},
        {.utf8_seq = {0x3080,0}, .answer = "mu"},
        {.utf8_seq = {0x3081,0}, .answer = "me"},
        {.utf8_seq = {0x3082,0}, .answer = "mo"}
    }
};

static struct stack hiragana_sa = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3055,0}, .answer = "sa"},
        {.utf8_seq = {0x3057,0}, .answer = "shi"},
        {.utf8_seq = {0x3059,0}, .answer = "su"},
        {.utf8_seq = {0x305b,0}, .answer = "se"},
        {.utf8_seq = {0x305d,0}, .answer = "so"}
    }
};

static struct stack hiragana_ya = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3084,0}, .answer = "ya"},
        {.utf8_seq = {0x3086,0}, .answer = "yu"},
        {.utf8_seq = {0x3088,0}, .answer = "yo"}
    }
};

static struct stack hiragana_ta = {
    .size = 5, .cards = {
        {.utf8_seq = {0x305f,0}, .answer = "ta"},
        {.utf8_seq = {0x3061,0}, .answer = "chi"},
        {.utf8_seq = {0x3064,0}, .answer = "tsu"},
        {.utf8_seq = {0x3066,0}, .answer = "te"},
        {.utf8_seq = {0x3068,0}, .answer = "to"}
    }
};

static struct stack hiragana_ra = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3089,0}, .answer = "ra"},
        {.utf8_seq = {0x308a,0}, .answer = "ri"},
        {.utf8_seq = {0x308b,0}, .answer = "ru"},
        {.utf8_seq = {0x308c,0}, .answer = "re"},
        {.utf8_seq = {0x308d,0}, .answer = "ro"}
    }
};

static struct stack hiragana_na = {
    .size = 5, .cards = {
        {.utf8_seq = {0x306a,0}, .answer = "na"},
        {.utf8_seq = {0x306b,0}, .answer = "ni"},
        {.utf8_seq = {0x306c,0}, .answer = "nu"},
        {.utf8_seq = {0x306d,0}, .answer = "ne"},
        {.utf8_seq = {0x306e,0}, .answer = "no"}
    }
};

static struct stack hiragana_wa = {
    .size = 3, .cards = {
        {.utf8_seq = {0x308f,0}, .answer = "wa"},
        {.utf8_seq = {0x3092,0}, .answer = "wo"},
        {.utf8_seq = {0x3093,0}, .answer = "n"}
    }
};

static struct stack hiragana_ga = {
    .size = 5, .cards = {
        {.utf8_seq = {0x304c,0}, .answer = "ga"},
        {.utf8_seq = {0x304e,0}, .answer = "gi"},
        {.utf8_seq = {0x3050,0}, .answer = "gu"},
        {.utf8_seq = {0x3052,0}, .answer = "ge"},
        {.utf8_seq = {0x3054,0}, .answer = "go"},
    }
};

static struct stack hiragana_za = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3056,0}, .answer = "za"},
        {.utf8_seq = {0x3058,0}, .answer = "ji"},
        {.utf8_seq = {0x305a,0}, .answer = "zu"},
        {.utf8_seq = {0x305c,0}, .answer = "ze"},
        {.utf8_seq = {0x305e,0}, .answer = "zo"},
    }
};

static struct stack hiragana_da = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3060,0}, .answer = "da"},
        {.utf8_seq = {0x3062,0}, .answer = "dzi"},
        {.utf8_seq = {0x3065,0}, .answer = "dzu"},
        {.utf8_seq = {0x3067,0}, .answer = "de"},
        {.utf8_seq = {0x3069,0}, .answer = "do"},
    }
};

static struct stack hiragana_ba = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3070,0}, .answer = "ba"},
        {.utf8_seq = {0x3073,0}, .answer = "bi"},
        {.utf8_seq = {0x3076,0}, .answer = "bu"},
        {.utf8_seq = {0x3079,0}, .answer = "be"},
        {.utf8_seq = {0x307c,0}, .answer = "bo"},
    }
};

static struct stack hiragana_pa = {
    .size = 5, .cards = {
        {.utf8_seq = {0x3071,0}, .answer = "pa"},
        {.utf8_seq = {0x3074,0}, .answer = "pi"},
        {.utf8_seq = {0x3077,0}, .answer = "pu"},
        {.utf8_seq = {0x307a,0}, .answer = "pe"},
        {.utf8_seq = {0x307d,0}, .answer = "po"},
    }
};

static struct stack hiragana_combined_ky = {
    .size = 3, .cards = {
        {.utf8_seq = {0x304d, 0x30e3,0}, .answer = "kya"},
        {.utf8_seq = {0x304d, 0x30e5,0}, .answer = "kyu"},
        {.utf8_seq = {0x304d, 0x30e7,0}, .answer = "kyo"},
    }
};

static struct stack hiragana_combined_gy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x304e, 0x30e3,0}, .answer = "gya"},
        {.utf8_seq = {0x304e, 0x30e5,0}, .answer = "gyu"},
        {.utf8_seq = {0x304e, 0x30e7,0}, .answer = "gyo"},
    }
};

static struct stack hiragana_combined_hy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3072, 0x30e3,0}, .answer = "hya"},
        {.utf8_seq = {0x3072, 0x30e5,0}, .answer = "hyu"},
        {.utf8_seq = {0x3072, 0x30e7,0}, .answer = "hyo"},
    }
};

static struct stack hiragana_combined_by = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3073, 0x30e3,0}, .answer = "bya"},
        {.utf8_seq = {0x3073, 0x30e5,0}, .answer = "byu"},
        {.utf8_seq = {0x3073, 0x30e7,0}, .answer = "byo"},
    }
};

static struct stack hiragana_combined_py = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3074, 0x30e3,0}, .answer = "pya"},
        {.utf8_seq = {0x3074, 0x30e5,0}, .answer = "pyu"},
        {.utf8_seq = {0x3074, 0x30e7,0}, .answer = "pyo"},
    }
};

static struct stack hiragana_combined_shy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3057, 0x30e3,0}, .answer = "sha"},
        {.utf8_seq = {0x3057, 0x30e5,0}, .answer = "shu"},
        {.utf8_seq = {0x3057, 0x30e7,0}, .answer = "sho"},
    }
};

static struct stack hiragana_combined_jy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3058, 0x30e3,0}, .answer = "ja"},
        {.utf8_seq = {0x3058, 0x30e5,0}, .answer = "ju"},
        {.utf8_seq = {0x3058, 0x30e7,0}, .answer = "jo"},
    }
};

static struct stack hiragana_combined_my = {
    .size = 3, .cards = {
        {.utf8_seq = {0x307f, 0x30e3,0}, .answer = "mya"},
        {.utf8_seq = {0x307f, 0x30e5,0}, .answer = "myu"},
        {.utf8_seq = {0x307f, 0x30e7,0}, .answer = "myo"},
    }
};

static struct stack hiragana_combined_chy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3061, 0x30e3,0}, .answer = "cha"},
        {.utf8_seq = {0x3061, 0x30e5,0}, .answer = "chu"},
        {.utf8_seq = {0x3061, 0x30e7,0}, .answer = "cho"},
    }
};

static struct stack hiragana_combined_dzy = {
    .size = 3, .cards = {
        {.utf8_seq = {0x3062, 0x30e3,0}, .answer = "dja"},
        {.utf8_seq = {0x3062, 0x30e5,0}, .answer = "dju"},
        {.utf8_seq = {0x3062, 0x30e7,0}, .answer = "djo"},
    }
};

static struct stack hiragana_combined_ry = {
    .size = 3, .cards = {
        {.utf8_seq = {0x308a, 0x30e3,0}, .answer = "rya"},
        {.utf8_seq = {0x308a, 0x30e5,0}, .answer = "ryu"},
        {.utf8_seq = {0x308a, 0x30e7,0}, .answer = "ryo"},
    }
};

static struct stack hiragana_combined_ny = {
    .size = 3, .cards = {
        {.utf8_seq = {0x306b, 0x30e3,0}, .answer = "nya"},
        {.utf8_seq = {0x306b, 0x30e5,0}, .answer = "nyu"},
        {.utf8_seq = {0x306b, 0x30e7,0}, .answer = "nyo"},
    }
};

struct stack *hiragana_stacks[] = {
    /* base */
    &hiragana_a, &hiragana_ha,
    &hiragana_ka, &hiragana_ma,
    &hiragana_sa, &hiragana_ya,
    &hiragana_ta, &hiragana_ra,
    &hiragana_na, &hiragana_wa,
    /* dakuten/handakuten */
    &hiragana_ga, &hiragana_za,
    &hiragana_da, &hiragana_ba,
    &hiragana_pa,
    /* combined */
    &hiragana_combined_ky,
    &hiragana_combined_gy,
    &hiragana_combined_hy,
    &hiragana_combined_by,
    &hiragana_combined_py,
    &hiragana_combined_shy,
    &hiragana_combined_jy,
    &hiragana_combined_my,
    &hiragana_combined_chy,
    &hiragana_combined_dzy,
    &hiragana_combined_ry,
    &hiragana_combined_ny,
};

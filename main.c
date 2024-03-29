#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#include "utf8.h"
#include "utils.h"

#include "cards.h"

/* defined in cards.c */
extern struct stack *hiragana_stacks[];
extern struct stack *katakana_stacks[];

struct stack_ptr_to_cards{
    int size;
    struct card *cards[117];
};

struct kana_flags{
    unsigned int voiced : 1;
    unsigned int combined : 1;
    unsigned int base : 1;
    unsigned hiragana_mode: 1;
    unsigned int a : 1;
    unsigned int h : 1;
    unsigned int k : 1;
    unsigned int m : 1;
    unsigned int s : 1;
    unsigned int y : 1;
    unsigned int t : 1;
    unsigned int r : 1;
    unsigned int n : 1;
    unsigned int w : 1;
};

void add_stack_to_main_stack(
        struct stack_ptr_to_cards *main_stack,
        struct stack *(*sub_stacks)[],
        int index) {
    for(int i = 0; i<(int)(*sub_stacks)[index]->size; i++) {
        main_stack->cards[main_stack->size++] = &((*sub_stacks)[index]->cards[i]);
    }
}

/* requires srand to be init */
void scramble_array(void **array, size_t size) {
    int pos1, pos2;
    struct card *tmp;
    for(size_t i = 0; i < size * 3; i++) {
        pos1 = rand() % size;
        pos2 = rand() % size;
        tmp = array[pos1];
        array[pos1] = array[pos2];
        array[pos2] = tmp;
    }
}

int load_kana(
        struct stack_ptr_to_cards *main_stack,
        char* kana_groups,
        struct stack *(*load_stacks)[],
        struct kana_flags *flags) {
    while(*kana_groups) {
        switch(*kana_groups) {
            case('a'):
                /* make sure to only load a group once */
                if(flags->a == 0) {
                    flags->a = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_a);
                }
                break;

            case('h'):
                /* make sure to only load a group once */
                if(flags->h == 0) {
                    flags->h = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_ha);
                    /* load this group's voiced if specified */
                    if(flags->voiced) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katakana_index_ba);
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katakana_index_pa);
                    }
                    /* load this group's combo katakana if specified */
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_hy);
                        /* load combo voiced if specified */
                        if(flags->voiced) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katakana_index_combined_by);
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katakana_index_combined_py);
                        }
                    }
                }
                break;
                /* all the code below follows
                 * the pattern established above */
            case('k'):
                if(flags->k == 0) {
                    flags->k = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_ka);
                    if(flags->voiced) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katakana_index_ga);
                    }
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_ky);
                        if(flags->voiced) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katakana_index_combined_gy);
                        }
                    }
                }
                break;

            case('m'):
                if(flags->m == 0) {
                    flags->m = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_ma);
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_my);
                    }
                }
                break;

            case('s'):
                if(flags->s == 0) {
                    flags->s = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_sa);
                    if(flags->voiced) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katakana_index_za);
                    }
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_shy);
                        if(flags->voiced) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katakana_index_combined_jy);
                        }
                    }
                }
                break;

            case('y'):
                if(flags->y == 0) {
                    flags->y = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_ya);
                }
                break;

            case('t'):
                if(flags->t == 0) {
                    flags->t = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_ta);
                    if(flags->voiced) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katakana_index_da);
                    }
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_chy);
                        if(flags->voiced) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katakana_index_combined_dzy);
                        }
                    }
                }
                break;

            case('r'):
                if(flags->r == 0) {
                    flags->r = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_ra);
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_ry);
                    }
                }
                break;

            case('n'):
                if(flags->n == 0) {
                    flags->n = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_na);
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katakana_index_combined_ny);
                    }
                }
                break;

            case('w'):
                if(flags->w == 0) {
                    flags->w = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katakana_index_wa);
                }
                break;
            default:
                return 1;
        }
        kana_groups++;
    }
    return 0;
}


int ask_user(struct card *card, FILE *stream) {
    size_t buff_size = 5 * sizeof(char);

    char *buff = malloc(buff_size);

    printf("\t");
    print_utf8_seq(card->utf8_seq);
    printf("\n");
    printf("type the associated romaji: ");
    int char_read = getline(&buff, &buff_size, stream);
    char *str = buff;
    int word_len = strlen(card->answer);

    int trimmed = strim(&str);
    int excess_char = char_read - trimmed == word_len;
    int out = !(excess_char || strncmp(str, card->answer, word_len+1));
    free(buff);
    return out;
}

/* -a -h -k -m -s -y -t -r -n -w
 * --voiced --combined
 *  if only voiced or combined only add them */
int main(int argc, char** argv) {
    int score_good=0, score_bad=0;
    struct kana_flags flags = {0};
    struct stack_ptr_to_cards main_stack = {0};
    struct stack *(*load_stacks)[] = &katakana_stacks;
    if(argc > 1 && !strcmp("--help", argv[1])) {
        printf("Usage: %s [--help | [-ahkmsytrnw] [--voiced] "
                "[--combined] [--hiragana]]\n\n"
               "launching this program without any arguments\n"
               "will add all the base katakana\n\n"
               "Groups:\n"
               "\t-a: a e i u o\n"
               "\t-h: ha he hi fu ho\n"
               "\t-k: ka ke ki ku ko\n"
               "\t-m: ma me mi mu mo\n"
               "\t-s: sa se shi su so\n"
               "\t-y: ya yu yo\n"
               "\t-t: ta te chi tu to\n"
               "\t-r: ra re ri ru ro\n"
               "\t-n: na ne ni nu no\n"
               "\t-w: wa wu wo\n"
               "--base is the same as -ahkmsytrnw\n"
               "--voiced adds each specified group's voiced\n"
               "--combined adds eache specified group's combo katakana\n"
               "--hiragana will load hiraganas instead of katakanas\n\n"
               "if --voiced or --combined are the only\n"
               "groups specified all the voiced and/or combo\n"
               "katakana will be added whithout adding the base katakana\n\n"
                , argv[0]);
        return 0;
    }
    if(argc == 1) flags.base = 1;
    /* set flags to know if we need to load more katakana */
    for(int i = 1; i<argc;i++) {
        if(!strcmp("--voiced", argv[i])) {
            flags.voiced = 1;
        }
        else if(!strcmp("--combined", argv[i])) {
            flags.combined = 1;
        }
        else if(!strcmp("--base", argv[i])) {
            flags.base = 1;
        }
        else if(!strcmp("--hiragana", argv[i])) {
            flags.hiragana_mode = 1;
            load_stacks = &hiragana_stacks;
        }
        else if(argv[i][0] == '-' && argv[i][1] == '-') {
            printf("Unrecognised parameter \"%s\"\n", argv[i]);
            return 1;
        }
    }
    /* parse the args and load the katakanas */
    while(argc-- > 1 && flags.base != 1) {
        argv++;
        if((*argv)[0] == '-' && (*argv)[1] != '-') {
            (*argv)++;
            if(load_kana(&main_stack, *argv, load_stacks, &flags)){
                printf("unrecognised group when parsing \"%s\"\n", *argv);
                return 1;
            }
        }
    }

    /* only run if no groups were specified */
    if(main_stack.size == 0 && flags.base == 0) {
        /* add all the voiced if --voiced and no group specified */
        if(flags.voiced) {
            for(int i = katakana_index_ga; i <= katakana_index_pa; i++) {
                add_stack_to_main_stack(&main_stack, load_stacks, i);
            }
        }
        /* add all combined if no groups other than --voiced were specified */
        if(flags.combined) {
            for(int i = katakana_index_combined_ky;
                    i <= katakana_index_combined_ny;
                    i++) {
                add_stack_to_main_stack(&main_stack, load_stacks, i);
            }
        }
        if(flags.hiragana_mode) flags.base = 1;
    }
    /* add the base group (will load the voiced and combined if specified) */
    if(flags.base == 1) {
        char* kanas = "ahkmsytrnw";
        load_kana(&main_stack, kanas, load_stacks, &flags);
    }

    /* init random */
    time_t t;
    srand((unsigned)time(&t));

    scramble_array((void**)main_stack.cards, main_stack.size);

    for(int i=0; i < main_stack.size; i++) {
        if(ask_user(main_stack.cards[i], stdin)) {
            printf("\033[0;32mGood\033[0m\t%d/%d\n", i+1, main_stack.size);
            score_good++;
        }
        else {
            printf("\033[0;31mWrong\033[0m\t%d/%d\nthe correct "
                   "answer is\n\"%s\"\n", i+1, main_stack.size,
                   main_stack.cards[i]->answer);
            score_bad++;
        }
        puts("-------------------------------");
    }

    printf(
        "\033[01;34m~~~~~Results~~~~~\033[0m\nCorrect:"
        "\t%d\nWrong:\t\t%d\nTotal:\t\t%d\n",
        score_good, score_bad, score_good + score_bad);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#include "utf8.h"

#include "cards.h"


struct stack_ptr_to_cards{
    int size;
    struct card *cards[117];
};

struct kana_flags{
    unsigned int dakuten : 1;
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

/* requires srand to be init'd */
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
                            main_stack, load_stacks, katagana_index_a);
                }

                break;

            case('h'):
                /* make sure to only load a group once */
                if(flags->h == 0) {
                    flags->h = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_ha);
                    /* load this group's dakuten if specified */
                    if(flags->dakuten) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katagana_index_ba);
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katagana_index_pa);
                    }
                    /* load this group's combo katagana if specified */
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_hy);
                        /* load combo dakuten if specified */
                        if(flags->dakuten) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katagana_index_combined_by);
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katagana_index_combined_py);
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
                            main_stack, load_stacks, katagana_index_ka);
                    if(flags->dakuten) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katagana_index_ga);
                    }
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_ky);
                        if(flags->dakuten) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katagana_index_combined_gy);
                        }
                    }
                }
                break;

            case('m'):
                if(flags->m == 0) {
                    flags->m = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_ma);
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_my);
                    }
                }
                break;

            case('s'):
                if(flags->s == 0) {
                    flags->s = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_sa);
                    if(flags->dakuten) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katagana_index_za);
                    }
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_shy);
                        if(flags->dakuten) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katagana_index_combined_jy);
                        }
                    }
                }
                break;

            case('y'):
                if(flags->y == 0) {
                    flags->y = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_ya);
                }
                break;

            case('t'):
                if(flags->t == 0) {
                    flags->t = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_ta);
                    if(flags->dakuten) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks, katagana_index_da);
                    }
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_chy);
                        if(flags->dakuten) {
                            add_stack_to_main_stack(
                                    main_stack, load_stacks,
                                    katagana_index_combined_dzy);
                        }
                    }
                }
                break;

            case('r'):
                if(flags->r == 0) {
                    flags->r = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_ra);
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_ry);
                    }
                }
                break;

            case('n'):
                if(flags->n == 0) {
                    flags->n = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_na);
                    if(flags->combined) {
                        add_stack_to_main_stack(
                                main_stack, load_stacks,
                                katagana_index_combined_ny);
                    }
                }
                break;

            case('w'):
                if(flags->w == 0) {
                    flags->w = 1;
                    add_stack_to_main_stack(
                            main_stack, load_stacks, katagana_index_wa);
                }
                break;
            default:
                return 1;
        }
        kana_groups++;
    }
    return 0;
}

int ask_user(struct card *card) {
    char buff[MAX_CARD_ANSWER_LEN];
    printf("\t");
    print_utf8_seq(card->utf8_seq);
    printf("\n");
    printf("type the associated romaji: ");
    fgets(buff, strlen(card->answer)+1, stdin);
    int too_long = 0;
    while(fgetc(stdin) != '\n') too_long=1;
    return !(too_long || strncmp(buff, card->answer, strlen(card->answer)+1));
}

/* -a -h -k -m -s -y -t -r -n -w
 * --dakuten --combined
 *  if only dakuten or combined only add them */
int main(int argc, char** argv) {
    int score_good=0, score_bad=0;
    struct kana_flags flags = {0};
    struct stack_ptr_to_cards main_stack = {0};
    struct stack *(*load_stacks)[] = &katagana_stacks;
    if(argc > 1 && !strcmp("--help", argv[1])) {
        printf("Usage: %s [--help | [-ahkmsytrnw] [--dakuten] [--combined]]\n\n"
               "launching this program without argument"
               "will add all the base katagana\n\n"
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
               "--dakuten adds each specified group's dakuten\n"
               "--combined adds eache specified group's combo katagana\n"
               "--hiragana will load hiraganas instead of kataganas\n\n"
               "if --dakuten or --combined are the only\n"
               "groups specified all the dakuten and/or combo\n"
               "katagana will be added whithout adding the base katagana\n\n"
               "note: all invalid arguments will be ignored\n"
                , argv[0]);
        return 0;
    }
    if(argc == 1) flags.base = 1;
    /* set flags to know if we need to load more katagana */
    for(int i = 1; i<argc;i++) {
        if(!strcmp("--dakuten", argv[i])) {
            flags.dakuten = 1;
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
    }
    /* parse the args and load the kataganas */
    while(argc-- > 1 && flags.base != 1) {
        argv++;
        if((*argv)[0] == '-' && (*argv)[1] != '-') {
            (*argv)++;
                load_kana(&main_stack, *argv, load_stacks, &flags);
        }
    }

    /* only run if no groups were specified */
    if(main_stack.size == 0 && flags.base == 0) {
        /* add all the dakuten if --dakuten and no group specified */
        if(flags.dakuten) {
            for(int i = katagana_index_ga; i <= katagana_index_pa; i++) {
                add_stack_to_main_stack(&main_stack, load_stacks, i);
            }
        }
        /* add all combined if no groups other than --dakuten were specified */
        if(flags.combined) {
            for(int i = katagana_index_combined_ky;
                    i <= katagana_index_combined_ny;
                    i++) {
                add_stack_to_main_stack(&main_stack, load_stacks, i);
            }
        }
        if(flags.hiragana_mode) flags.base = 1;
    }
    /* add the base group (will load the dakutens and combined if specified) */
    if(flags.base == 1) {
        char* kanas = "ahkmsytrnw";
        load_kana(&main_stack, kanas, load_stacks, &flags);
    }

    /* init random */
    time_t t;
    srand((unsigned)time(&t));

    scramble_array((void**)main_stack.cards, main_stack.size);

    for(int i=0; i < main_stack.size; i++) {
        if(ask_user(main_stack.cards[i])) {
            printf("\033[0;32mGood\033[0m\t%d/%d\n", i+1, main_stack.size);
            score_good++;
        }
        else {
            printf("\033[0;31mWrong\033[0m\t%d/%d\nthe correct "
                   "answer is\n\"%s\"\n", i+1, main_stack.size,
                   main_stack.cards[i]->answer);
            score_bad++;
        }
    }
    printf(
        "\033[01;34m~~~~~Results~~~~~\033[0m\nCorrect:"
        "\t%d\nWrong:\t\t%d\nTotal:\t\t%d\n",
        score_good, score_bad, score_good + score_bad);
    return 0;
}

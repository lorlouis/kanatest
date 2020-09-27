OBJS	= main.o utf8.o utils.o
SOURCE	= main.c utf8.c utils.c
HEADER	=
OUT	= kanatest
CC	= gcc
FLAGS	= -std=c99 -Wall -Wextra -Werror -g -c
LFLAGS	=

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

%.o: %.c
	$(CC) $(FLAGS) $^

install:
	cp $(OUT) ~/.local/bin/

uninstall:
	rm ~/.local/bin/$(OUT)

clean:
	rm -f $(OBJS) $(OUT)

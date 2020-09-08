OBJS	= main.o utf8.o
SOURCE	= main.c utf8.c
HEADER	=
OUT	= kanatest
CC	= gcc
FLAGS	= -std=c99 -Wall -Wextra -Werror -g -c
LFLAGS	=

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

%.o: %.c
	$(CC) $(FLAGS) $^

clean:
	rm -f $(OBJS) $(OUT)

CC = $(shell which gcc)
CFLAGS = -std=c99 -Wall -g
LDFLAGS += -lsndfile

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) $(LDFLAGS) $^ -o main

clean:
	rm -rf *.o main

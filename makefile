CC = gcc
CFLAGS = -Wall -Iinclude -g -std=c99 -pedantic

SRC=./src/
BIN=./bin/

board_generator.c
dictionary.c
scoreboard.c
word_checker.c
test: 
	$(CC) $(CFLAGS) $(SRC)board_generator.c  $(SRC)dictionary.c $(SRC)scoreboard.c $(SRC)word_checker.c -Iinclude $(SRC)unitTest.c -o test
clean:
	rm test

CC = gcc
CFLAGS = -Wall -g -std=c99

BIN = ./bin/
SRC = ./src/

program:
	$(CC) $(CFLAGS) $(SRC)dictionary.c $(SRC)boardGenerator.c $(SRC)boggle.c $(SRC)scoreboard.c $(SRC)wordChecker.c -Iinclude -o $(BIN)boggle

cls:
	clear

testing:
	$(CC) $(CFLAGS) $(SRC)test.c -Iinclude -o $(BIN)boggleTest

clean:
	rm $(BIN)boggle
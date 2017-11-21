CC = gcc
CFLAGS = -Wall -Iinclude -g -std=c99 -pedantic

boggle: 
	$(shell mkdir -p bin) $(CC) $(CFLAGS) -o bin/boggle src/*.c -Iinclude
clean:
	rm bin/*

CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g

# Add locations
ASSET = assets/
BINDIR = bin/
SRCDIR = src/
INCLUDE = include/
LIB = lib/

HEADERS = $(INCLUDE)dictionary.h $(INCLUDE)boardGenerator.h $(INCLUDE)wordChecker.h $(INCLUDE)scoreboard.h

all : $(BINDIR)boggle

$(BINDIR)boggle : $(BINDIR)boggle.o $(BINDIR)dictionary.o $(BINDIR)scoreboard.o $(BINDIR)wordChecker.o $(BINDIR)boardGenerator.o

$(BINDIR)boggle.o : $(SRCDIR)boggle.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCDIR)boggle.c -o $(BINDIR)boggle.o

$(BINDIR)dictionary.o : $(SRCDIR)dictionary.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCDIR)dictionary.c -o $(BINDIR)dictionary.o

$(BINDIR)scoreboard.o : $(SRCDIR)scoreboard.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCDIR)scoreboard.c -o $(BINDIR)scoreboard.o

$(BINDIR)wordChecker.o : $(SRCDIR)wordChecker.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCDIR)wordChecker.c -o $(BINDIR)wordChecker.o

$(BINDIR)boardGenerator.o : $(SRCDIR)boardGenerator.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCDIR)boardGenerator.c -o $(BINDIR)boardGenerator.o

doxy: Doxyfile
		doxygen

clean :
	rm $(BINDIR)boggle.o $(BINDIR)dictionary.o $(BINDIR)scoreboard.o $(BINDIR)wordChecker.o $(BINDIR)boardGenerator.o $(BINDIR)boggle

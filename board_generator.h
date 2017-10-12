#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


// The pre-set dice which keep their values between games.
typedef struct presetDice {
	char *configurations;
	int position;
} PresetDice;

// The rolled dice which do not keep their values between games.
typedef struct rolledDice {
	char character;
	int position;
} RolledDice;


void InitializePresetDice(PresetDice *inputArrayOfDice);
void RollButNotShuffleDice(RolledDice* gameDice, PresetDice* inputArrayOfDice);

void ShuffleRolledDicePositions(RolledDice* gameDice);
void PrintGameBoard(RolledDice** gameBoard);
void RollDice(RolledDice** gameBoard, PresetDice* inputArrayOfDice);

void ConvertToBoard(char *letters, char ***board);
void PrintHcBoard(char boggle[][4]);

#endif

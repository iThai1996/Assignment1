/**
 * @file board_generator.h
 * @author Joshua Samuels
 * @date October 2017
 * @brief File containing the struct and function definitions of boggle board generator
 */

#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


/**
 *Struct for the value of preset dice - maintained between games
 **/
typedef struct presetDice {
    char* configurations; ///< pointer to the die configurations
    int position; ///< int position of the die
} PresetDice;

/**
 *Struct for the value of the rolled dice - different between games
 **/
typedef struct rolledDice {
    char character; ///< character value of the rolled die
    int position; ///< int position of the die
} RolledDice;


/**
 *Sets the value of all the dice to their preset values
 *@param pointer that hold the preset value on each die
 **/
void InitializePresetDice(PresetDice* inputArrayOfDice);

/**
 *Rolls all the dice and stores them in the game dice in a random order. The dice do not get shuffled - helper function
 *@param pointer to the game dice
 *@param pointer that hold the preset value on each die
 **/
void RollButNotShuffleDice(RolledDice* gameDice, PresetDice* inputArrayOfDice);

/**
 *Shuffles the positions of the dice that were rolled - helper function
 *@param pointer to the game dice
 **/
void ShuffleRolledDicePositions(RolledDice* gameDice);

/**
 *Prints the gameboard - a visual representation of the 2D rolled dice array
 *@param 2D pointer to the game board
 **/
void PrintGameBoard(RolledDice** gameBoard);

/**
 *Used to roll and shuffle the game dice. The dice are then put in the gameBoard array
 *@param 2D pointer to the game board
 *@param pointer that hold the preset value on each die
 **/
void RollDice(RolledDice** gameBoard, PresetDice* inputArrayOfDice);

/**
 *Converts the board from a string to a 2D array, used for testing
 *@param string containing the letters for the board
 *@param 2D pointer array that holds the board
 **/
void ConvertToBoard(char* letters, char*** board);

/**
 *Prints the 4x4 boggle board
 *@param 2D array that holds the 4x4 board
 **/
void PrintHcBoard(char boggle[][4]);

#endif

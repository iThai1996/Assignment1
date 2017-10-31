#include <string.h>
#include "board_generator.h"
#include <stdlib.h>

/**Verifies a word is on the game board
 *@pre      The gameBoard must be accurate and the word needs to be 4 letters long.
 *@return   1 or 0, 1 indicates the word was on the board, 0 indicates it wasnt.
 *@param    The gameboard
 *@param   The word the user wants to verify
 **/
int wordChecker(RolledDice **gameBoard, char* word);

/**Goes through letters on the board to verify a word, building the word on the board one position at a time
 *@pre      This function is called through wordChecker and needs it to function.
 *@post     This function is recursive and repeats as it builds the word on the board, letter by letter.
 *@return   1 or 0, 1 indicates the word was on the board, 0 indicates it wasnt.
 *@param    i and 
 *@param    j are the coordinate to search from,
 *@param    The word to search through,
 *@param    The board, an int to track how much of the word is left,
 *@param    Array of already used letters.
 **/
int abidesRules(int i, int j, char* word, RolledDice** gameBoard, int subLen, int** visited);

/**Function to get a letter on the boggle board
 *@pre      The coorinate of i and j must be a real value that exsists on the board.
 *@return   A char value, representing a letter on the boggle board
 *@param    i is an x cooridinate, 
 *@param    j is the y coordinate,
 *@param    **rolled reps the boggleBoard
 **/
char getLetter(int i, int j, RolledDice** gameBoard);

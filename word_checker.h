#include <string.h>
#include "board_generator.h"
#include <stdlib.h>

/**Verifies a word is on the game board
 *@pre      The gameBoard must be accurate and the word needs to be 4 letters long.
 *@return   1 or 0, 1 indicates the word was on the board, 0 indicates it wasnt.
 *@param    The gameboard
 *@param   The word the user wants to verify
 **/
int wordChecker(struct rolledDice **gameBoard, char *word);

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
int abidesRules(int i, int j, char *word, struct rolledDice** gameBoard, int subLen, int **visited);

/**Function to get a letter on the boggle board
 *@pre      The coorinate of i and j must be a real value that exsists on the board.
 *@return   A char value, representing a letter on the boggle board
 *@param    i is an x cooridinate, 
 *@param    j is the y coordinate,
 *@param    **rolled reps the boggleBoard
 **/
char getLetter(int i, int j, struct rolledDice **gameBoard);

/**test
 * this code has minor semantic difference but major functional issues
 * It seems to go through the letters two at a time instead of once*/

/**Verifies a word is on the game board
 *@pre      The gameBoard must be accurate and the word needs to be 4 letters long.
 *@return   1 or 0, 1 indicates the word was on the board, 0 indicates it wasnt.
 *@param    The gameboard
 *@param   The word the user wants to verify
 **/

int testWordChecker(char **boggle, char *word);
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
int testAbidesRules(int i, int j, char *word, char **gameBoard, int subLen, int **visited);

/**Function to get a letter on the boggle board
 *@pre      The coorinate of i and j must be a real value that exsists on the board.
 *@return   A char value, representing a letter on the boggle board
 *@param    i is an x cooridinate,
 *@param    j is the y coordinate,
 *@param    **char reps the boggle
 **/
char testGetLetter(int i, int j, char **boggle);

/**hc This code uses boogle[][4] which will not work inside the functions and the declaration is off. 
 * It seems that a value is meant to go inside the */

/**Verifies a word is on the game board
 *@pre      The gameBoard must be accurate and the word needs to be 4 letters long.
 *@return   1 or 0, 1 indicates the word was on the board, 0 indicates it wasnt.
 *@param    The gameboard
 *@param   The word the user wants to verify
 **/
int hcWordChecker(char boggle[][4], char *word);

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
int hcAbidesRules(int i, int j, char *word, char boggle[][4], int subLen, int **visited);

/**Function to get a letter on the boggle board
 *@pre      The coorinate of i and j must be a real value that exsists on the board.
 *@return   A char value, representing a letter on the boggle board
 *@param    i is an x cooridinate,
 *@param    j is the y coordinate,
 *@param     **char reps the boggle
 **/
char hcGetLetter(int i, int j, char boggle[][4]);

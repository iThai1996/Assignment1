#include <stdio.h>
#include <string.h>
#include "word_checker.h"
#include <ctype.h>

char GetLetter(int i, int j, struct rolledDice **gameBoard)
{
    //Returns the letter in the gameboard
    return gameBoard[i][j].character;
    
}

//This function looks a sournding correct letter
int AbidesRules(int i, int j, char *word, struct rolledDice** gameBoard, int subLen, int **visited)
{
    int adjCell;
    char currentLetter = word[subLen];
    int ans = (subLen == (strlen(word)-1));
    
    // right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight
    int allxVariable[] = { 0, -1, -1, -1, 0, 1, 1, 1} ;
    int allyVariable[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
    
    int newX;
    int newY;
    
    char findLetter;
    
    int result = 0;
    
    findLetter = word[subLen + 1];
    
    //if the word is complete then return out
    if(subLen == (strlen(word)-1)){
        
        return 1;
        
    }
    
    //verify by checking all letters surrounding the current one
    for(adjCell = 0; adjCell < 8; adjCell++){
        
        newX = i + allxVariable[adjCell];
        newY = j + allyVariable[adjCell];
        
        //if a correct letter is found move on, if a letter cant move on then go back
        if((newX >= 0) && (newX < 4) && (newY >=0) && (newY < 4) && toupper(findLetter) == GetLetter(newX, newY, gameBoard) && !visited[newX][newY]){
            
            //mark variable as checked
            visited[newX][newY] = 1;
            
            ++subLen;
            
            //Move onto next correct letter
            result = AbidesRules(newX, newY, word, gameBoard, subLen, visited);
            
            if(result){
                
                return 1;
                
            }else{
                
                //if the word failed half way through then retry a new attempt
                --subLen;
                
            }
            
        }
        
    }
    
    //if the letter cant be found at all return 0
    return 0;
}


int WordChecker(struct rolledDice **gameBoard, char *word)
{
    
    int row, letter, col, m, n;
    int **visited;
    
    //Stores the location of the found letters
    visited = malloc(sizeof(int * ) * 4);
    
    visited[0] = malloc(sizeof(int) * 4);
    visited[1] = malloc(sizeof(int) * 4);
    visited[2] = malloc(sizeof(int) * 4);
    visited[3] = malloc(sizeof(int) * 4);
    
    //set variables of 2d pointer array, mark the starting variables as already checked
    for(m = 0; m < 4; m++){
        for(n = 0; n < 4; n++){
            if(m == 0 && n == 0){
                
                visited[m][n] = 1;
                
            }else{
                
                visited[m][n] = 0;
                
            }
        }
    }
    
    //go through each space on the board and see if it connects to the letter
    for (row = 0; row < 4; row++) {
        
        for (col = 0; col < 4; col++) {
            
            if(AbidesRules(row, col, word, gameBoard, 0, visited)){
                
                //free and return true
                free(visited[0]);
                free(visited[1]);
                free(visited[2]);
                free(visited[3]);
                
                return 1;
                
            }
            
        }
        
    }
    
    //free and return false
    free(visited[0]);
    free(visited[1]);
    free(visited[2]);
    free(visited[3]);
    
    return 0;
    
}

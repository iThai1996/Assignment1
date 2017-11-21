#import <stdio.h>
#import <stdlib.h>

#import "../board_generator.h"
#import "../dictionaty.h"\
#import "../scoreboard.h"
#import "../word_checker.h"

int main(int arg, char**argv){
    
    //call tests
    testMain();
    testConvertToBoard();
    testPrintHCBoard();
    testHash();
    testLookupAndInsert();
    testAbidesRules();
    
}

//test for boggle
void testMain(){
    
    //code to test * not sure if refactored code or legacy
   
    //need to create gameboard
    
    /* around 150
     if (check_english != NULL) {
     check_submitted = lookup (guessed_words, SMALL_HASH_SIZE, input_word);
     
     if (check_submitted == NULL) {
     if(strlen(input_word) > 2){
     if(word_checker(game_board, input_word)){
     insert (guessed_words, SMALL_HASH_SIZE, input_word);
     increment_total_score(&current_score, input_word);
     fprintf (stdout, "Correct! You current score is now: %d \n", current_score);
     
     }else{
     fprintf (stderr, "The submitted word: \'%s\'' does not abide game rules. Try again!\n", original_input_word);
     }
     }else{
     fprintf (stderr, "The submitted word: \'%s\'' must be at least 3 letters long. Try again!\n", original_input_word);
     }
     
     }else{
     fprintf (stderr, "You have already submitted the word: \'%s\'' Try again!\n", original_input_word);
     }
     
     }else if (turn_count > 0){
     fprintf (stderr, "Incorrect word: \'%s\' is not in the English Dictionary. Try again!\n", original_input_word);
     }
     fprintf(stdout, "Submit a word you found:\n");
     scanf("%s", input_word);
     turn_count++;
     system("clear");
     */
    
}

//tests for board generator
void testConvertToBoard(){
    
    //test function convertToBoard
    
    
}

void testPrintHCBoard(){
    
    //test function printHCBoard

    
}

void testHash(){
    
    //test function hash
    
    
}

//tests for dictionary.c
void testLookupAndInsert(){
    
    //insert a word first
    //test its retrieval
    
}

//test for abide rules

/* not 100% sure what to do here this code will take
 allot of dependancies */

void testAbidesRules(){
    
    //test abideRules
    
}


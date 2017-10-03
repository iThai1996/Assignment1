#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include "board_generator.h"
#include "word_checker.h"
#include "scoreboard.h"

#define MAX_LINE 100

/*
 * set up board,
 * set up dictionary,
 */

void IncrementTotalScore(int *userScore, char *word);

void FreeAndResetBoard(struct rolledDice** gameBoard,
		struct presetDice* inputArrayOfDice) {

	for (int i = 0; i < 4; i++) {
		free(gameBoard[i]);
	}
	RollDice(gameBoard, inputArrayOfDice);
}


char *ConvertToUpper(char **upper){
	char *upperDeref = *upper;

	for(int i = 0; upperDeref[i]; i++){
	  upperDeref[i] = toupper(upperDeref[i]);
	}
	return upperDeref;
}

char *ConvertToUpper2(char (*upper)[]){
	char *upperDeref = *upper;

	for(int i = 0; upperDeref[i]; i++){
	  upperDeref[i] = toupper(upperDeref[i]);
	}
	return upperDeref;
}

void IncrementTotalScore(int *userScore, char *word){
	int wordLen = strlen(word);
	fprintf(stdout, "word_len: %d\n",wordLen );
	if(wordLen == 3 || wordLen == 4){
		*userScore+=1;
	}else if(wordLen == 5){
		*userScore+=2;
	}else if(wordLen == 6){
		*userScore+=3;
	}else if(wordLen == 7){
		*userScore+=5;
	}else if(wordLen >= 8){
		*userScore+=11;
	}
}


int main (int argc, char ** argv) {
	int i, points = 0, testPoints = 0, invalidSize = 0;
	char inputWord[100];
	char originalInputWord[100];

	FILE *inputFP;
	char line [MAX_LINE];
	char *fileName;
 	
 	const char * dictName = "EnglishWords.txt";
	DNode* checkEnglish;
	DNode* checkSubmitted;
	static DNode* englishDictionary [BIG_HASH_SIZE];
	static DNode* guessedWords [SMALL_HASH_SIZE];

	int currentScore = 0;
	int turnCount = 0;

	User* head = NULL;
	head = (User*)malloc(sizeof(User));

	PresetDice globalDice[16];
	RolledDice *gameBoard[4];

	FILE *outputFP;
	char readLine[MAX_LINE];


	if(!(inputFP = fopen ( dictName , "r" )))    {
        fprintf(stderr,"Could not open file \"%s\" for reading dictionary words\n", dictName);
        return 1;
    }

	while( fgets (line, MAX_LINE, inputFP)!=NULL ) {
		line[strcspn(line, "\r\n")] = '\0';  //trim new line characters
		insert (englishDictionary, BIG_HASH_SIZE, ConvertToUpper2(&line));
	}	
	fclose (inputFP);


	if (argc == 1){
		fprintf(stdout, "playing in normal mode\n\n");

		system("clear");

		InitializePresetDice(globalDice);

		RollDice(gameBoard, globalDice);

		while (turnCount >= 0) {
			strcpy(originalInputWord, inputWord);

			ConvertToUpper2(&inputWord);

			User *thisUser;
			char inputName[100];

			if (strcmp(originalInputWord, "q") == 0) {
				// "q" is the input, print scoreboard and exit game
				PrintScoreboard(head);
				break;
			}
			// "n" is the input, adds user to/changes user in linked list and
			// resets game
			if (strcmp(originalInputWord, "n") == 0) {

				PrintScoreboard(head);
				fprintf(stdout, "Your current score: %d \n", currentScore);
				fprintf(stdout, "What is your name? \n");
				scanf("%s", inputName);

				if (UserIsInList(head, inputName) == 0){
					AddNode(head, inputName, currentScore);
				}
				else {
					UpdateNodeWithName(head, inputName, currentScore);
				}

				currentScore = 0;

				strcpy(inputWord, "");

				FreeAndResetBoard(gameBoard, globalDice);
				turnCount = 0;
				system("clear");
				continue;
			}

			PrintGameBoard(gameBoard);

			checkEnglish = Lookup (englishDictionary, BIG_HASH_SIZE, inputWord);
			
			if (checkEnglish != NULL) {
				checkSubmitted = Lookup (guessedWords, SMALL_HASH_SIZE, inputWord);
				
				if (checkSubmitted == NULL) {
					if(strlen(inputWord) > 2){
						if(WordChecker(gameBoard, inputWord)){
							Insert (guessedWords, SMALL_HASH_SIZE, inputWord);
							IncrementTotalScore(&currentScore, inputWord);
							fprintf (stdout, "Correct! You current score is now: %d \n", currentScore);
					
						}else{
							fprintf (stderr, "The submitted word: \'%s\'' does not abide game rules. Try again!\n", originalInputWord);
						}
					}else{
						fprintf (stderr, "The submitted word: \'%s\'' must be at least 3 letters long. Try again!\n", originalInputWord);
					}

				}else{
					fprintf (stderr, "You have already submitted the word: \'%s\'' Try again!\n", originalInputWord);
				}

		 	}else if (turnCount > 0){
		 		fprintf (stderr, "Incorrect word: \'%s\' is not in the English Dictionary. Try again!\n", originalInputWord);
			}
			fprintf(stdout, "Submit a word you found:\n");
	       	scanf("%s", inputWord);
	        turnCount++;
	        system("clear");
   		}
		for (int i = 0; i < 4; i++) {
			free(gameBoard[i]);
		}
		free_all(head);

	}else if (argc == 2){
				fileName =  argv[1];
		fprintf(stdout, "playing in test mode with file: %s\n", fileName);
		FILE *testFileFP;
		char testLine [MAX_LINE];
		char *testWords;
		char **testBoard;
		int fileLineCounter = 1;
		int i,j;
		DNode* testResult;
		int begin = 0;

		// (1) read first line which is the board
		if(!(testFileFP = fopen ( fileName , "r" )))    {
		    fprintf(stderr,"Could not open test file \'%s\' for reading\n", fileName);
		    return 1;
		}else if(!(outputFP = fopen("result.txt", "w" ))){
	   	 fprintf(stderr,"Could not open result file \'%s\' for writing\n", "result.txt");
		    return 1;
		}

		while (fgets (testLine, MAX_LINE, testFileFP)!=NULL ) {
			testLine[strcspn(testLine, "\r\n")] = '\0';  //trim new line characters

			if(fileLineCounter == 1){
					ConvertToBoard(testLine, &testBoard);

					// this can be removed, its just for testing purposes
					for (i = 0; i < 4; i++) {
						for (j = 0; j < 4; j++) {
							if (j != 3) {
								fprintf(stdout, "%c \t", testBoard[i][j] );
							}else {
								fprintf(stdout, "%c \n", testBoard[i][j] );
							
							}
						}
					
					}
			
			}else if (file_line_counter >= 2){
				for (char *p = strtok(test_line,","); p != NULL; p = strtok(NULL, ",")){
					check_english = lookup (english_dictionary, BIG_HASH_SIZE, convert_to_upper(&p));
						
					if (check_english != NULL) {
						check_submitted = lookup (guessed_words, SMALL_HASH_SIZE, p);
						
						if (check_submitted == NULL) {
							if(test_word_checker(test_board, p)){
								insert (guessed_words, SMALL_HASH_SIZE, p);
								increment_total_score(&test_points, p);
								fprintf(stdout,"Correct! You total score is now: %d \n",test_points );
						
							}else{
								if(begin == 0){								
									fprintf(output_FP, "%s", p );
									begin++;
								}else{
									fprintf(output_FP, ",%s", p );
								}
								
								fprintf(stderr,"The submitted word: \'%s\'' does not abide game rules. Try again!\n", p);								
							}

						}else{
								if(begin == 0){								
									fprintf(output_FP, "%s", p );
									begin++;
								}else{
									fprintf(output_FP, ",%s", p );
								}
							fprintf(stderr,"You have already submitted the word: \'%s\'' Try again!\n", p);
						}

			
				 	}else{
						if(begin == 0){								
							fprintf(output_FP, "%s", p );
							begin++;
						}else{
							fprintf(output_FP, ",%s", p );
						}

				 		fprintf(stderr,"Incorrect word: \'%s\'' is not in the English Dictionary. Try again!\n", p);
					}
				}
			}
			file_line_counter++;
		}

		fprintf(output_FP, "\n");
		fprintf(output_FP, "%d\n", test_points);

		fclose (test_file_FP);

		for (int i = 0; i < 4; i++) {
			free(test_board[i]);
		}
		free(test_board);

		fclose(output_FP);

	}

	free_dictionary(english_dictionary, BIG_HASH_SIZE);
	free_dictionary(guessed_words, SMALL_HASH_SIZE);

	return 0;
}

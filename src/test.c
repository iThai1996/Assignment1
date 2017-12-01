#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/dictionary.h"
#include "../include/boardGenerator.h"
#include "../include/wordChecker.h"
#include "../include/scoreboard.h"

void incrementTotalScore(int *userScore, char *word);

char *convertToUpper2(char (*upper)[]) {
    char *upperDeref = *upper;

    int i;
    for (i = 0; upperDeref[i]; i++) {
        upperDeref[i] = toupper(upperDeref[i]);
    }
    return upperDeref;
}

void incrementTotalScore(int *userScore, char *word) {
    int wordLen = strlen(word);

    if (wordLen == 3 || wordLen == 4) {
        *userScore += 1;
    }
    else if (wordLen == 5) {
        *userScore += 2;
    }
    else if (wordLen == 6) {
        *userScore += 3;
    }
    else if (wordLen == 7) {
        *userScore += 5;
    }
    else if (wordLen >= 8) {
        *userScore += 11;
    }
    printf("user score %d\n", *userScore);
}

int main() {

//Test 1
printf("Testing the incrementTotalScore function...\n");
int userScore = 0;
char *word;
printf("sending in a 2 letter word to incrementTotalScore score should be 0\n");
word = "at";
incrementTotalScore(&userScore,word);
userScore = 0;
word = "abcdefga";
printf("sending in an 8 letter word score should be 11\n");
incrementTotalScore(&userScore,word);
userScore = 0;
printf("sending in a space to incrementTotalScore score should be 0\n");
word = " ";
incrementTotalScore(&userScore,word);
userScore = 0;
printf("sending in a 3 letter word score should be 1\n");
word = "abc";
incrementTotalScore(&userScore,word);
userScore = 0;
printf("sending in a 5 letter word score should be 2\n");
word = "abcde";
incrementTotalScore(&userScore,word);
userScore = 0;
printf("sending in a 0 letter word score should be 0\n");
word = "";
incrementTotalScore(&userScore,word);
userScore = 0;

//Test 2
printf("Testing the convertToUpper function...\n");
char newWord[100];

printf("sending in a 0 letter word result should be nothing\n");
strcpy(newWord, "");
printf("result is %s\n", convertToUpper2(&newWord));

printf("sending in a 1 letter word result should be A\n");
strcpy(newWord, "a");
printf("result is %s\n", convertToUpper2(&newWord));

printf("sending in a 5 letter word (all lowercase characters) result should be QWERT\n");
strcpy(newWord, "qwert");
printf("result is %s\n", convertToUpper2(&newWord));

printf("sending in a 7 letter word (mixed upper and lower characters) result should be ASDFGHJ\n");
strcpy(newWord, "asDFghJ");
printf("result is %s\n", convertToUpper2(&newWord));

printf("sending in a 1 letter word result should be +\n");
strcpy(newWord, "+");
printf("result is %s\n", convertToUpper2(&newWord));

printf("sending in an 8 letter word (mixed upper, lower, and symbols) result should be ZXCV$?U!\n");
strcpy(newWord, "zxCV$?u!");
printf("result is %s\n", convertToUpper2(&newWord));

return 0;
}


#include "../include/board_generator.h"

void initializePresetDice(PresetDice *inputArrayOfDice)
{
    int i;

    for (i = 0; i < 16; i++) {
        inputArrayOfDice[i].position = 0;
    }

    //initializes each dies potential characters
    inputArrayOfDice[0].configurations = "RIFOBX";
    inputArrayOfDice[1].configurations = "IFEHEY";
    inputArrayOfDice[2].configurations = "DENOWS";
    inputArrayOfDice[3].configurations = "UTOKND";
    inputArrayOfDice[4].configurations = "HMSRAO";
    inputArrayOfDice[5].configurations = "LUPETS";
    inputArrayOfDice[6].configurations = "ACITOA";
    inputArrayOfDice[7].configurations = "YLGKUE";
    inputArrayOfDice[8].configurations = "QBMJOA";
    inputArrayOfDice[9].configurations = "EHISPN";
    inputArrayOfDice[10].configurations = "VETIGN";
    inputArrayOfDice[11].configurations = "BALIYT";
    inputArrayOfDice[12].configurations = "EZAVND";
    inputArrayOfDice[13].configurations = "RALESC";
    inputArrayOfDice[14].configurations = "UWILRG";
    inputArrayOfDice[15].configurations = "PACEMD";
}

void rollButNotShuffleDice(RolledDice *gameDice, PresetDice *inputArrayOfDice)
{
    int i;
    int randNum;

    srand(time(NULL));

    //for each of the 16 dice one face is chosen at random and is stored in the game dice
    for (i = 0; i < 16; i++) {
        randNum = rand() % 6;
        gameDice[i].character = inputArrayOfDice[i].configurations[randNum];
    }
}

void shuffleRolledDicePositions(RolledDice *gameDice)
{
    int i;

    RolledDice newGameDice[16];

    int randNum = 0;
    for (i = 0; i < 16; i++) {
        srand(time(NULL));

        //generate random values for the game dice
        while (gameDice[randNum].position == -1)
        {
            randNum = (int) (rand()%16);
        }
        newGameDice[i] = gameDice[randNum];
        gameDice[randNum].position = -1;
    }

    for (i = 0; i < 16; i++) {
        gameDice[i] = newGameDice[i];
        gameDice[i].position = i+1;
    }
}


void rollDice(RolledDice **gameBoard, PresetDice *inputArrayOfDice)
{
    int i;
    int j;

    gameBoard[0] = malloc(sizeof(RolledDice) * 4);
    gameBoard[1] = malloc(sizeof(RolledDice) * 4);
    gameBoard[2] = malloc(sizeof(RolledDice) * 4);
    gameBoard[3] = malloc(sizeof(RolledDice) * 4);

    //temp array for the dice before getting stored in the game board
    RolledDice adjustedDiceArray[16];

    rollButNotShuffleDice(adjustedDiceArray, inputArrayOfDice);
    shuffleRolledDicePositions(adjustedDiceArray);

    //converts the array of rolled and shuffled dice into a 2D array for the game board
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            gameBoard[i][j] = adjustedDiceArray[(i * 4) + j];
        }
    }
}

//prints the game board as a 4x4 visualization of the 2d array
void printGameBoard(RolledDice **gameBoard)
{
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j != 3) {
                printf("%c \t", gameBoard[i][j].character);
            } else {
                printf("%c \n", gameBoard[i][j].character);
            }
        }
    }
}

/*same as above*/
void printHcBoard(char **boggle)
{
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j != 3) {
                printf("%c \t", boggle[i][j]);
            } else {
                printf("%c \n", boggle[i][j]);

            }
        }
    }
}

void convertToBoard(char *letters, char ***board)
{

    char *word;
    int i;
    int j;

    *board = malloc(sizeof(char * ) * 4);
    char **board2D = *board;

    board2D[0] = malloc(sizeof(char) * 4);
    board2D[1] = malloc(sizeof(char) * 4);
    board2D[2] = malloc(sizeof(char) * 4);
    board2D[3] = malloc(sizeof(char) * 4);

    //loops through the 4x4 board adding letters one at a time from the array
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            board2D[i][j] = letters[(i*4) + j];
        }
    }
}

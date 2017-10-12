#include "board_generator.h"

// Initializes the dice in the list of pre-set dice. Call once at program start.
void InitializePresetDice(PresetDice *inputArrayOfDice) {
    for (int i = 0; i < 16; i++) {
        inputArrayOfDice[i].position = 0;
    }

    // initializes individual potential chars for each dice
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

// Rolls the dice to be used at the start of each game. Puts the rolled dice in
// game_dice. Does not shuffle the dice. Helper function.
void RollButNotShuffleDice(RolledDice* gameDice, PresetDice* inputArrayOfDice) {
    srand(time(NULL));
    for (int i = 0; i < 16; i++) {
        int r = rand()%6;
        gameDice[i].character = inputArrayOfDice[i].configurations[r];
    }
}

// Shuffles an array of rolled dice. Helper function.
void ShuffleRolledDicePositions(RolledDice *gameDice) {
    RolledDice newGameDice[16];

    int r = 0;
    for (int i = 0; i < 16; i++) {
        srand(time(NULL));
        // this is somewhat inefficient. Using it for now.
        while (gameDice[r].position == -1) {
            r = (int) (rand()%16);
        }
        newGameDice[i] = gameDice[r];
        gameDice[r].position = -1;
    }

    for (int i = 0; i < 16; i++) {
        gameDice[i] = newGameDice[i];
        gameDice[i].position = i+1;
    }
}


// Rolls the dice to be used at the start of the game and shuffles them, putting
// the dice into the 2D array game_dice. Call once at the start of every game.
void RollDice(RolledDice **gameBoard, PresetDice *inputArrayOfDice) {
    gameBoard[0] = malloc(sizeof(RolledDice) * 4);
    gameBoard[1] = malloc(sizeof(RolledDice) * 4);
    gameBoard[2] = malloc(sizeof(RolledDice) * 4);
    gameBoard[3] = malloc(sizeof(RolledDice) * 4);

    // temporary array of structs to contain adjusted 1D array of dice.
    RolledDice adjustedDiceArray[16];

    RollButNotShuffleDice(adjustedDiceArray, inputArrayOfDice);
    ShuffleRolledDicePositions(adjustedDiceArray);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gameBoard[i][j] = adjustedDiceArray[i * 4 + j];
        }
    }
}

// Prints a visualization of the input array of rolled_dice.
void PrintGameBoard(RolledDice** gameBoard) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != 3) {
                printf("%c \t", gameBoard[i][j].character);
            } else {
                printf("%c \n", gameBoard[i][j].character);
            }
        }
    }
}

void PrintHcBoard(char boggle[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != 3) {
                printf("%c \t", boggle[i][j]);
            } else {
                printf("%c \n", boggle[i][j]);

            }
        }
    }
}

/** Converts board from a string version to 2D array. Used in test mode**/
void ConvertToBoard(char *letters, char ***board) {

    // allocate space for boggle board on heap in order to access it in main.
    char *word;
    int i, j, t = 0;

    *board = malloc(sizeof(char * ) * 4);
    char **boardDeref = *board;

    boardDeref[0] = malloc(sizeof(char) * 4);
    boardDeref[1] = malloc(sizeof(char) * 4);
    boardDeref[2] = malloc(sizeof(char) * 4);
    boardDeref[3] = malloc(sizeof(char) * 4);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j != 3) {
                boardDeref[i][j] = letters[t];
                t++;
            } else {
                boardDeref[i][j] = letters[t];
                t++;
            }
        }
    }
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scoreboard.h"

User* findUserWithName(User* head, char* nameToFind)
{
    if (head == NULL) {
        return NULL;
    }

    User* current = head ;

    while (current != NULL) {
        if (strcmp(current->name, nameToFind) == 0) {
            return current;
        }
        current = (current)->next;
    }

    return NULL;
}

User* getUserAtIndex(User* head, int index)
{
    int count = 0;

    if (head == NULL) {
        return NULL;
    }

    User* current = head;

    while (current != NULL) {
        if (count == index + 1) {
            return current;
        }
        current = (current)->next;
        count++;
    }

    return NULL;
}

void freeAll(User* head)
{
    if (head->next == NULL) {
        free(head);
    }
    else {
        User* current = head->next;
        User* previous = head;
        while (current != NULL) {
            free(previous);
            previous = current;
            current = current->next;
        }
    }

    return;
}

int getIndexOfUserWithName(User* head, char* nameToFind)
{
    int count = 0;
    User* current = head;

    if (head == NULL && head->name != nameToFind) {
        return -1;
    }

    while (current != NULL) {
        if (strcmp(current->name, nameToFind)) {
            return count;
        }
        current = current->next;
        count++;
    }

    return -1;
}

int userIsInList(User* head, char* nameToFind)
{
    User* current = head;

    while (current != NULL) {
        if (strcmp(current->name, nameToFind) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int getLength(User* head)
{
    int count = 0;

    if (head == NULL) {
        return 0;
    }

    User* current = head;

    while (current != NULL) {
        count++;
        if (current->next == NULL) {
            return count;
        }
        current = current->next;
    }

    return 0;
}

User* getLastNode(User* head)
{
    if (head == NULL) {
        return head;
    }

    User* current = head;

    while (current != NULL) {
        if (current->next == NULL) {
            return current;
        }
        current = (current)->next;
    }

    return NULL;
}

void printScoreboard(User* head)
{
        fprintf(stdout, "\n");
        fprintf(stdout, "---- SCORE BOARD ---- \n");

    if (head -> next != NULL) {
        User* current = head -> next;
        while (current != NULL) {
            printf("\n");
            printf("Player name: %s \n", current->name);
            printf("High score: %d \n", current->maxScore);
            printf("Games played: %d \n", current->totalGames);
            printf("Total score: %d \n", current->totalScore);
            printf("\n");
            printf("--------------------- \n");

            if (current->next == NULL) {
                break;
            }
            current = current->next;
        }
    }

    return;
}

void addNode(User* head, char* name, int maxScore)
{
    User* userPtr;

    if (head != NULL) {
         userPtr = malloc(sizeof(User));
    }

    strcpy(userPtr->name, name);
    userPtr->maxScore = maxScore;
    userPtr->totalGames = 1;
    userPtr->totalScore = maxScore;
    userPtr->next = NULL;

    if (head == NULL) {
        head = userPtr;
    }

    else {
        getLastNode(head)->next = userPtr;
    }

    return;
}

void updateNodeWithName(User* head, char* name, int currentScore)
{
    if (userIsInList(head, name) == 1) {

        User *userPtr = findUserWithName(head, name);

        if (currentScore > (userPtr->maxScore)) {
            userPtr->maxScore = currentScore;
        }

        userPtr->totalGames += 1;
        userPtr->totalScore += currentScore;
    }

    return;
}

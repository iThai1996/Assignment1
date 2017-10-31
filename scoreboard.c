#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scoreboard.h"

User* FindUserWithName(User* head, char* nameToFind)
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

User* GetUserAtIndex(User* head, int index)
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

void FreeAll(User* head)
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

int GetIndexOfUserWithName(User* head, char* nameToFind)
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

int UserIsInList(User* head, char* nameToFind)
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

int GetLength(User* head)
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

User* GetLastNode(User* head)
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

void PrintScoreboard(User* head)
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

void AddNode(User* head, char* name, int maxScore)
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
        GetLastNode(head)->next = userPtr;
    }

    return;
}

void UpdateNodeWithName(User* head, char* name, int currentScore)
{
    if (UserIsInList(head, name) == 1) {

        User *userPtr = FindUserWithName(head, name);

        if (currentScore > (userPtr->maxScore)) {
            userPtr->maxScore = currentScore;
        }

        userPtr->totalGames += 1;
        userPtr->totalScore += currentScore;
    }

    return;
}

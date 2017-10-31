#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdlib.h>

typedef struct user{
	char name[100];
	int maxScore;
	int totalGames;
	int totalScore;
	struct user *next;
} User;

/*
 * Finds and returns a pointer to the User in the linked list beginning with
 * head which has the name nameToFind. If such a User is not in the Linked
 * List, it will return NULL. Helper function to incrementScore.
 * @param head The head of linked list
 * @param nameToFind The name being searched for
 * @return On success returns a pointer to the User. On failure, returns NULL.
 */
User* findUserWithName(User* head, char* nameToFind);

/*
 * Finds and returns a pointer to the User in the linked list at
 * the given index. If such a User is not in the Linked List, it
 * will return NULL.
 * @param head The head of the linked list
 * @param index The index location of the user to find
 */
User* getUserAtIndex(User* head, int index);

/*
 * Finds and returns index number of User in a linked list, given
 * the name of a user.
 * @param head The head of the linked list
 * @param nameToFind The name of the user to search for
 * @return On success, return index location of user. On failure, return NULL.
 *
 */
int getIndexOfUserWithName(User* head, char* nameToFind);

/*
 * Given a pointer to the head of a linked list, returns the length.
 * @param head The head of the linked list
 * @return On success, return index location. On failure, return NULL.
 */
int getLength(User* head);

/*
 * Helper function. Finds the last node in the linked list and returns it.
 * Returns NULL if called with an empty head, although such a case is not used
 * in the main function AddNode.
 */
User* getLastNode(User* head);

/*
 * Given a pointer to the head of a linked list, prints the scoreboard.
 * @param head The head of the linked list
 */
void printScoreboard(User* head);

/*
 * Frees every element of the linked list
 * @param head The head of the linked list
 */
void freeAll(User* head);

/*
 * Adds a new user to the scoreboard linked list.
 * @param head Pointer to the head of the linked list
 * @param name The name of the person to enter
 * @param maxScore Maximum score a user is allowed to have.
 */
void addNode(User* head, char* name, int maxScore);

/*
 * Finds whether or not a an existing user is already in the list. Of they are,
 * returns 1. If not, returns 0.
 */
int userIsInList(User* head, char* nameToFind);

/*
 * Updates a person in the scoreboard linked list to have a new name.
 * @param head The head of the linked list
 * @param name New name to save
 * @currentScore The person's current score
 */
void updateNodeWithName(User *head, char* name, int currentScore);

#endif

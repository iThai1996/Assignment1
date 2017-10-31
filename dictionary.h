/**
* @file dictionary.h
* @editor Maxwell Christie
* @date October 24
* @brief File containing functions declarations for dictionary
**/


#ifndef DICTIONARY_H
#define DICTIONARY_H
#define BIG_HASH_SIZE 20000
#define SMALL_HASH_SIZE 100
#include <stdlib.h>

/**
 * Contains basic node information
 * @var key word used as key to hash table
 * @var next pointer to next node
 */
typedef struct dNode {
	char* key;
    struct dNode *next;
} DNode;

/**
 * Function to copy string
 * @param s string to be copied
 * @return new string identical to s
 */
char* copyStr(const char* s);

/**
 * Function to convert string into integer for using in hash table
 * @return hashVal value to become hash table index
 * @param s from EnglishWords.txt converted into hashVal
 */
unsigned hash(const char* s);

/**
 * Function to search for word in dictionary
 * @param dictionary 2D array/hash table containing words
 * @param hashSize constant int size of hash table
 * @param key key to locating word in dictionary
 * @return pointer node containing word
 */
DNode* lookUp(DNode** dictionary, int hashSize, const char* key);

/**
 * Function to insert word into dictionary
 * @param dictionary 2D array/hash table containing words
 * @param hashSize constant int size of hash table
 * @param key key to locating word in dictionary
 * @return pointer node containing word
 */
DNode* insert(DNode** dictionary, int hashSize, const char* key);

/**
 * Function to free data in dictionary
 * @param dictionary 2D array/hash table containing words
 * @param hashSize constant int size of hash table
 * @post dictionary and encapsulated data is freed
 */
void freeDictionary(DNode** dictionary, int hashSize);

#endif

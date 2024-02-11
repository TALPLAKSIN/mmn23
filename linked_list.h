
#ifndef MMN23_REFAEL2024_LINKED_LIST_H
#define MMN23_REFAEL2024_LINKED_LIST_H



#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000

/*A pointer to a linked list*/
typedef struct linked *linkedList;
/*
 * This function allocates memory for a new linked list node, initializes its name
 * and data fields with the provided arguments (name and countLine),
 * sets the next pointer to NULL, and returns a pointer to the newly created node.
 * This function essentially constructs a new node for a linked list,
 * preparing it for insertion into the list.
 */
linkedList createLinked(char *name, int countLine) ;
/*
 * The  function efficiently inserts a new node into a linked list.
 * If the list is empty, it sets the head pointer to the new node. Otherwise,
 * it updates the new node's next pointer to the current head,
 * effectively inserting it at the beginning of the list,
 * and then updates the head pointer to point to the new node.
 */
void InsertLinked(linkedList *head, linkedList new_linked) ;
/*
 * The  function recursively searches for a node with a specific name in a linked list.
 * It compares the name field of each node with the provided name parameter.
 * If a match is found, it returns a pointer to that node; otherwise,
 * it continues searching recursively by moving to the next node using its next pointer.
 * If the end of the list is reached without finding a match or if the input list is empty,
 * it returns NULL.
 */
linkedList SearchLink(linkedList linked, char *name) ;
/*
 * This  function checks if a node with the given name exists in the linked list.
 * If not, it creates a new node with the name and line number and inserts it at the beginning.
 * If a node with the same name exists, it creates a temporary node with the line number,
 * combines its data with the existing node's data, and then frees it.
 */
void checkAndAdd(linkedList **listStr, char *name, int countLine) ;
/*
 * This function concatenates characters from s2 into s1 until it
 * encounters a NULL terminator or a comma in s2.
 * After the concatenation, it appends a comma to the end of s1 if s1 is not NULL,
 * ensuring the resulting string is properly formatted. This function essentially
 * combines two strings, s1 and s2, with comma separation in s1.
 */
void comS1S2(char *s1, char *s2);
/*
 * This function reads the content of an input file line by line. For each line,
 * it tokenizes the words using whitespace characters as delimiters.
 * Then, it iterates through each word, calling the checkAndAdd function
 * to add each word to a linked list along with its corresponding line number.
 * This function populates the linked list with words and their line numbers
 * from the input file and returns the updated linked list.
 */
linkedList readFile(FILE *inputFile, linkedList *listStr) ;
/*
 * The removeLink function removes a node with a specific name
 * from a linked list by traversing the list
 * to find the node with the given name and updating pointers to bypass it.
 */
linkedList removeLink(linkedList listStr,char *name);
/*
 * This function the name of that node along with the associated line numbers.
 * After printing, it removes the node with the minimum name from the
 * linked list and recursively calls itself to print the remaining nodes.
 */
void printList(linkedList listStr) ;
/*
 * This function deallocates the memory occupied by a linked list node,
 * including its name and data fields, and then frees the node itself.
 */
void freeLinked(linkedList linked) ;
/*
 * The  function deallocates the memory occupied by all nodes in a linked list starting
 * from the head node by iterating through the list and freeing each node.
 */
void freelist(linkedList head) ;

#endif

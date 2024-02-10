
#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct linked {
    char *name;/* name of the node */
    char *data;/* data of the node */
    linkedList next;  /* Next linked */
};

linkedList createLinked(char *name, int countLine) {
    linkedList tempList = (linkedList) calloc(1, sizeof(struct linked));
    tempList->name = (char *) calloc(1, (strlen(name) + 1) * sizeof(char));
    tempList->data = (char *) calloc(1, (50)* sizeof(char));
    strcpy(tempList->name, name);
    sprintf(tempList->data, "%d", countLine);
    tempList->next = NULL;
    return tempList;
}

void InsertLinked(linkedList *head, linkedList new_linked) {
    if (!(*head)) /* if the list is empty */
        *head = new_linked;
    else {
        /*Make next of new node as head*/
        new_linked->next = (*head);
        /*move the head to point to the new node*/
        (*head) = new_linked;
    }
}

linkedList SearchLink(linkedList linked, char *name) {
    linkedList temp;
    if (linked != NULL) {
        temp = linked;
        if ((name != NULL) && strcmp(temp->name, name) == 0)
            return temp;
        return SearchLink(linked->next, name);/*recursive call to check next node*/
    }
    return NULL;
}

void checkAndAdd(linkedList **listStr, char *name, int countLine) {
    linkedList tempList = NULL; /* Temporary pointer for existing node */
    linkedList tempList2 = NULL;  /* Temporary pointer for new node */
    tempList = SearchLink(**listStr, name); /* Search for existing node with given name */
    if (tempList == NULL) {/* If node with given name doesn't exist */
        /* Create a new node with the given name and line number */
        tempList = createLinked(name, countLine);
        InsertLinked(*listStr, tempList); /* Insert the new node at the head of the linked list */
    } else {
        tempList2 = createLinked(" ", countLine); /* Create a new temporary node with a dummy name and the given line number */
        sprintf(tempList2->data, "%d", countLine);
        comS1S2(tempList->data,tempList2->data );
        freeLinked(tempList2);
    }
}

void comS1S2(char *s1, char *s2) {
    int  j; /* Counter for characters in s2 */
    unsigned long i;  /* Counter for characters in s1 */
    /* Loop through each character in s2 until reaching NULL terminator or comma */
    for (j = 0,i= strlen(s1)+1; s1!=NULL &&(isdigit(s2[j]) || s2[j] == ','); j++, i++)
        s1[i]=s2[j];/* Append current character of s2 to s1 */
    if(s1!=NULL) { /* Add comma to the end of s1 if it's not NULL */
        s1[strlen(s1)] = ',';/* Add comma to the end of s1 */
        s1[i] = '\0';/* Add NULL terminator to the end of s1 */
    }
}

linkedList readFile(FILE *inputFile, linkedList *listStr) {
    char *curWord;
    char lineCheck[MAX_LINE_LENGTH] = {0};
    char countLine = 0; /* Pointer to current word */
    while (!feof(inputFile)) { /*over all file, line by line*/
        memset(lineCheck, 0, MAX_LINE_LENGTH);
        fgets(lineCheck, MAX_LINE_LENGTH, inputFile); /*save the current line*/
        countLine++;
        curWord = strtok(lineCheck, " \t\n\v\f\r");/* cut the first word in the line */
        checkAndAdd(&listStr, curWord, countLine);
        while (curWord != NULL) {
            curWord = strtok(NULL, " \t\n\v\f\r");
            if (curWord != NULL)
                checkAndAdd(&listStr, curWord, countLine);
        }
    }
    return *listStr;
}


linkedList removeLink(linkedList listStr, char *name) {
    linkedList tempList1 = listStr;/* Pointer to the previous node */
    linkedList tempList2 = listStr;  /* Pointer to the current node */
    if (listStr->next == NULL)  /* If the linked list is empty or has only one node */
        return NULL;
    if (listStr->name == name)/* If the first node's name matches the given name, remove it */
        return listStr->next;
    tempList2 = tempList2->next; /* Move to the next node */
    while (tempList2->name != name) {/* Traverse the linked list until finding the node with the given name */
        tempList2 = tempList2->next;
        tempList1 = tempList1->next;
    }
    tempList1->next = tempList2->next;  /* Adjust the pointers to remove the node from the linked list */
    freeLinked(tempList2);
    return listStr;
}

void printList(linkedList listStr) {
    unsigned long i; /* Counter for loop */
    linkedList tempList = listStr;  /* Temporary pointer to traverse the linked list */
    linkedList minList = listStr;  /* Pointer to the node with the minimum name */
    if (listStr != NULL) { /* If the linked list is not empty */
        while (tempList->next != NULL) {
            tempList = tempList->next;
            if (strcmp(tempList->name, minList->name) < 0)
                minList = tempList;
        } /* Print the name of the node with padding for formatting */
        printf("%s", minList->name);
        for(i= strlen(minList->name);i<15;i++)
            printf(" ");
        printf("appears in lines %s\n", minList->data);/* Print the line numbers associated with the node */
        listStr = removeLink(listStr, minList->name); /* Remove the node with the minimum name from the linked list */
        printList(listStr);  /* Recursive call to print the rest of the linked list */
    }
}

void freeLinked(linkedList linked) {
    free(linked->name);
    free(linked->data);
    free(linked);
}

void freelist(linkedList head) {
    linkedList prev, current = head;
    while (current != NULL) {
        prev = current;
        current = current->next;
        freeLinked(prev);
    }
}





#include "index.h"


/**
 * @author Refael Camus
 * @date 09.02.2024
 */
int main(int argc, char *argv[]) {
    FILE *fptr;
    linkedList listStr=NULL;
    /* opening the file for reading, exiting if file does not exist */
    fptr = openFileAndCommandLineCheck(argc, argv[1]);
    listStr=readFile(fptr,&listStr);
    printList(listStr);
    /*closing the file */
    fclose(fptr);
    /*freeing the memory that has been allocated for the list */
    freelist(listStr);
    return 0;
}



FILE *openFileAndCommandLineCheck(int argc, char *file) {
    FILE *fptr;
    if (argc != 2) {
        fprintf(stderr, "Must be 2 operators \n");
        exit(0);
    }
    fptr = fopen(file, "r");
    if (fptr == NULL) {
        fprintf(stderr, "Cannot open file \n");
        exit(0);
    }
    if (feof(fptr)) {
        fprintf(stderr, "The file is empty\n");
        fclose(fptr);
        exit(0);
    }
    return fptr;
}

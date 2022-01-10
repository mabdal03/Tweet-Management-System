#include "headerA3.h"

//Function to save all tweets to a file
void saveTweetsToFile(tweet * tweetList){

    //Defining default values and prompting user for input filename
    char filename[50];
    printf("Enter where you would like to store your tweets: ");
    fgets(filename, 50, stdin);
    strtok(filename, "\n");

    //Opening the file in write mode
    FILE* openFile = NULL;
    openFile = fopen(filename, "w");

    tweet * current = tweetList;

    //Going through the file until the end of the linked list and printing all of its contents
    while (current != NULL) {
        fprintf(openFile,"%d,%s,%s\n",current->id,current->user,current->text);
        current = current->next;
    }

    fclose(openFile);
}
#include "headerA3.h"

//Function to search for a tweet going by keyword
int searchTweetsByKeyword(tweet * tweetList){

    //Defining all default values
    char searchStr[141], * searchFound = NULL, lowerSearch[141], lowerText[141];
    int returned = 0;
    tweet * current = tweetList;

    //Taking keyword input from the user
    printf("Enter a keyword to search: ");
    fgets(searchStr, 141, stdin);
    strtok(searchStr, "\n");

    //Making all characters lower case in the inputted keyword
    strcpy(lowerSearch, searchStr);
    for(int i = 0;i <= strlen(lowerSearch); i++){
      if(lowerSearch[i] >= 65 && lowerSearch[i] <= 90)
         lowerSearch[i] = lowerSearch[i] + 32;
    }
   
    //Going through the linked list of nodes and making all text lowercase, then using strstr to check if it matches the keyword
    while (current != NULL) {

        //Making all characters lower case in the tweet text
        strcpy(lowerText, current->text);
        for(int i = 0; i <= strlen(lowerText); i++){
        if(lowerText[i] >= 65 && lowerText[i] <= 90)
            lowerText[i] = lowerText[i] + 32;
        }

        //Using strstr to check if the keyword matches the text and outputting whether it does
        searchFound = strstr(lowerText, lowerSearch);
        if (searchFound != NULL){
            printf("Match found for '%s': %s wrote: \"%s\"\n", searchStr, current->user, current->text);
            returned = 1;
        }
        current = current-> next;
    }

    return returned;
}
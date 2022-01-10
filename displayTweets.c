#include "headerA3.h"

//Function to display all the tweets in the linked list
void displayTweets(tweet * tweetList){
    tweet * current = tweetList;

    //While loop going through the linked list and printing all data
    while (current != NULL) {
        printf("%d: Created by %s: %s\n", current->id, current->user, current->text);
        current = current->next;
    }
}
#include "headerA3.h"

//Function to create a tweet.
tweet * createTweet(tweet * tweetList){

    //Defining all initial values
    tweet * current = tweetList;
    int sum = 0, userId, exit = 0, findNewID = 0, upper = 999, lower = 1;
    char userName[500];
    char userText[500];

    //taking input from the user for username and tweet text, then making sure it's the correct character size
    printf("Enter a username: ");
    fgets(userName, 500, stdin);

    if (strlen(userName) > 51 || userName[0] == '\n'){
        printf("Username must be > 0 and no greater than 51 characters.\n");
        return NULL;
    }

    printf("Enter the user's tweet: ");
    fgets(userText, 500, stdin);

    if (strlen(userText) > 141 || userText[0] == '\n'){
        printf("Text must be >0 and no greater than 141 characters.\n");
        return NULL;
    }

    strtok(userName, "\n");
    strtok(userText, "\n");

    //Calculating the value for the user ID
    for (int i = 0; i < strlen(userName); i++)
    {
        sum = sum + userName[i];
    }
    userId = sum + strlen(userText);

    //While loop to determine whether there's a duplicate ID and calculate a new ID if there is one
    while (exit == 0){
        current = tweetList;

        while (current != NULL) {
            if (userId == current->id){
                findNewID = 1;
                break;
            }
            current = current->next;
        }

        //Random generator for new ID
        if (findNewID == 1){
           userId = userId + (rand() % (upper - lower + 1)) + lower; 
           findNewID = 0;
        }
        else{
            exit = 1;
        }
    }

    //Returning the computer generated userid
    printf("Your computer generated userid is %d.", userId);

    //Putting the data into a struct and returning the tweet
    tweetList = malloc(sizeof(tweet));
    tweetList -> id = userId;
    strcpy(tweetList->user, userName);
    strcpy(tweetList->text, userText);

    return tweetList;
}
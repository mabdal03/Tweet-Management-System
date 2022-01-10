#include "headerA3.h"

//Main function for A3
int main(void){

    //Defining default values
    tweet * tweetList = NULL;
    tweet * temp = NULL;
    int exit = 0, choice, returned;
    char choiceStr[5];

    //While loop that runs until the user chooses to exit
    while (exit == 0){

        //Printing menu and prompting user for their choice of input
        printf("1. Create a new tweet\n2. Display tweets\n3. Search a tweet (by keyword)\n4. Find how many words are \"stop words\"\n5. Delete the nth tweet\n6. Save tweets to a file\n7. Load tweets from a file\n8. Exit\nChoose a menu option: ");
        fgets(choiceStr, 5, stdin);
        sscanf(choiceStr, "%d", &choice);

        //If-else statements to determine course of action based on input
        if (choice == 1){

            //Creating a tweet and adding it to the end of a linked list
            temp = createTweet(tweetList);
            if (temp!=NULL){
                addNodeToList(&tweetList, temp);
                printf("\n");
            }
        }

        //Displaying all tweets
        else if (choice == 2){
            displayTweets(tweetList);
        }

        //Searching tweets by keyword
        else if (choice == 3){
            returned = searchTweetsByKeyword(tweetList);
            if (returned == 1){
                returned = 0;
            }
        }

        //Counting and outputting the # of stop words
        else if (choice == 4){
            countStopWords(tweetList);
        }

        //Deleting a tweet
        else if (choice == 5){
            deleteTweet(&tweetList);
        }

        //Saving tweets to a file
        else if (choice == 6){
            saveTweetsToFile(tweetList);
        }

        //Loading tweets from a file
        else if (choice == 7){
            loadTweetsFromFile(&tweetList);
        }

        //Exiting the program and freeing all nodes from the linked list
        else if (choice == 8){
            exit = 1;

            tweet * tmp;
            while (tweetList != NULL)
                {
                    tmp = tweetList;
                    tweetList = tweetList->next;
                    free(tmp);
                }
        }

        //Displaying whether an input was not a valid option
        else{
            printf("Error that is not a menu option!\n");
        }
        choice = 0;
    }

    return 0;
}


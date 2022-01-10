#include "headerA3.h"

//Function to remove a given tweet from the linked list, tweetList
void deleteTweet(tweet ** tweetList){
    //Defining initial values
    int choice, nodeCount = 0;
    char choiceStr[5];
    tweet * current = * tweetList;
    tweet * temp = * tweetList; 

    //Counting the # of nodes
    while (current != NULL) {
        nodeCount++;
        current = current->next;
    }

    int tempNodeCount = nodeCount;

    //Taking input from the user to ask which tweet they would like to delete
    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", nodeCount);
    fgets(choiceStr, 5, stdin);
    sscanf(choiceStr, "%d", &choice);
    choice = choice - 1;
    nodeCount = 0;

    //Printing the ID of the tweet the user deleted
    current = * tweetList;
    while (current != NULL) {
        if (nodeCount == choice){
            printf("Tweet %d deleted. There are now %d tweets left.\n",current->id, tempNodeCount - 1);
        }
        nodeCount++;
        current = current->next;
    }


    //If the linked list is empty, end the function
    if (*tweetList == NULL){
        return; 
    }
    
    //Statement to delete the head if it needs to be removed
    if (choice == 0) 
    { 
        *tweetList = temp->next;  
        free(temp); 
        return; 
    } 
    
    //Finding the previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < choice - 1; i++){
        temp = temp->next; 
    }
    
    //Statement to end function if the deleted choice is more than the # of nodes
    if (temp == NULL || temp->next == NULL){
        return; 
    }
    
    //Storing the pointer to the next of the node to be deleted
    tweet * next = temp -> next -> next; 
    
    //Freeing the node from the linked list 
    free(temp->next);
    
    //Unlinking the deleted node from list
    temp->next = next;   
}
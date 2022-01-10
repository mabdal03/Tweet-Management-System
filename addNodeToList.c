#include "headerA3.h"

//function to add a node to the linked list
void addNodeToList(tweet**tweetList, tweet * node){

    //dynamically allocating newNode
    tweet * newNode = malloc(sizeof(tweet));
    newNode-> id = node -> id;
    strcpy(newNode->user, node -> user);
    strcpy(newNode->text, node -> text);
    newNode -> next = NULL;

    //If the head is NULL, it's an empty list
    if(*tweetList == NULL)
         *tweetList = newNode;
    //Finding the last node and add the newNode
    else
    {
        tweet * lastNode = *tweetList;

        //Setting the last node's next address to NULL
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //Adding the new node at the end of the linked list
        lastNode-> next = newNode;
    }
}

#include "headerA3.h"

//Function to count the number of stop words
void countStopWords(tweet * tweetList){
    //Defining default values for the countStopWords function
    const int NUM_STOPWORDS = 25;
    int countStopWords = 0, countNodes = 0, character, word;
    char fullString[1000000], newString[100000][50]; 
    char stopWords[25][5] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};

    tweet * current = tweetList;

    //If statement and while loop to take all the text in the linked list and combine it into one char array for analysis
    if (current != NULL){
        strcpy(fullString, current->text);
        countNodes++;
        current = current->next;
    }
    while (current != NULL) {
        strcat(fullString," ");
        strcat(fullString, current->text);

        countNodes++;
        current = current->next;
    }

    //For loop to go through the fullString array of all text in the linked list and turn it into newString, a 2D char array seperating every word
    character=0; word=0;
    for(int i=0;i <= (strlen(fullString)); i++)
    {
        //If a space or NULL is found, assign terminator to the end of the word.
        if(fullString[i]== ' '|| fullString[i] == '\0')
        {
            newString[word][character]='\0';
            word++;  //Moving to the next word
            character=0; //Initiate the character index to zero for the next word
        }
        else
        {
            newString[word][character]=fullString[i];
            character++;
        }
    }

    //For loop to compare every word in the newString array to every stop word and count everytime a stop word is found
    for(int i=0; i < word; i++){
        for (int j = 0; j < NUM_STOPWORDS; j++){
            if (strcmp(newString[i], stopWords[j])==0){
                countStopWords++;
            }
        }
    }

    //Displaying # of stop words
    printf("Across %d tweets, %d stop words were found\n", countNodes, countStopWords);
}
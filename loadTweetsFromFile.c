#include "headerA3.h"

//Function to load tweets from a csv file
void loadTweetsFromFile(tweet ** tweetList){
    //Defining initial values
    char filename[50];
    char characterWords[10000][500];
    char * characterArray = malloc(sizeof(char*));
    int charIndex = 0, word, character, numCommas = 0;

    //Taking input for the filename
    printf("Enter a filename to load from: ");
    fgets(filename, 50, stdin);
    strtok(filename, "\n");

    //Opening the file
    FILE* openFile = NULL;
    openFile = fopen(filename, "r");

    //Returning whether or not the tweet imported correctly based on whether the file is NULL
    if (openFile!=NULL){
        printf("Tweets imported!\n");
    }
    else{
        printf("Error loading tweet!\n");
        return;
    }
    
    //Taking each character from the file and putting it into the array whilst reallocating the array size
    while (!feof(openFile))
    {
        characterArray[charIndex] = fgetc(openFile);
        charIndex++;
        characterArray = realloc(characterArray, sizeof(char*) * (charIndex + 1));
    }

    //Taking the character array and parsing it into a 2D char array, seperated by commas
    characterArray[charIndex] = '\0';
    character = 0; word = 0;
    for(int i = 0; i <= (strlen(characterArray)); i++)
    {
        //If a comma is found and there have been fewer than three commas, assign a terminator to the end of the word
        if((characterArray[i] == ',' && numCommas < 2)||characterArray[i] == '\0'||characterArray[i] == '\n')
        {
            numCommas++;
            characterWords[word][character] = '\0';
            word++; 
            character=0; 
            if (characterArray[i] == '\n'){
                numCommas = 0;
            }
        }
        else
        {
            //Else the character in the original array is equal to the character in the new.
            characterWords[word][character] = characterArray[i];

            //If there's a newline or a NULL terminator and the number of commas is greater than two, assign a NULL terminator to the end of the text and ignore the last comma
            if (numCommas >= 2 && (characterArray[i + 1] =='\n' || characterArray[i + 1] =='\0')){
                characterWords[word][character + 1] = '\0';
            }
            if (numCommas >= 2 && characterArray[i] == ',' && (characterArray[i + 1] == '\n' || characterArray[i + 2] == '\n' || characterArray[i + 1] == '\0'|| characterArray[i + 2] == '\0')){
                characterWords[word][character] = '\0';
            }
            if (numCommas >= 2 && characterArray[i] == ',' && (characterArray[i + 2] == '\n' || characterArray[i + 2] == '\0')){
                characterWords[word][character + 1] = '\0';
            }
            character++;
        }
    }

    tweet * current = malloc(sizeof(tweet));

    //For loop to take all inputted data and add them to the linked list
    for(int i=0; i < word; i = i + 3){
        if (atoi(characterWords[i]) != 0){
            current->id = atoi(characterWords[i]);
            strcpy(current->user, characterWords[i + 1]);
            strcpy(current->text, characterWords[i + 2]);
            addNodeToList(tweetList, current);
        }

    }    

    fclose(openFile);
}


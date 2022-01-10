Mohammed Abdallah
Last Edited: 2021/03/21

How to run the Program:
Make sure ALL included files are in the same file folder, including the makefile.
Simply type "make" into the command line and the program should compile without warnings
or issue. To run the program, type "./a3" into the command line. Once done with the program,
type "make clean" to remove all intermediate .o files as well as the final executable.

Explaining each part of the program:
When running the program, you're presented with a menu of 8 options:
1. Create a new tweet - is used to add a new tweet to the linked list, based on username and text of the tweet itself.
2. Display tweets - used to display data on all saved tweets in the linked list.
3. Search a tweet (by keyword) - used to search through the tweets and display ones including the same string of characters in text.
4. Find how many words are "stop words" - used to list the # of words in tweet texts that include "stop words."
5. Delete the nth tweet - used to delete a specific tweet in the linked list.
6. Save tweets to a file - used to save tweets to a file.
7. Load tweets from a file - used to load tweets from a file.
8. Exit - exit the program and free all nodes

Known inefficiencies with the program:
- In the function *countStopWords* it does not print the number of tweets searched based on grammar so if there was only
one tweet searched, it would return "Across 1 tweets, N stop words were found" which is not grammatically correct.

Future Improvements:
- I would like to fix the above known inefficiency with my program to make it more grammatically correct.
- Add a function to automatically save data from the linked list to a file called "autosave.csv" as tweets are added so that if the computer 
dies or crashes, everything is saved.

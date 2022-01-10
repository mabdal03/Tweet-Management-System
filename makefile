#makefile for A3

#defining variables based on object, source, and flags
OBJS	= mainA3.o createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o addNodeToList.o
SOURCE	= mainA3.c createTweet.c displayTweets.c searchTweetsByKeyword.c countStopWords.c deleteTweet.c saveTweetsToFile.c loadTweetsFromFile.c addNodeToList.c
CC	 = gcc
FLAGS	 = -g -c -Wall

#Makefile body, defining all executables and clean function
all: $(OBJS)
	$(CC) -g $(OBJS) -o a3

mainA3.o: mainA3.c 
	$(CC) $(FLAGS) mainA3.c -std=c99

createTweet.o: createTweet.c 
	$(CC) $(FLAGS) createTweet.c -std=c99

displayTweets.o: displayTweets.c 
	$(CC) $(FLAGS) displayTweets.c -std=c99

searchTweetsByKeyword.o: searchTweetsByKeyword.c 
	$(CC) $(FLAGS) searchTweetsByKeyword.c -std=c99

countStopWords.o: countStopWords.c 
	$(CC) $(FLAGS) countStopWords.c -std=c99

deleteTweet.o: deleteTweet.c 
	$(CC) $(FLAGS) deleteTweet.c -std=c99

saveTweetsToFile.o: saveTweetsToFile.c 
	$(CC) $(FLAGS) saveTweetsToFile.c -std=c99

loadTweetsFromFile.o: loadTweetsFromFile.c 
	$(CC) $(FLAGS) loadTweetsFromFile.c -std=c99

addNodeToList.o: addNodeToList.c
	$(CC) $(FLAGS) addNodeToList.c -std=c99

clean:
	rm -f $(OBJS) a3
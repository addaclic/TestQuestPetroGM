PROJECT_NAME = TestQuest
FLAGS = -Wall -Wextra -Werror -std=c++17
CC = g++

build:
	$(CC) $(FLAGS) $(PROJECT_NAME).cc -o $(PROJECT_NAME)
	
clean:
	rm $(PROJECT_NAME)
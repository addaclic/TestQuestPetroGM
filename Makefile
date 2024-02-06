PROJECT_NAME = TestQuest
FLAGS = -Wall -Wextra -Werror -std=c++17
CC = g++

build:
	@$(CC) $(FLAGS) $(PROJECT_NAME).cc -o $(PROJECT_NAME)
	@./$(PROJECT_NAME) < $(PROJECT_NAME).txt
	
clean:
	rm $(PROJECT_NAME)

my:
	$(CC) $(FLAGS) .vscode/game.cpp -o $(PROJECT_NAME)
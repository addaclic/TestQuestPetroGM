PROJECT_NAME = TestQuest
FLAGS = -Wall -Wextra -Werror -std=c++17
CC = g++

build:
	@$(CC) $(FLAGS) $(PROJECT_NAME).cc -o $(PROJECT_NAME)

test: build
	@./$(PROJECT_NAME) < TestsCase/$(PROJECT_NAME)01.txt
	@./$(PROJECT_NAME) < TestsCase/$(PROJECT_NAME)05.txt
	@./$(PROJECT_NAME) < TestsCase/$(PROJECT_NAME)06.txt

test_error1:
	@./$(PROJECT_NAME) < TestsCase/$(PROJECT_NAME)02.txt
test_error2:
	@./$(PROJECT_NAME) < TestsCase/$(PROJECT_NAME)03.txt
test_error3:
	@./$(PROJECT_NAME) < TestsCase/$(PROJECT_NAME)04.txt
	
clean:
	rm $(PROJECT_NAME)

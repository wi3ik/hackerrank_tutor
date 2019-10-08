#GCC=gcc

GCC=g++

RESULT=main
#LIB=$(C14) -Wall -Wextra -Werror -Wc++11-extensions
LIB=-std=c++14 -Wall -Werror -pedantic-errors


# g++ -std=c++14 -Wall -Wextra -pedantic-errors


SRC=main.cpp



	
all: main.cpp
	$(GCC)  $(LIB) $(SRC) -o $(RESULT) 

clean:
	rm -rf $(RESULT)


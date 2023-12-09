CC      := g++
FLAGS   := -std=c++20
INCLUDE := -I../utils

DEBUG := 1

ifeq ($(DEBUG),1)
	FLAGS += -g -fsanitize=address
else
	FLAGS += -O3
endif

test: test.cpp exercise_1 exercise_2
	$(CC) -o test test.cpp exercise_1.o exercise_2.o $(FLAGS) $(INCLUDE) -lCatch2
	./test

retest: clean test

app: main.cpp exercise_1 exercise_2
	$(CC) -o app main.cpp exercise_1.o exercise_2.o $(FLAGS) $(INCLUDE)
	./app

exercise_1: exercise_1.cpp exercise_1.hpp
	$(CC) -c exercise_1.cpp $(FLAGS) $(INCLUDE)

exercise_2: exercise_2.cpp exercise_2.hpp
	$(CC) -c exercise_2.cpp $(FLAGS) $(INCLUDE)

clean:
	rm -f main_draft test
	rm *.o

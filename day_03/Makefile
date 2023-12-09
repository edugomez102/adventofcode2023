CC      := g++
FLAGS   := -std=c++20 -g -fsanitize=address
INCLUDE := -I../utils

test: test.cpp exercise_1 exercise_2
	$(CC) -o test test.cpp exercise_1.o exercise_2.o $(FLAGS) $(INCLUDE) -lCatch2
	./test

retest: clean test

draft: draft.cpp exercise_1 exercise_2
	$(CC) -o main_draft draft.cpp exercise_1.o exercise_2.o $(FLAGS) $(INCLUDE)
	./main_draft

exercise_1: exercise_1.cpp exercise_1.hpp
	$(CC) -c exercise_1.cpp $(FLAGS) $(INCLUDE)

exercise_2: exercise_2.cpp exercise_2.hpp
	$(CC) -c exercise_2.cpp $(FLAGS) $(INCLUDE)

clean:
	rm -f main_draft test
	rm *.o

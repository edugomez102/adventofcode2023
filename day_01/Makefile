CC      := g++
FLAGS   := -std=c++20 -g -fsanitize=address

test: test.cpp exercise
	$(CC) -o test test.cpp exercise.o $(FLAGS) -lCatch2
	./test

retest: clean test

draft: draft.cpp exercise
	$(CC) -o main_draft draft.cpp exercise.o $(FLAGS)
	./main_draft

exercise: exercise.cpp exercise.hpp
	$(CC) -c exercise.cpp $(FLAGS)

clean:
	rm -f main_draft test
	rm *.o

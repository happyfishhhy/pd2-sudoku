project1 : main.o Sudoku.o
	g++ -o project1 main.o Sudoku.o

main.o : main.cpp Sudoku.h
	g++ -c main.cpp


function.o : Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

clean : Sudoku.o main.o
	rm Sudoku.o main.o

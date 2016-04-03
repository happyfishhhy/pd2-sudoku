project1 : main.o Sudoku.o
	g++ -o project1 main.o Sudoku.o

main.o : main.cpp sudoku.h
	g++ -c main.cpp


function.o : Sudoku.cpp sudoku.h
	g++ -c Sudoku.cpp

clean : Sudoku.o main.o
	rm Sudoku.o main.o

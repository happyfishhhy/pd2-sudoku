#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Sudoku
{
	public : 
		int question[9][9];
		int input[9][9];
		int answer[9][9];
		int temp[9][9];
		int result;
		void giveQuestion();
		void change();
		void readIn();
		void changeNum(int a, int b);
		void changeRow(int a, int b);
		void changeCol(int a, int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void solve();
		int solvess(int a[9][9],int n);
		bool checkRow(int a[9][9]);
		bool checkCol(int a[9][9]);
		bool writeanswer(int a[9][9],int row,int col,int num);
		void printOutanswer(int a[9][9]);
};

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "sudoku.h"
#include <stdio.h>
using namespace std;

int main()
{
	//int question[9][9];
	//int result;
	Sudoku ss;

	ss.readIn();
	ss.solve(ss.input,0);
	if(ss.result==0)
	cout<<"0"<<endl;
	
	return 0;

}

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "sudoku.h"
#include <stdio.h>
using namespace std;

int main()
{
	Sudoku ss;

	ss.readIn();
	ss.solve();
	if(ss.result==0)
	cout<<"0"<<endl;
	
	return 0;

}

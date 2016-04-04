#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Sudoku.h"
#include <stdio.h>
using namespace std;

int main()
{
	Sudoku ss;

	ss.readIn();
	ss.solve();
	
	return 0;

}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Sudoku.h"
using namespace std;


void Sudoku::giveQuestion()
{
	int question[9][9]={{1,0,0,0,0,0,0,0,4},
						{0,8,3,0,0,0,1,2,0},
						{0,0,6,3,0,7,8,0,0},
						{0,0,0,5,0,2,0,0,0},
						{0,0,0,0,9,0,0,0,0},
						{0,0,0,6,0,4,0,0,0},
						{0,0,9,2,0,8,6,0,0},
						{0,2,7,0,0,0,3,9,0},
						{4,0,0,0,0,0,0,0,1}};
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << question[i][j] << " ";;
		}
		cout << "\n";
	}

}       				
void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3, rand()%3);
	changeCol(rand()%3, rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
void Sudoku::readIn()
{
	int number;
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin >> number;
			input[i][j]=number;
		}
	}
}

void Sudoku::changeNum(int a, int b)
{
	int temp[9][9]={0};
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			temp[i][j]=input[i][j];
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			temp[i][j]=input[i][j];
			if(input[i][j]==a)
			input[i][j]=b;
			if(temp[i][j]==b)
			input[i][j]=a;
		}
	}
}


void Sudoku::changeRow(int a, int b)
{
	if(a==0)
	{
		if(b==1)
		{
			for(int j=0;j<9;j++)
			{
				swap(input[0][j],input[3][j]);
				swap(input[1][j],input[4][j]);
				swap(input[2][j],input[5][j]);	
			}
		}	
		if(b==2)
		{
			for(int j=0;j<9;j++)
			{
    	       	swap(input[0][j],input[6][j]);
    			swap(input[1][j],input[7][j]);
				swap(input[2][j],input[8][j]);
			}
		}
	}
	if(a==1)
	{
		if(b==2)
		{
			for(int j=0;j<9;j++)
			{
    	       	swap(input[3][j],input[6][j]);
 				swap(input[4][j],input[7][j]);
				swap(input[5][j],input[8][j]);
			}
		}
		if(b==0)
		{
			for(int j=0;j<9;j++)
			{
				swap(input[0][j],input[3][j]);
				swap(input[1][j],input[4][j]);
				swap(input[2][j],input[5][j]);
			}	
		}		
	}
	if(a==2)
	{
		if(b==0)
		{
			for(int j=0;j<9;j++)
			{
				swap(input[0][j],input[6][j]);
				swap(input[1][j],input[7][j]);
				swap(input[2][j],input[8][j]);
			}	
		}
		if(b==1)
		{
			for(int j=0;j<9;j++)
			{
				swap(input[3][j],input[6][j]);
				swap(input[4][j],input[7][j]);
				swap(input[5][j],input[8][j]);
			}
		}
	}
}
void Sudoku::changeCol(int a, int b)
{
   	if(a==0)
	{
		if(b==1)
		{
			for(int i=0;i<9;i++)
			{
				swap(input[i][0],input[i][3]);
				swap(input[i][1],input[i][4]);
				swap(input[i][2],input[i][5]);
			}
		}
		if(b==2)
		{
			for(int i=0;i<9;i++)
			{
				swap(input[i][0],input[i][6]);
				swap(input[i][1],input[i][7]);
				swap(input[i][2],input[i][8]);
			}
		}
	}
	if(a==1)
	{
		if(b==2)
		{
			for(int i=0;i<9;i++)
			{
				swap(input[i][3],input[i][6]);
				swap(input[i][4],input[i][7]);
				swap(input[i][5],input[i][8]);
			}
		}
		if(b==0)
		{
			for(int i=0;i<9;i++)
			{
				swap(input[i][0],input[i][3]);
				swap(input[i][1],input[i][4]);
				swap(input[i][2],input[i][5]);
			}
		}
	}
	if(a==2)
	{
		if(b==0)
		{
			for(int i=0;i<9;i++)
			{
				swap(input[i][0],input[i][6]);
				swap(input[i][1],input[i][7]);
				swap(input[i][2],input[i][8]);	
			}
		}
		if(b==1)
		{
			for(int i=0;i<9;i++)
			{
				swap(input[i][3],input[i][6]);
				swap(input[i][4],input[i][7]);
				swap(input[i][5],input[i][8]);
			}
		}
	}
}
void Sudoku::rotate(int n)
{
	int temp[9][9]={0};
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			temp[i][j]=input[i][j];
		}
	}
	
	if(n%4==0)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				temp[i][j]=input[i][j];
			}
		}
	}
	
	if(n%4==1)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				temp[i][j]=input[8-j][i];
			}
		}
	}

	if(n%4==2)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				temp[i][j]=input[8-i][8-j];
			}
		}
	}

	if(n%4==3)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				temp[i][j]=input[j][8-i];
			}
		}
	}

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			input[i][j]=temp[i][j];
		}
	}
}
void Sudoku::flip(int n)
{
	if(n==1)
	{	   
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<9;j++)
			{
				swap(input[i][j],input[8-i][j]);
			}
		}
	}
	else
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<4;j++)
			{
				swap(input[i][j],input[i][8-j]);
			}
		}
	}
}
void Sudoku::transform()
{
	change();
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << input[i][j] << " ";
		}
		cout<<"\n";
	}
}

void Sudoku::solve()
{
	if(checkRow(input))
	{
		cout << 0 << endl;
		return;
	}
	if(checkCol(input))
	{
		cout << 0 << endl;
		return;
	}
	solvess(input,0);
	if(result==0)
	{
		cout << 0 << endl;
		return;
	}
	if(result==2)
	{
		cout << 2 << endl;
		return;
	}
	if(result==1);
	{
		cout << 1 << endl;
		printOutanswer(answer);
		return;
	}
}

int Sudoku::solvess(int a[9][9],int position)
{	
	int i,j,k;
	int A,B;
	int record[9][9];
	bool mark;
	
	if(result>1)
	{
		return 2;
	}
	for(i=0;i<9;i++)
	{	
		for(j=0;j<9;j++)
		{
			record[i][j]=a[i][j];
		}
	}
	i=position/9;
	j=position%9; 
	
	if(a[i][j]!=0) 
	{
		if(position==80) 
		{
			result++;
			//printOutanswer(record);
			for(A=0;A<9;A++)
				for(B=0;B<9;B++)
					answer[A][B]=record[A][B];
		}
		else 
		{
			solvess(record,position+1);
		}
	}
	else 
	{
		for(k=1;k<=9;k++)
		{
			mark=writeanswer(record,i,j,k);
			if(mark) 
			{
				record[i][j]=k; 
				if(position==80)
				{
					result++;
					//printOutanswer(record);
					if(result==1)
					{
						for(A=0;A<9;A++)
						{
							for(B=0;B<9;B++)
								answer[A][B]=record[A][B];
						}
					}
				}
				else
				solvess(record,position+1);
				record[i][j]=0; 
	 		}
		}	
	}
}

void Sudoku::printOutanswer(int a[9][9])
{
	//Sudoku::result++;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}


bool Sudoku::writeanswer(int a[9][9],int row,int col,int num)
{
	int i,j;
	
	for(j=0;j<9;j++)
	{
		if(a[row][j] == num)
		{
			return false;
		}
	}

	for(i=0;i<9;i++)
	{
		if(a[i][col] == num)
		{
			return false;
		}
	}

	int table1=(row/3)*3,table2=(col/3)*3;
	for(i=table1;i<table1+3;i++)
	{
		for(j=table2;j<table2+3;j++)
		{
			if(a[i][j]==num)
			{
				return false;
			}
       }
	}

	return true;
}



bool Sudoku::checkRow(int a[9][9])
{
	int check[9]={0};
	
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(a[i][j]!=0)
			{
				check[a[i][j]-1]++;
			}
		}
		for(int k=0;k<9;k++)
		{
			if(check[k]>1)
			{
				return true;
			}
			else check[k]=0;
		}
	}
	return false;
}

bool Sudoku::checkCol(int a[9][9])
{
	int check[9]={0};

	for(int j=0;j<9;j++)
	{
		for(int i=0;i<9;i++)
		{
			if(a[i][j]!=0)
			{
				check[a[i][j]-1]++;
			}
		}
		for(int k=0;k<9;k++)
		{
			if(check[k]>1)
			{
				return true;
			}
			else check[k]=0;
		}
	}
	return false;
}


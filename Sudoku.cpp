#include <iostream>
#include <cstdlib>
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
			cout << question[i][j];
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
	for(int i=0;i<9;i++)
	{
		cout<<"請输入第"<<i+1<<"列的9個數字："<<endl;
		for(int j=0;j<9;j++)
		scanf("%d",&Sudoku::input[i][j]);
	}
	if(checkRow(Sudoku::input)==true)
	{
		cout << "The question is wrong ! "<<endl;
		return;
	}
	if(checkCol(Sudoku::input)==true)
	{
		cout << "The question is wrong ! "<<endl;
		return;
	}

}

void Sudoku::changeNum(int a, int b)
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<0;j++)
		{
			if(Sudoku::input[i][j]==a)
			Sudoku::input[i][j]==b;
			else if(Sudoku::input[i][j])
				Sudoku::input[i][j]=a;
		}
	}
}


void Sudoku::changeRow(int a, int b)
{
	if(a=0,b=1)
	{
		for(int j=0;j<9;j++)
		{
			swap(Sudoku::input[0][j],Sudoku::input[3][j]);		
		}
	}
	if(a=0,b=2)
	{
		for(int j=0;j<9;j++)
		{
           	swap(Sudoku::input[0][j],Sudoku::input[6][j]);
    	}
	}
	if(a=1,b=2)
	{
		for(int j=0;j<9;j++)
		{
           	swap(Sudoku::input[3][j],Sudoku::input[6][j]);
 		}
	}
}
void Sudoku::changeCol(int a, int b)
{
   	if(a=0,b=1)
	{
		for(int i=0;i<9;i++)
		{
			swap(Sudoku::input[i][0],Sudoku::input[i][3]);
		}
	}
	if(a=0,b=2)
	{
		for(int i=0;i<9;i++)
		{
			swap(Sudoku::input[i][0],Sudoku::input[i][6]);
		}
	}
	if(a=1,b=2)
	{
		for(int i=0;i<9;i++)
		{
			swap(Sudoku::input[i][3],Sudoku::input[i][6]);
		}
	}
}
void Sudoku::rotate(int n)
{
	n%=4;
	while(n--)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				swap(Sudoku::input[j][8-i],Sudoku::input[i][j]);
			}
		}
	}
}
void Sudoku::flip(int n)
{
	if(n)
	{	   
		for(int i=0,tmp;i<4;i++)
		{
			for(int j=0;j<9;j++)
			{
				swap(Sudoku::input[i][j],Sudoku::input[8-i][j]);
			}
		}
	}
	else
	{
		for(int i=0,tmp;i<9;i++)
		{
			for(int j=0;j<4;j++)
			{
				swap(Sudoku::input[i][j],Sudoku::input[i][8-j]);
			}
		}
	}
}
void Sudoku::transform()
{
	readIn();
	change();
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << Sudoku::input[i][j];
		}
		cout<<"\n";
	}
}

void Sudoku::solve()
{
	solvess(input,0);
}

void Sudoku::solvess(int a[9][9],int p)
{	
	int i,j,k;
	int record[9][9];
	
	for(i=0;i<9;i++)
	{	
		for(j=0;j<9;j++)
		{
			record[i][j]=a[i][j];
		}
	}
	i=p/9;
	j=p%9; 
	if(a[i][j] != 0) 
	{
		if(p==80) 
		{
			printOutanswer(record);
		}
		else 
		{
			solvess(record,p+1);
		}
	}
	else 
	{
		for(k=1;k<=9;k++)
		{
			bool flag=writeanswer(record,i,j,k);
			if(flag) 
			{
				record[i][j]=k; 
				if(p==80)
				printOutanswer(record);
				else
				solvess(record,p+1);
				record[i][j]=0; 
	 		}
		}
	}
}

void Sudoku::printOutanswer(int a[9][9])
{
	Sudoku::result++;
	cout <<"\n" <<result <<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << a[i][j];
			if((j==2)||(j==5))
			cout << " ";
		}
		cout << "\n";
		if((i==2)||(i==5))
		{
			cout << "\n";
		}
	}
	cout << "\n";
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
			if(a[i][j] == num)
			return false;
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
			return true;
			else check[k]=0;
		}
	}
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
			return true;
			else check[k]=0;
		}
	}
}


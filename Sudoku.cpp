#include<bits/stdc++.h>
using namespace std;
#define N 9
int a[N][N];
int i,j;
int domain[]={1,2,3,4,5,6,7,8,9};

/*
    SUDOKU USING CSP(Backtracking)

    -9x9 Matrix:
    -Input: 81 Values
    -81 Variables - Each representing the value of a cell
    -Domain of values that each cell can take: ={1,2,3,4,5,6,7,8,9} (for non-empty cells)
    -Output: Sudoku Matrix of (9x9) if solution exists else Prints "No Solution Exists"

*/

void input()
{
  cout<<"ENTER THE VALUES OF THE SUDOKU GRID {1-9}. (Enter 0 for empty cell)"<<endl;
  cout<<"-----------------------------------------   -----------------------"<<endl;
  for(i=0;i<9;i++)
  {
    for(j=0;j<9;j++)
    {
      cin>>a[i][j];      
    }
  }
}
bool findempty(int& row, int& col) 
{ 
    for (row = 0; row < N; row++) 
        for (col = 0; col < N; col++) 
            if (a[row][col] == 0) 
                return true; 
    return false; 
} 
bool checkmatrix(int startrow, int startcol, int num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (a[row + startrow][col + startcol] == num) 
                return true; 
    return false;   
} 
bool checkcol(int col, int num) 
{ 
    for (int row = 0; row < N; row++) 
        if (a[row][col] == num) 
            return true; 
    return false; 
} 
bool checkrow(int row, int num) 
{ 
    for (int col = 0; col < N; col++) 
        if (a[row][col] == num) 
            return true; 
    return false; 
} 
bool checkconstraints(int row, int col, int num) 
{ 
    return (!checkrow(row, num) && !checkcol(col, num) && !checkmatrix(row - row % 3,col - col % 3, num) 
           && a[row][col] == 0); 
} 
bool sudoku_solve()
{
    int row, col;  
    if (!findempty(row, col)) 
    {
        cout<<"\n THE GRID IS FULL \n";
        return true;
    }
    for (int num = 1; num <= 9; num++) 
    { 
        if (checkconstraints(row, col, num)==true) 
        { 
            a[row][col] = num; 
            if (sudoku_solve()) 
            {
                return true;
            }
            else
            {
                a[row][col] = 0;
            }
        } 
    }  
    return false; 
}
void display()
{
    cout<<endl<<endl;
    cout<<"THE SUDOKU BOARD"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
      {
        if(j==0 || j==3 || j==6)
        {
          cout<<"|"<<" "<<a[i][j]<<" "<<"|"<<" ";
        }
        else if(j==8)
        {
          cout<<a[i][j]<<"|";
        }
        else
        {
          cout<<a[i][j]<<" "<<"|"<<" ";
        }
      }
      cout<<endl;
      if(i==2 || i== 5)
      {
        cout<<"-----------------------------------------"<<endl;
        
      }
    }
    cout<<"-----------------------------------------"<<endl;
}
int main()
{
  input();
  bool b = sudoku_solve();
  if(b)
  {
    display();
  }
  else
  {
    cout<<"\nNo Solution Exists";
  }
}
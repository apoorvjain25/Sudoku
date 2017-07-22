
#include <iostream>
#include "checkfns.h"
#define ORDER 9

using namespace std;

extern int sudoku[ORDER][ORDER];
int check (int y[]);
int temp[ORDER];

int rowCheck ( int x[ORDER][ORDER]) {
  for (int i=0; i<ORDER; i++) {
    for (int j= 0; j<ORDER; j++)
      temp[j] = x[i][j];
			
    if ( check (temp) == 0 )
      return 0;
  }
  return 1;
}
							
int check (int y[ORDER]) {
  int lineartemp;
  for (int i=0; i<ORDER; i++) {
    lineartemp = y[i];
    for (int j=i+1; j<ORDER; j++) { //searches for duplications
      if (y[j] ==  lineartemp)
	return 0;
	  }
  }
  return 1;
}

int columnCheck ( int x[ORDER][ORDER]) {
  for (int i=0; i<ORDER; i++) {
    for (int j= 0; j<ORDER; j++)
      temp[j] = x[j][i];
		
    if ( check (temp) == 0 )
      return 0;
  }
  return 1;
}			

int SquaresCheck (int x[ORDER][ORDER]) {

  int i;
  int j;
  int column;
  int row;
  int k;
	
  for (column=0; column <= 6; column += 3) {
    for (row=0; row <= 6; row += 3) {
      for (k=0, i=0; i<3; i++) {
	for (j=0; j<3; j++)
	  temp[k++] = x[row+i][column+j];
      }
      if (check(temp) ==0)
	return 0;		
    }
  }
	
  return 1;
}

int checkSolution() 
{
  if ( !rowCheck(sudoku) || !columnCheck(sudoku) || !SquaresCheck(sudoku) )
     return 0;
  else
     return 1;
}

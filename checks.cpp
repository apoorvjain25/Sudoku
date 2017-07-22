
#include "checkfns.h"
#define ORDER 9
extern int sudoku[ORDER][ORDER];
int checkRow(int row, int num) 
{
  int foundnum = 0;
  for (int i = 0; i < 9; i++) {
    if (sudoku[row][i] == num) {
      foundnum = 1;
      break;
    }
  }
  if (foundnum == 1)
    return 0;
  else
    return 1;
}

int checkColumn(int column, int num) 
{
  int foundnum = 0;
  for (int i = 0; i < 9; i++) {
    if (sudoku[i][column] == num) {
      foundnum = 1;
      break;
    }
  }
  if (foundnum == 1)
    return 0;
  else
    return 1;
}

int checkSquare(int row, int column, int num) 
{
  int foundnum = 0;
  int startIndexRow = (row / 3) *   3;
  int startIndexColumn = (column / 3) *   3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (sudoku[startIndexRow + i][startIndexColumn + j] == num ){
        foundnum = 1;
        break;
      }
    }
  }
  if (foundnum == 1)
    return 0;
  else
    return 1; 
}

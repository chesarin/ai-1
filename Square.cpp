/*Cesar Vargas
 *AI Fall 2010
 *Square.cpp
 */
#include "Square.h"
Square::Square(){
  for ( int row=1 ; row < 4 ; row++)
    for ( int col=1 ; col < 4 ; col++)
      board[row][col]=0;
}
void Square::set_row(const int a[], int row){
  for(int col=1; col < 4 ; col++)
    set_value(row,col,a[col]);
}
void Square::set_value(int row, int col, int val){
  board[row][col]=val;
}
int Square::get_value(int row, int col){
  return board[row][col];
}
void Square::print(){
  for ( int row=1 ; row < 4 ; row++ ){
    for ( int col=1 ; col < 4 ; col++ ){
      cout << board[row][col];
    }
    cout << endl;
  }
}
bool Square::operator==(const Square &other){
  int counter=0;
  int i,j;
  for (i=1; i<4 ; i++){
    for (j=1; j<4 ; j++){
      if (board[i][j] == other.board[i][j])
	counter++;
    }
  }
  if ( counter == 9 )
    return true;
  return false;
}
int Square::diff(const Square &other){
  int counter=0;
  int i,j;
  for (i=1; i<4 ; i++){
    for (j=1; j<4 ; j++){
      if (board[i][j] != other.board[i][j])
	counter++;
    }
  }
  return counter;
}
void Square::find_zero(){
  int i,j;
  for ( i=1 ; i < 4 ; i++){
    for ( j=1 ; j < 4 ; j++ ){
      if ( board[i][j] == 0 ){
	zrow=i;
	zcol=j;
      }//end of if 
    }//end for j
  }//end for i
}
void Square::exchange(int ir,int ic,int fr,int fc){
  int temp = board[ir][ic];
  board[ir][ic] = board[fr][fc];
  board[fr][fc] = temp;
}
void Square::move_up(){
  exchange(zrow,zcol,zrow-1,zcol);
}
void Square::move_bottom(){
  exchange(zrow,zcol,zrow+1,zcol);
}
void Square::move_left(){
  exchange(zrow,zcol,zrow,zcol-1);
}
void Square::move_right(){
  exchange(zrow,zcol,zrow,zcol+1);
}
bool Square::can_move_up(){
  if ( zrow-1 >= 1 )
    return true;
  return false;
}
bool Square::can_move_bottom(){
  if ( zrow+1 <= 3 )
    return true;
  return false;
}
bool Square::can_move_left(){
  if ( zcol-1 >= 1 )
    return true;
  return false;
}
bool Square::can_move_right(){
  if ( zrow+1 <= 3 )
    return true;
  return false;
}

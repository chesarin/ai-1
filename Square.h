/*Cesar Vargas
 *AI Fall 2010
 *Square.h
 */
#ifndef SQUARE_H_
#define SQUARE_H_
#include <iostream>
using namespace std;
class Square{
 public:
  Square();
  int get_value(int row, int col);
  void move(int s_row,int s_col,int d_row,int d_col);
  bool is_full();
  void set_row(const int a[], int row);
  void print();
  bool operator==(const Square &other);
  friend ostream& operator<<(ostream &os, Square s);
  int diff(const Square &other);
  void find_zero();
  void exchange(int ir, int ic, int fr, int fc);
  void move_up();
  void move_bottom();
  void move_left();
  void move_right();
  bool can_move_up();
  bool can_move_bottom();
  bool can_move_left();
  bool can_move_right();
 private:
  int zrow,zcol;
  void set_value(int row, int col, int val);
  int counter;
  const static int row = 4;
  const static int col = 4;
  int board[row][col];
};
#endif

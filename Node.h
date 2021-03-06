/*Cesar Vargas
 *AI Fall 2010
 *Node.h
 */
#ifndef NODE_H_
#define NODE_H_
/* #include <iostream> */
#include "Square.h"
/* using namespace std; */
class node{
 public:
  node(){ parent=NULL;};
 node(Square in,node* q=0):data(in),parent(q),g(0){};
  bool operator==(const node &other);
  bool operator<(const node &other);
  void inc_g();
  void set_link(node* link);
  int diff(const node &other);
  void create_state(const node &other);
  friend ostream& operator<<(ostream &os, node s);
  void find_zero();
  bool can_move_up();
  bool can_move_right();
  bool can_move_bottom();
  bool can_move_left();
  void move_up();
  void move_right();
  void move_bottom();
  void move_left();

  // private:
  Square data;
  node* parent;
  int f,g,h;
};
#endif

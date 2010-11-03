/*
 *Cesar Vargas
 *AI
 *Queens College Fall 2010
 *Astar.h
 */
#ifndef ASTAR_H_
#define ASTAR_H_
#include "Node.h"
#include "Queue.h"
#include "Square.h"
#include <iostream>
#include <list>
using namespace std;
class Astar{
 public:
 Astar(Square s,Square g):start(s),goal(g){}
  void begin();
  bool isGoal(node in, node g);
  void expand(node &input);
  node find_goal();
  void add_expanded(list<node> &temp,node &father);
  bool is_member_openlist(node in);
  bool is_member_closedlist(node in);
  void print_list(list<node> &tlist, string name);
  void add_expanded_list(list<node> &tlist, node &in);
  bool is_node_in_list(node &tempnode,list<node> &tlist);
 private:
  node start,goal;
  Queue<node> openlist;
  Queue<node> closedlist;
  list<node> test1;
  list<node> test2;
};
#endif

/*Cesar Vargas
 *AI Fall 2010
 *SearchAlg.h
 */
#include <iostream>
#include "Queue.h"
#include "Square.h"
using namespace std;
class node{
 public:
  node(){}
  node(Square in, node* q=0):data(in),parent(q){}
  bool operator==(const node &other);
  Square data;
  node* parent;
};
bool node::operator==(const node &other){
  if ( data == other.data )
    return true;
  return false;
}
class SearchAlg{
 private:
  node start;
  node goal;
  Queue<node> openlist;
  Queue<node> closedlist;
 public:
  SearchAlg();
  SearchAlg(Square sstart, Square sgoal);
  bool are_we_there(const node &in, const node &goal);
  void go();
};
SearchAlg::SearchAlg(Square sstart, Square sgoal){
   start(sstart); goal(sgoal);
   go();
}
bool SearchAlg::are_we_there(const node &in, const node &goal){
  if ( in == goal )
    return true;
  return false;
}
void SearchAlg::go(){
  if(are_we_there(in,goal))
    cout << "We have reach our destination" << endl;
  cout << "not there yet" << endl;
}

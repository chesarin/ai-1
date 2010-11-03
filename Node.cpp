/*Cesar Vargas
 *AI Fall 2010
 *Node.h
 */
#include "Node.h"
bool node::operator==(const node &other){
  if ( data == other.data )
    return true;
  return false;
}
bool node::operator<(const node &other){
  if ( f < other.f )
    return true;
  return false;
}
void node::inc_g(){
  g++;
}
int node::diff(const node &other){
  return data.diff(other.data);
}
void node::create_state(const node &other){
  h = diff(other);
  f = g + h;
}
void node::find_zero(){
  data.find_zero();
}
bool node::can_move_up(){
  return data.can_move_up();
}
bool node::can_move_right(){
  return data.can_move_right();
}
bool node::can_move_bottom(){
  return data.can_move_bottom();
}
bool node::can_move_left(){
  return data.can_move_left();
}
void node::move_up(){
  data.move_up();
}
void node::move_right(){
  data.move_right();
}
void node::move_bottom(){
  data.move_bottom();
}
void node::move_left(){
  data.move_left();
}
void node::set_link(node* link){
  parent = link;
}

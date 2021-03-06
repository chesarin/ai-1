/*Cesar Vargas
 *Astar.cpp
 *Artificial Intelligence 2010
 *Queens College, CUNY 2010
 */
#include "Astar.h"
void Astar::begin(){
  //let's create a new state from the start node using the start node
  //double check the naming it's confusing
  start.create_state(start);
  //push to the front of the openlist list, this should be the openlist
  openlist.push_front(start);
  //let's create a node called current
  node current_node;
  //let's check there is nothing on the open list
  while( !openlist.empty() ){
    //let's print the open list
    print_list(openlist, "Open");
    //store the front of the open list on the current_node
    current_node = openlist.front();
    //delete it from the open list queue
    openlist.pop_front();
    //add current_node to the closed list
    closedlist.push_front(current_node);
    //check if the node just popped actually the goal
    //if it is we just print it here but something else needs to be done.
    if ( isGoal(current_node,goal) ){
      cout << "We have reached the goal" << endl;
      cout << current_node << endl;
      break;
    } else {
      //else let's expand the currnent node
      cout << "Not yet, let's expand the current_node node." << endl;
      cout << current_node << endl;
      expand(current_node);
      openlist.sort();
    }
  }
}
bool Astar::isGoal(node in, node g){
  if ( in == g )
    return true;
  return false;
}
/*expand(node input) this function takes a node and it expands it, by
 *that we mean that it finds where the zero element is and then 
 *it tries to see if it can move up, down, left and right. If so 
 *then it adds all these nodes into the templist list.
 */
void Astar::expand(node &input){
  cout << "We are in the expanding function. " << endl;
  node tempn;
  list<node> templist;
  input.find_zero();
  if ( input.can_move_up() ){
    tempn = input;
    tempn.move_up();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_back(tempn);}
  if ( input.can_move_right() ){
    tempn = input;
    tempn.move_right();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_back(tempn);}
  if ( input.can_move_bottom() ){
    tempn = input;
    tempn.move_bottom();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_back(tempn);}
  if ( input.can_move_left() ){
    tempn = input;
    tempn.move_left();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_back(tempn);}
  //let's print the templist elements
  print_list(templist,"Temporary");
  //let's add the nodes we just created into the openlist
  add_expanded(templist,input);
  //  add_expanded(tempq,input);}
}
ostream& operator<<(ostream &os, Square s){
  int i,j;
  for ( i=1; i < 4; i++ ){
    for( j=1; j < 4 ; j++ ){
      os << s.board[i][j];
    }
  }
  return os;
}
ostream& operator<<(ostream &os, node s){
  return  os << s.data << " h " << s.h << " g " << s.g << " f " << s.f << " ";
}
void Astar::add_expanded(list<node> &temp, node &father){
  node added;
  list<node>::iterator it;
  while ( !temp.empty() ){
    added = temp.front();
    temp.pop_front();
    if ( !is_member_openlist(added) && !is_member_closedlist(added) ){
      added.set_link(&father);
      openlist.push_back(added);
    } else {
      if ( is_member_openlist(added) ){
	for ( it=openlist.begin() ; it != openlist.end() ; it++ ){
	  if ( *it == added && added.f < it->f ){
	    it->f = added.f;
	    it->h = added.h;
	    it->h = added.g;
	    it->set_link(&father);
	  }//end of first inner if
	}//end of iterator
      }//end of outer if
      if ( is_member_closedlist(added) ){
	for ( it=closedlist.begin() ; it != closedlist.end() ; it++ ){
	  if ( *it == added && added.f < it->f ){
	    closedlist.remove(*it);
	    added.set_link(&father);
	    openlist.push_back(added);
	  }//end of first inner if
	}//end of iterator
      }//
    }//end of second inner if
  }//end of else
}
bool Astar::is_member_openlist(node in){
  list<node>::iterator it;
  bool sentinel = false;
  for ( it=openlist.begin() ; it != openlist.end() ; it++ ){
    if ( in == *it )
      sentinel=true;
  }
  return sentinel;
}
bool Astar::is_member_closedlist(node in){
  list<node>::iterator it;
  bool sentinel = false;
  for ( it=closedlist.begin() ; it != closedlist.end() ; it++ ){
    if ( in == *it )
      sentinel=true;
  }
  return sentinel;
}
void Astar::print_list(list<node> &tlist, string name){
  list<node>::iterator it;
  cout << name <<  " contains:";
  for ( it = tlist.begin() ; it != tlist.end() ; ++it )
    cout << " " << *it;
  cout << endl;
}
bool Astar::is_node_in_list( node &tempnode, list<node> &tlist){
  bool decision=false;
  list<node>::iterator it;
  for ( it = tlist.begin() ; it != tlist.end() ; it++ ){
    if ( tempnode == *it ){
      decision = true;
      break;
    }
  }
  return decision;
}

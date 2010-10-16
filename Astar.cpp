#include "Astar.h"
void Astar::begin(){
  start.create_state(start);
  //  openlist.insert(start);
  test1.push_front(start);
  node current_node;
  //  while( !openlist.isEmpty() ){
  while( !test1.empty() ){
    //    current_node = openlist.del();
    current_node = test1.front();
    test1.pop_front();
    if ( isGoal(current_node,goal) ){
      cout << "We have reached the goal" << endl;
      cout << current_node << endl;
      break;
    } else {
      cout << "Not yet, let's expand the current_node node." << endl;
      cout << current_node << endl;
      expand(current_node);
    }
  }
  // if ( start.data == goal.data )
  //   cout << " we have reached out goal" << endl;
  // cout << " we have not reached out goal " << endl;
}
bool Astar::isGoal(node in, node g){
  if ( in == g )
    return true;
  return false;
}
void Astar::expand(node input){
  cout << "We are in the expanding function. " << endl;
  node tempn;
  //  Queue<node> tempq;
  list<node> templist;
  input.find_zero();
  if ( input.can_move_up() ){
    tempn = input;
    tempn.move_up();
    tempn.inc_g();
    tempn.create_state(goal);
    //    tempq.insert(tempn);}
    templist.push_front(tempn);}
  if ( input.can_move_right() ){
    tempn = input;
    tempn.move_right();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_front(tempn);}
  //    tempq.insert(tempn);}
  if ( input.can_move_bottom() ){
    tempn = input;
    tempn.move_bottom();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_front(tempn);}
  //    tempq.insert(tempn);}
  if ( input.can_move_left() ){
    tempn = input;
    tempn.move_left();
    tempn.inc_g();
    tempn.create_state(goal);
    templist.push_front(tempn);}
  //    tempq.insert(tempn);}
  // tempq.print();
  list<node>::iterator it;
  cout << "templist contains:";
  for ( it=templist.begin() ; it != templist.end() ; it++ )
    cout << " " << *it;
  cout << endl;
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
//void Astar::add_expanded(Queue<node> temp, node father){
void Astar::add_expanded(list<node> temp, node father){
  node added;
  list<node>::iterator it;
  //  while ( !temp.isEmpty() ){
  while ( !temp.empty() ){
    //    added = temp.del();
    added = temp.front();
    temp.pop_front();
    if ( !is_member_openlist(added) && !is_member_closedlist(added) ){
      added.set_link(&father);
      test1.push_front(added);
    } else {
      if ( is_member_openlist(added) ){
	for ( it=test1.begin() ; it != test1.end() ; it++ ){
	  if ( *it == added && added.f < it->f ){
	    it->f = added.f;
	    it->h = added.h;
	    it->h = added.g;
	    it->set_link(&father);
	  }//end of first inner if
	}//end of iterator
      }//end of outer if
      if ( is_member_closedlist(added) ){
	for ( it=test2.begin() ; it != test2.end() ; it++ ){
	  if ( *it == added && added.f < it->f ){
	    test2.remove(*it);
	    added.set_link(&father);
	    test1.push_front(added);
	  }//end of first inner if
	}//end of iterator
      }//
    }//end of second inner if
  }//end of else
  //    if ( !openlist.isMember(added) && !closedlist.isMember(added) ){
  //      added.set_link(&father);
  //      openlist.insert(added);
  //}
}
bool Astar::is_member_openlist(node in){
  list<node>::iterator it;
  bool sentinel = false;
  for ( it=test1.begin() ; it != test1.end() ; it++ ){
    if ( in == *it )
      sentinel=true;
  }
  return sentinel;
}
bool Astar::is_member_closedlist(node in){
  list<node>::iterator it;
  bool sentinel = false;
  for ( it=test2.begin() ; it != test2.end() ; it++ ){
    if ( in == *it )
      sentinel=true;
  }
  return sentinel;
}

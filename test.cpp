/*Cesar Vargas
 *AI Fall 2010
 *test.cpp
 */
#include "Astar.h"
#include "Square.h"
// #include "Queue.h"
#include "Node.h"
// #include "SearchAlg.h"
// #include <iostream>
// #include <string>
#include <sstream>
Square start;
Square goal;
int counter=0;
int array[4];
// using namespace std;
void parse(Square &in, string a);
void prompt(Square &st, Square &go);
int main(){
  prompt(start,goal);
  Astar test1(start,goal);
  test1.begin();

  return 0;
}
void parse(Square &in, string a){
  counter++;
  int sentinel=1;
  int temp;
  for(istringstream i(a); i>>temp; ){
    array[sentinel] = temp;
    sentinel++;
  }
  in.set_row(array,counter);
}
void prompt(Square &st, Square &go){
  string input;
  string choice;
  cout << "Do you want to play a game: (Y or N)";
  getline(cin,choice);
  while( choice == "Y" ){
    cout << "Enter a 3x3 square with underscore as separator, this is your star node:" <<endl;
    getline(cin,input);
    parse(st,input);
    getline(cin,input);
    parse(st,input);
    getline(cin,input);
    parse(st,input);
    cout << "here is your beginning puzzle" << endl;
    start.print();
    counter=0;
    cout << "Enter a 3x3 square with underscore as separator, this is your end node:" <<endl;
    getline(cin,input);
    parse(go,input);
    getline(cin,input);
    parse(go,input);
    getline(cin,input);
    parse(go,input);
    cout << "here is your goal puzzle" << endl;
    go.print();
    counter=0;
    cout << "Do you want to play again:(Y or N)";
    getline(cin,choice);
  }
}
void expand(){
  start.find_zero();
  
}

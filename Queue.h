/*Cesar Vargas
 *AI Fall 2010
 *Queue.h
 */
#ifndef QUEUE_H_
#define QUEUE_H_
#define MAX 50
#include <iostream>
using namespace std;
template <class T>
class Queue{
 private:
  T queue_arr[MAX];
  int rear,front,counter;
 public:
  Queue();
  void insert(T added_item);
  T del();
  void print();
  bool isEmpty();
  bool isMember(T item);
};
#endif

template <class T>
Queue<T>::Queue():rear(-1),front(-1),counter(0){}
template <class T>
void Queue<T>::insert(T added_item){
  // int added_item;
  if( rear==MAX-1){
    cout << "Queue overflow"<<endl;
    return;
  }
  if ( front == -1 )
    front = 0;
  // cout << "Enter item:";
  // cin >> added_item;
  rear=rear+1;
  queue_arr[rear]=added_item; 
  counter++;
}
template <class T>
T Queue<T>::del(){
  // if ( front == -1 || front > rear ){
  //   cout << "Queue underflow " << endl;
  //   return ;
  // } else {
    /* cout << "Element deleted from queue is " << queue_arr[front] << endl; */
    front=front+1;
    counter--;
    return queue_arr[front-1];
  // } 
}
template <class T>
void Queue<T>::print(){
  int i;
  if ( front == -1 || front > rear ){
    cout << "Queue is empty" << endl;
    return;
  } else {
    cout << "Queue is: ";
    for ( i=front ; i <= rear ; i++)
      cout << queue_arr[i] << " ";
    cout << endl;
  } 
}
template <class T>
bool Queue<T>::isEmpty(){
  if ( counter == 0 )
    return true;
  return false;
}
template <class T>
bool Queue<T>::isMember(T item){
  int i;
  bool sentinel=false;
  for(i=front; i <= rear ; i++ ){
    if ( item == queue_arr[i] ){
      sentinel = true;
    }//if statement
  }//for loop
  return sentinel;
}
/* template <class T> */
/* ostream& operator<<(ostream &os, Square s){ */
/*   int i,j; */
/*   for ( i=1; i < 4; i++ ){ */
/*     for( j=1; j < 4 ; j++ ){ */
/*       os << s.board[i][j]; */
/*     } */
/*   } */
/*   return os; */
/* } */

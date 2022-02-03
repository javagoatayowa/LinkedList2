#include <iostream>
#include <iomanip>
#include <cstring>
#include "node.h"
#include "student.h"
using namespace std;
void add(Student* s, Node* & head, Node* previous, Node* current, int idtres);
void printList(Node* firstNode);
void remove(Node* &firstNode, Node* p, Node* c, int theID);//methods
int main() {//main
  Node* head = NULL;//original head
  cout<<"hey, welcome to student list. to add a student, type ADD. to print, type PRINT, average to get an average of the gpas, and to delete, type DELETE!";
  cout<<endl;//start prompt
  int a = 0;
  while (a == 0) {//forever!
    cout<<"Ur action:";
    char input[10];
    cin>>input;
    char first[80];
    char last[80];
    int id;
    float gpa;//the values
    if (strcmp(input,"QUIT") == 0) {//quit
      a =1;
    }
    else {
      if(strcmp(input,"ADD") == 0) {
        Student* temp = new Student();
	cout<<"Enter first name";
	cin>> temp->first;
	cout<<"enter last name";
	cin>> temp->last;
        cout<<"Give id";
	cin>> temp->id;
	cout<<"enter the gpa. It better not be negative!!!!";
	cin>>temp->gpa;
	int id2 = temp->id;
	add(temp,head,head,head,id2);
      }
      if(strcmp(input,"PRINT") == 0) {
	printList(head);
      }
       if(strcmp(input,"DELETE") == 0) {//delete
        cout<<"What is id of the student you want to delete?";
        cout<<endl;
        int theIDID;
        cin>>theIDID;
        remove(head,head,head,theIDID);
      }
    }
  }
  return 0;
} //the functions
void add(Student* s, Node* &head, Node* previous, Node* current, int idtres) {
  if(head == NULL) {
    head = new Node(s);
    head->setNext(NULL);
  }
  else if(current == NULL) {
    previous->setNext(new Node(s));
    previous ->getNext()->setNext(NULL);
  }
  else if(idtres < head->getStudent()->id) {
    Node* temp = head;
    head = new Node(s);
    head->setNext(temp);
  }
  else if(idtres < current->getStudent()->id) {
    previous->setNext(new Node(s));
    previous->getNext()->setNext(current);
  }
  else {
    add(s,head,current,current->getNext(), idtres);
  }
}
void printList(Node* firstNode) {
  firstNode->getStudent()->printStudent();
  if(firstNode->getNext() != NULL) {
    printList(firstNode->getNext());//using recursion to go through and print.
  }
}
void remove(Node* &firstNode, Node *p, Node* c, int theID) {
  if(firstNode == NULL) {
    cout<<"Empty LinkedList.";//check if empty
  }
  else if(theID == c->getStudent()->id) {//check if the id is found
    if (c == firstNode) {
      firstNode = firstNode->getNext();
      c->setNext(NULL);
      c->~Node();
      return;
    }
    else {
      p->setNext(c->getNext());
      c->setNext(NULL);
      c->~Node();
      return;
    }
  }
  else {//continuing with recursion
    remove(firstNode, c, c->getNext(),theID);
  }
}

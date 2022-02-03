#include <iostream> //Aneeq Chowdhury 2021 code to make a linkedlist version of student list. Nihal Parthasarathy has helped me with rounding numbers, a bit on the add function, and he helped me with the delete\
 function.
//Also used stack overflow website to figure out how to sum up through a linked list.
//https://stackoverflow.com/questions/43083819/summing-up-the-elements-in-a-linked-list-recursively-in-c
//The post was the first post.
#include <iomanip>
#include <cstring>
#include "node.h"
#include "student.h"
using namespace std;
void add(Student* s, Node* & head, Node* previous, Node* current, int idtres);
void printList(Node* firstNode);
void remove(Node* &firstNode, Node* p, Node* c, int theID);
float average(Node* firstNode, int &it);
//methods
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
      if(strcmp(input,"ADD") == 0) {//add input
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
      if(strcmp(input,"PRINT") == 0) {//print input
	printList(head);
      }
       if(strcmp(input,"DELETE") == 0) {//delete
        cout<<"What is id of the student you want to delete?";
        cout<<endl;
        int theIDID;
        cin>>theIDID;
        remove(head,head,head,theIDID);
      }
       if(strcmp(input,"AVERAGE") == 0) {//average
        int count = 0;
        cout<< fixed << showpoint<< setprecision(2) <<average(head,count)/count << endl;
       }
    }
  }
  return 0;
} //the functions
void add(Student* s, Node* &head, Node* previous, Node* current, int idtres) {//add function
  if(head == NULL) {//if head is null
    head = new Node(s);
    head->setNext(NULL);
  }
  else if(current == NULL) {
    previous->setNext(new Node(s));
    previous ->getNext()->setNext(NULL);
  }//sorting purposes
  else if(idtres < head->getStudent()->id) {
    Node* temp = head;
    head = new Node(s);
    head->setNext(temp);
  }
  else if(idtres < current->getStudent()->id) {
    previous->setNext(new Node(s));
    previous->getNext()->setNext(current);
  }
  else {//recursive method of moving through list
    add(s,head,current,current->getNext(), idtres);
  }
}
void printList(Node* firstNode) {//print method
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
float average(Node* firstNode, int &it) {
  if(firstNode!= NULL) {
    it++;//summing through with recursion
    return firstNode->getStudent()->gpa + average(firstNode->getNext(),it);
  }
  else {
    return 0;
  }
}

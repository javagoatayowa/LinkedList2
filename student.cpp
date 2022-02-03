#include "Student.h"
#include <iostream>
#include <iomanip>//student.cpp
using namespace std;

void Student::printStudent() {//print student method
  cout<<"The full name is:";
  cout<<endl;
  cout<<first;
  cout<<endl;
  cout<<last;
  cout<<endl;
  cout<<"The GPA is:";
  cout<< fixed << showpoint << setprecision(2) << gpa;
  cout<< endl;
  cout<< "The ID is:";
  cout<< id;
  cout<<endl;
}

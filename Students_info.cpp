#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
using namespace std ;

struct Student {
    int age  ;
    string name ;
    double GPA ;
};


void insert_student_info (Student *pStudents , int size) ;
void print_student_info (Student *pStudents , int size) ;

int main () {
    int size ;
    cout << "enter number of students : " ;
    cin >> size ;
    Student *pStudents = new Student [size] ;
    insert_student_info (pStudents , size);

    print_student_info (pStudents , size) ;


    return 0 ;
}


void insert_student_info (Student *pStudents , int size) {
    for (int i = 0 ; i < size ; i++) {
        Student student ;
        pStudents [i] = student ;
        cout << "student " << i+1 << " name : " ;
        getline (cin >> ws , pStudents[i].name) ;
        cout << "student " << i+1 << " age : " ;
        cin >> pStudents[i].age ;
        cout << "student " << i+1 << " GPA : " ;
        cin >> pStudents[i].GPA ;

    }
}

void print_student_info (Student *pStudents , int size) {
    cout << "\n" ;
    cout << "**********************************************\n";
    for (int i = 0 ; i <size ; i++) {
        cout << "name of student " << i+1 << " is : " << pStudents[i].name << '\n' ;
        cout << "age of student " << i+1 << " is : " << pStudents[i].age << '\n' ;
        cout << "GPA of student " << i+1 << " is : " << pStudents[i].GPA << '\n' ;
    }
    cout << "**********************************************\n";
}
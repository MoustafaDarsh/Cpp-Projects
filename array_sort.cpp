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
void choosing_sort_type (int &sort) ;
void sorting_array (int array [] , int size , int sort) ;

int main () {
    int sort ;
    int array [] = {2 , 5 , 1 , 0 , 12 , -5 , 8 , 5} ;
    int size = sizeof(array)/sizeof(array[0]) ;
    choosing_sort_type (sort) ;
    sorting_array (array , size , sort) ;

    // displaying array :
    for (int element : array) {
        cout << element << " " ;
    }
    cout << '\n' ;

    return 0;
}


void choosing_sort_type (int &sort)  {
    cout << "choose which type of sort you want!\n" ;
    cout << "1. Ascending\n";
    cout << "2. Descending\n";
    cout << "your choice : " ;
    cin >> sort ;
    while (sort != 1 && sort != 2) {
        cout << "please enter a valid answer!\n" ;
        cin.clear () ;
        while (cin.get () != '\n') ;
        cout << "your choice : " ; 
        cin >> sort ;
    }
}

void sorting_array (int array [] , int size , int sort) {
    for (int i = 0 ; i < size-1 ; i++) {
        for (int j = i+1 ; j < size ; j++) {
            if (sort == 1) {
                if (array [i] > array [j]) {
                    int temp = array [i] ;
                    array [i] = array [j] ;
                    array [j] = temp ;
                }
            }
            else if (sort == 2) {
                if (array [i] < array [j]) {
                    int temp = array [i] ;
                    array [i] = array [j] ;
                    array [j] = temp ;
                }
            }
        }    
    }

} 

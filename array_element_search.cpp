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
void asking_user_for_element (int &element) ;
void elementSearch (int array [] , int element , int &index , int size) ;
void show_result (int index,int element) ;
void check_retry (char &retry) ;
int main () {

    int element ;
    int index ;
    int array [] = {2 , 4 , 5 , 6 , 7 , 9 , 10 , 4 , 3 , 11};
    int size = sizeof(array)/sizeof(array[0]) ;
    char retry ;
    while (1) {
    cout << "Welcome to our searching program!\n" ;
    asking_user_for_element (element) ;
    elementSearch (array , element , index , size) ;
    show_result (index , element) ;
    check_retry (retry) ;
    if (retry == 'N') {
        break ;
    }
    }
    cout << "Thank you for using our program!\n" ;
    return 0 ;
}

void asking_user_for_element (int &element) {
    cout << "Enter element that you want to search for in array : " ;
    while (!(cin >> element)) {
        cout << "Please enter a valid number!\n"; 
        cin.clear () ;
        while (cin.get() != '\n') ;
        cout << "Enter element that you want to search for in array : " ;
    }
}

void elementSearch (int array [] , int element , int &index , int size) {
    index = -1 ;
    for (int i = 0 ; i < size ; i++) {
        if (array [i] == element ) {
            index = i ;
            break ;
        }
    }
}

void show_result (int index , int element) {
    if (index == -1) {
        cout << "Couldn't find element ("<< element << ") that you have searched for!\n" ;
    }
    else {
        cout << "The index of element (" << element << ") that you have searched for is : " << index << '\n' ;
    }
}

void check_retry (char &retry) {
    cout << "Would you like to try again? (Y/N) : " ;
    cin >> retry ;
    while (toupper(retry)!='Y' && toupper(retry) != 'N') {
        cout << "Please enter a valid answer!\n" ;
        cin.clear () ;
        while (cin.get() != '\n') ;
        cout << "Would you like to try again? (Y/N) : " ;
        cin >> retry ;
    }
    retry = toupper (retry) ;
}
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
/*
This program performs conversion between celsius and fahrenheit temperature units
*/



void insert_temp_value (double &temp) ;
void choose_temp_type (char &type) ;
void convert_to_F (double &temp_F , double temp_C) ;
void convert_to_C (double temp_F , double &temp_C) ;
void show_temp (double temp_F , double temp_C) ;
void check_for_retry (char &retry) ;


int main () {
    double temp ;
    char type ;
    double temp_F ;
    double temp_C ;
    char retry ;
    while (1) {
        cout << "Welcome to our program!\n" ;
        insert_temp_value (temp) ;
        choose_temp_type (type) ;
        if (type == 'F') {
            temp_F = temp ;
            convert_to_C (temp_F,temp_C) ;
        }
        else {
            temp_C = temp ;
            convert_to_F (temp_F,temp_C) ;
        }
        show_temp (temp_F,temp_C) ;
        check_for_retry (retry) ;
        if (retry == 'N') {
            break ;
        }
    }
    cout << "Thank you for using our program!\n" ;
    cout << "GoodBye!\n" ;
    return 0 ;
}


void insert_temp_value (double &temp)  {
    cout << "Please enter temperature value : " ;
    while (!(cin >> temp)) {
        cout << "Please enter a valid value!\n" ;
        cin.clear () ;
        while (cin.get() != '\n') ;
        cout << "Please enter temperature value : " ;
    }
}


void choose_temp_type (char &type) {
    cout << "Choose Temperature type : " ;
    cin >> type ;
    while (toupper(type) != 'C' && toupper(type) != 'F') {
        cout << "Please enter a valid type!\n" ;
        cin.clear ();
        while (cin.get () != '\n' );
        cout << "Choose Temperature type : " ;
        cin >> type ;
    }
    type = toupper (type) ;
}

void convert_to_F (double &temp_F , double temp_C) {
    temp_F = (temp_C * 9/5)+32 ;
}

void convert_to_C (double temp_F , double &temp_C) {
    temp_C = (temp_F-32) * 5/9 ;
}

void show_temp (double temp_F , double temp_C) {
    cout << "Temperature :\n" ;
    cout << temp_C << " Celsius\n" ;
    cout << temp_F << " Fahrenheit\n" ;
}

void check_for_retry (char &retry) {
    cout << "Would you like to try again? (Y/N) : " ;
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper (retry) != 'N') {
        cout << "Please enter a valid answer!\n" ;
        cin.clear ();
        while (cin.get () != '\n') ;
        cout << "Would you like to try again? (Y/N) : " ;
        cin >> retry ;
    }
    retry = toupper(retry) ;
}
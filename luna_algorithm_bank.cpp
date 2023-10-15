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

void entering_credit_card (string &credit_number) ;
void double_and_add_second_digit (string credit_number , int &s1) ;
void add_odd_digits (string credit_number , int &s2) ;
void calculate_sum (int s1 , int s2 , int &sum) ;
void luna_check (int sum) ;
void check_retry (char &retry) ;


int main () {
    string credit_number ;
    char retry ;
    int s1 , s2 , sum ;
    while (1) {    
    cout << "Welcome to our program!\n" ;
    entering_credit_card (credit_number) ;
    double_and_add_second_digit (credit_number,s1) ;    
    add_odd_digits (credit_number ,s2) ;
    calculate_sum (s1 , s2 , sum) ;
    luna_check (sum) ;
    check_retry (retry) ;
    if (retry == 'N') {
        break;
    }
    }
    cout << "Thank you for using our program!\n" ;
    return 0 ;
}

void entering_credit_card (string &credit_number) {
    cout << "enter credit number : " ;
    getline (cin>>ws , credit_number) ;
}

void double_and_add_second_digit (string credit_number , int &s1 ) {
    s1 = 0 ;
    for (int i = (credit_number.size () -2)  ; i >= 0  ; i-=2) {
        int temp ;
        temp = credit_number [i] - '0' ;
        temp *= 2 ;
        if (temp <10) {
            s1 += temp ;
        }
        else {
            s1 += (temp-9) ;
        }
    }
}


void add_odd_digits (string credit_number , int &s2) {
    s2 = 0 ;
    for (int i = (credit_number.size () -1)  ; i >= 0  ; i-=2) {
        s2 += credit_number[i] - '0';
    }

}


void calculate_sum (int s1 , int s2 , int &sum) {
    sum = s1 + s2 ;
}

void luna_check (int sum) {
    if (!(sum % 10)) { // divisible by 10
        cout << "The credit card that you have entered is valid!\n" ;
    }
    else {
        cout << "Invalid credit card!\n" ;
    }
}



void check_retry (char &retry) {
    cout << "would you like to try again (Y/N) ? : " ;
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper(retry) != 'N') {
        cout << "enter a valid answer!\n" ;
        cin.clear () ;
        while (cin.get () != '\n') ;
        cout << "would you like to try again (Y/N) ? : " ;
        cin >> retry ;
    }
    retry = toupper (retry) ;
}
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
Bank program to choose operation
*/


void chooseOperation (int &choice) ;
void showBalance (int balance) ;
void Deposit (int &balance) ;
void withDraw (int &balance) ;
void check_retry (char &retry) ;

int main () {
    int choice ;
    int balance = 0 ;
    char retry ;
    while (1) {
        cout << "Welcome to our program!\n" ;
        chooseOperation (choice) ;
        switch (choice) {
            case 1 :
                showBalance (balance) ;
                break ;
            case 2 :
                Deposit (balance) ;
                break ;
            case 3 :
                withDraw (balance) ;
                break ;    
            case 4 :
                break ;    
        }
        if (choice == 4) {
            break ;
        }
        check_retry (retry) ;
        if (retry == 'N') {
            break ;
        }
    }
    cout << "Thank you for using our program!\n" ;
    return 0 ;
}


void chooseOperation (int &choice) {
    cout << "Choose an operation that you want!\n" ;
    cout << "1.Show Balance\n" ;
    cout << "2.Deposit\n" ;
    cout << "3.With Draw\n" ;
    cout << "4.Close\n" ;
    cout << "Your Choice : " ;
    cin >> choice ;
    while (choice != 1 && choice!= 2 && choice != 3 && choice != 4) {
        cout << "Please enter a valid choice!\n" ;
        cin.clear () ;
        while (cin.get () != '\n') ;
        cout << "Your Choice : " ;
        cin >> choice ;
    }
}

void showBalance (int balance) {
    cout << "Your current balance = " << balance << " $\n" ;
}
void Deposit (int &balance) {
    int deposit_value ;
    cout << "Enter value you want to deposit : " ;
    while (!(cin>>deposit_value)) {
        cout << "Please enter a valid value!\n" ;
        cin.clear() ;
        while (cin.get()!='\n') ;
        cout << "Enter value you want to deposit : " ;
    }
    balance += deposit_value ;
    cout << "your balance after performing deposit operation = " << balance << " $\n" ;
}
void withDraw (int &balance) {
    int withDraw_value ;
    cout << "Enter value you want to withdraw!" ;
    while (!(cin>>withDraw_value)) {
        cout << "Please enter a valid value!\n" ;
        cin.clear() ;
        while (cin.get()!='\n') ;
        cout << "Enter value you want to withdraw! : " ;
    }
    if (withDraw_value > balance) {
        cout << "Can't do this operation because no enough balance!\n" ;
    }
    else {
        balance -= withDraw_value ;
        cout << "your balance after performing with draw operation = " << balance << " $\n" ;
    }
}



void check_retry (char &retry) {
    cout << "Would you like to perform another operation ? (Y/N) : " ;
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper(retry) != 'N') {
        cout << "Please enter a valid answer!\n" ;
        cin.clear ();
        while (cin.get () != '\n');
        cout << "Would you like to perform another operation ? (Y/N) : " ;
        cin >> retry ;
    }
    retry = toupper(retry) ;
}
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

void make_computer_choice (int &computer_choice) ;
void make_user_choice (int &user_choice) ;
void show_result (int computer_choice , int user_choice) ;
void choose_winner (int computer_choice , int user_choice) ;
void check_retry (char &retry) ;




int main () {
    int computer_choice ;
    int user_choice ;
    char retry ;
    while (1) {
        cout << "Welcome to our game!\n" ;
        make_computer_choice (computer_choice) ;
        make_user_choice (user_choice) ;
        show_result (computer_choice , user_choice) ;
        choose_winner (computer_choice , user_choice) ;
        check_retry (retry) ;
        if (retry == 'N') {
            break ;
        }
    }
    cout << "Thank you for playing our game!\n" ;
    cout << "GoodBye!\n" ;

    return 0 ;
}


void make_computer_choice (int &computer_choice) {
    srand(time(0)) ;
    computer_choice = ( rand () % 3 ) + 1 ;
}

void make_user_choice (int &user_choice) {
    cout << "Please make your choice!\n" ;
    cout << "***************************************\n" ;
    cout << "1.Rock\n";
    cout << "2.Paper\n";
    cout << "3.Scissors\n";
    cout << "***************************************\n" ;
    cout << "Your choice : " ;
    cin >> user_choice ;
    while (user_choice != 1 && user_choice != 2 && user_choice != 3) {
        cout << "Please enter a valid choice!\n" ;
        cin.clear () ;
        while (cin.get() != '\n') ;
        cout << "Your choice : " ;
        cin >> user_choice ;
    }
}

void show_result (int computer_choice , int user_choice) {
    string computer_choice_st ;
    string user_choice_st ;
    switch (computer_choice) {
        case 1 : 
            computer_choice_st = "Rock" ;
            break;
        case 2 :
            computer_choice_st = "Paper" ;
            break;
        case 3 :
            computer_choice_st = "Scissors" ;
            break;
        default :
            cout << "Invalid!\n" ;
    }

    switch (user_choice) {
        case 1 : 
            user_choice_st = "Rock" ;
            break;
        case 2 :
            user_choice_st = "Paper" ;
            break;
        case 3 :
            user_choice_st = "Scissors" ;
            break;
        default :
            cout << "Invalid!\n" ;
    }
    cout << "***************************************\n" ;
    cout << "User Choice : " << user_choice_st << '\n' ;
    cout << "Computer Choice : " << computer_choice_st << '\n' ;
    cout << "***************************************\n" ;
}


void choose_winner (int computer_choice , int user_choice) {
    if (computer_choice == user_choice) {
        cout << "Result is draw!\n" ;
    }
    else if ((user_choice == 1 && computer_choice == 3) || (user_choice == 2 && computer_choice == 1) || (user_choice == 3 && computer_choice == 2 )) {
        cout << "User wins!\n" ;
    }
    else {
        cout << "Computer wins!\n" ;
    }
}


void check_retry (char &retry) {
    cout << "Would you like to play again (Y/N) : " ;
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper(retry) != 'N') {
        cout << "Please enter a valid answer!\n" ;
        cin.clear () ;
        while (cin.get () != '\n') ;
        cout << "Would you like to play again (Y/N) : " ;
        cin >> retry ;
    }
    retry = toupper(retry) ;
}
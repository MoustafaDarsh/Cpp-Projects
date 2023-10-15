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
Guessing game to guess a number between 2 boundaries

*/


void choosing_number_boundaries (int &min_val , int &max_val) ;
void guessing_number (int number , int guess , int trials) ;
void check_retry (char &retry) ;
int main () {
    int min_val ;
    int max_val ;
    int number ;
    int guess ;
    char retry ;
    while (1) {
        srand (time(0)) ;
        cout << "Welcome to our program!\n" ;
        int trials = 0 ;
        choosing_number_boundaries (min_val , max_val);
        number = (rand () % (max_val-min_val+1)) + min_val ; // generating random number which we will guessc
        cout << "Beny w benk number = " << number << '\n' ;
        guessing_number (number , guess , trials);
        check_retry (retry) ;
        if (retry == 'N') {
            break ;
        }
    }
    cout << "Thank you for using our program\n" ;
    cout << "GoodBye!\n" ;
    return 0 ;
}

void choosing_number_boundaries (int &min_val , int &max_val) {
    cout << "choose minimum number of region : " ;
    while (!(cin >> min_val)) {
        cout << "Please enter a valid number!\n" ;
        cin.clear() ;
        while (cin.get() != '\n') ;
        cout << "choose minimum number of region : " ;
    }

    cout << "choose maximum number of region : " ;
    while (!(cin >> max_val) || max_val < min_val) {
        cout << "Please enter a valid number!\n" ;
        cin.clear() ;
        while (cin.get() != '\n') ;
        cout << "choose maximum number of region : " ;
    }

}

void guessing_number (int number , int guess , int trials) {
    while (1) {
        if (!trials) {
            cout << "enter a guess : " ;
        }
        else {
            cout << "enter another guess : " ;
        }
        while (!(cin >> guess)) {
            cout << "Please enter a valid number!\n" ;
            cin.clear() ;
            while (cin.get() != '\n') ;
            cout << "enter another guess : "  ;
        }
        trials ++ ;
        if (guess == number) {
            break ;
        }
    }
    cout << "You have guessed the right number after " << trials << " trials!\n" ;

}

void check_retry (char &retry) {
    cout << "Would you like to try again ? (Y/N) : " ;
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper(retry) != 'N') {
        cout << "Please enter a valid answer!\n" ;
        cin.clear ();
        while (cin.get () != '\n');
        cin >> retry ;
    }
    retry = toupper(retry) ;
}

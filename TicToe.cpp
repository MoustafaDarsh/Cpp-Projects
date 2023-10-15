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

void display_matrix (char matrix [] [3] , int rows , int columns) ;
void player_1_input (char matrix [] [3] , int row , int column) ;
void player_2_input (char matrix [] [3] , int row , int column) ;
bool check_player_1_wins (char matrix [] [3] , int rows , int columns) ;
bool check_player_2_wins (char matrix [] [3], int rows , int columns) ;
bool check_draw (char matrix [] [3] , int rows , int columns) ;
void check_retry (char &retry) ;

int main () {
    int column , row ;
    char retry ;
    bool player_1_wins ;
    bool player_2_wins ;
    bool draw ;
    while (1) {
        cout << "Welcome to our Tic Toe game!\n";
        char matrix [] [3] = {{' ' , ' ' , ' '} , {' ' , ' ' , ' '} , {' ' , ' ' , ' '}  };
        int rows = sizeof(matrix)/sizeof(matrix[0]) ;
        int columns = sizeof(matrix[0])/sizeof(matrix[0][0]) ;
        display_matrix (matrix , rows , columns) ;
        while (1) {
            player_1_input (matrix , row , column) ; 
            display_matrix (matrix , rows , columns) ;
            player_1_wins = check_player_1_wins (matrix , rows , columns) ;
            if (player_1_wins) {
                cout << "Player 1 Wins!\n" ;
                break ;
            }
            draw = check_draw (matrix , rows , columns) ;
            if (draw) {
                cout << "DRAW!\n" ;
                break;
            }
            player_2_input (matrix , row , column) ;
            display_matrix (matrix , rows , columns) ;
            player_2_wins = check_player_2_wins (matrix , rows , columns) ;
            if (player_2_wins) {
                cout << "Player 2 Wins!\n" ;
                break ;
            }
        }
        check_retry (retry) ;
        if (retry == 'N') {
            break ;
        }
    }
    cout << "Thank you for playing our game!\n" ;
    cout << "GoodBye!\n" ;

    return 0 ;
}




void display_matrix (char matrix [] [3] , int rows , int columns) {
    for (int i = 0 ; i < rows ; i ++) {
        for (int j = 0 ; j < columns ; j++) {
            if (j != columns-1) {
                cout << " "<<  matrix [i][j] << " |"  ;
            }
            else {
                cout << " "<<  matrix [i][j] << "  "  ;
            }
        }
        cout << "\n___|___|___\n" ;
    }

}

void player_1_input (char matrix [] [3] , int row , int column) {
    cout << "Player 1 Turn!\n" ;
    while (1) {
        cout << "Row number (1-3) : " ;
        while (!(cin >> row) || (row != 1 && row != 2 && row !=3)) {
            cout << "Please enter a valid number!\n" ;
            cin.clear () ;
            while (cin.get () != '\n');
            cout << "Row number (1-3) : " ;
        }
        cout << "Column number (1-3) : " ;
        while (!(cin >> column) || (column != 1 && column != 2 && column !=3)) {
            cout << "Please enter a valid number!\n" ;
            cin.clear () ;
            while (cin.get () != '\n');
            cout << "column number (1-3) : " ;
        }
        if (matrix [row-1][column-1] != ' ') {
            cout << "The position you have entered is already taken!\n" ;
            cout << "Please enter an empty position!\n" ; 
        }
        else {
            matrix [row-1][column-1] = 'X' ;
            break ;
        }
    }
}

void player_2_input (char matrix [] [3] , int row , int column) {
    cout << "Player 2 Turn!\n" ;
    while (1) {
        cout << "Row number (1-3) : " ;
        while (!(cin >> row) || (row != 1 && row != 2 && row !=3)) {
            cout << "Please enter a valid number!\n" ;
            cin.clear () ;
            while (cin.get () != '\n');
            cout << "Row number (1-3) : " ;
        }
        cout << "Column number (1-3) : " ;
        while (!(cin >> column) || (column != 1 && column != 2 && column !=3)) {
            cout << "Please enter a valid number!\n" ;
            cin.clear () ;
            while (cin.get () != '\n');
            cout << "column number (1-3) : " ;
        }
        if (matrix [row-1][column-1] != ' ') {
            cout << "The position you have entered is already taken!\n" ;
            cout << "Please enter an empty position!\n" ; 
        }
        else {
            matrix [row-1][column-1] = 'O' ;
            break ;
        }
    }
}

bool check_player_1_wins (char matrix [] [3] , int rows , int columns) {
    for (int i =0 ; i < rows ; i++) { // horizontal
        if ((matrix [i][0] == matrix [i][1] ) && ( matrix [i][1] == matrix [i][2] ) && (matrix [i][0] == 'X')) {
            return true ;
        }
    }
    for (int i = 0 ; i < columns ; i++) { // Vertical
        if ((matrix [0][i] == matrix [1][i] ) && ( matrix [1][i] == matrix [2][i] ) && (matrix [0][i] == 'X')) {
            return true ;
        }
    }
    if ((matrix [0][0] == matrix [1][1] ) && (matrix [1][1] == matrix [2][2]) && (matrix [0][0] == 'X')) {
        return true ;
    }
    if ((matrix [0][2] == matrix [1][1] ) && (matrix [1][1] == matrix [2][0]) && (matrix [0][2] == 'X')) {
        return true ;
    }
    return false ;
    }

bool check_player_2_wins (char matrix [] [3] , int rows , int columns) {
    for (int i =0 ; i < rows ; i++) { // horizontal
        if ((matrix [i][0] == matrix [i][1] ) && ( matrix [i][1] == matrix [i][2] ) && (matrix [i][0] == 'O')) {
            return true ;
        }
    }
    for (int i = 0 ; i < columns ; i++) { // Vertical
        if ((matrix [0][i] == matrix [1][i] ) && ( matrix [1][i] == matrix [2][i] ) && (matrix [0][i] == 'O')) {
            return true ;
        }
    }
    if ((matrix [0][0] == matrix [1][1] ) && (matrix [1][1] == matrix [2][2]) && (matrix [0][0] == 'O')) {
        return true ;
    }
    if ((matrix [0][2] == matrix [1][1] ) && (matrix [1][1] == matrix [2][0]) && (matrix [0][2] == 'O')) {
        return true ;
    }
    return false ;
    }


bool check_draw (char matrix [] [3] , int rows , int columns) {
    int draw_counter = 0 ;
    for (int i = 0 ; i < rows ; i ++) {
        for (int j = 0 ; j < columns ; j++) {
            if (matrix [i][j] != ' ' ) {
                draw_counter ++ ;
            }
        }
    }
    if (draw_counter == 9) {
        return true ;
    }
    else {
        return false ;
    }
}

void check_retry (char &retry) {
    cout << "Would you like to try again ? (Y/N) : " ;
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper (retry) != 'N') {
        cout << "Please enter a valid answer!\n" ;
        cin.clear ();
        while (cin.get () != '\n') ;
        cin >> retry ;
    }
    retry = toupper (retry) ;
}

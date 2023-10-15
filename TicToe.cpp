#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std ;

void print_matrix (char matrix [] [3] , int rows , int columns) ;
void player_1_input (char matrix [] [3] ) ;
void player_2_input (char matrix [] [3] ) ;
bool player_1_wins_check (char matrix [] [3] , int rows , int columns) ;
bool player_2_wins_check (char matrix [] [3] , int rows , int columns) ;
bool players_draw_check (char matrix [] [3] , int rows , int columns) ;



int main () {
    char retry ;
    bool is_player_1_wins ;
    bool is_player_2_wins ;
    bool is_draw ;
    int trial_time = 0 ;
    while (1) { //// starting the game
        if (!trial_time) {
            cout << "Welcome to our game!\n" ;
            trial_time += 1;
    }
        else {
            cout << "Welcome again to our game :)\n";
    }
    char matrix [] [3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}} ;
    int rows = sizeof(matrix)/sizeof(matrix[0]);
    int columns = sizeof(matrix[0])/sizeof(matrix[0][0]);
    print_matrix (matrix , rows , columns) ;
        while (1) {
            player_1_input (matrix) ;
            //cout << matrix[0][0];
            print_matrix (matrix,rows,columns) ;
            is_player_1_wins = player_1_wins_check (matrix,rows,columns) ;
            if (is_player_1_wins) {
                cout << "Player 1 has won!\n" ;
                break ;
            }

            is_draw = players_draw_check (matrix,rows,columns) ;
            if (is_draw) {
                cout << "The result is draw!\n" ;
                break ;
            }

            player_2_input (matrix) ;
            print_matrix (matrix,rows,columns) ;

            is_player_2_wins = player_2_wins_check (matrix,rows,columns) ;
            if (is_player_2_wins) {
                cout << "Player 2 has won!\n" ;
                break ;
            }
        }
        cout << "Would you like to try again (Y/N) ? " ;
        cin >> retry ;
        retry = toupper (retry) ;
        while (retry != 'Y' && retry != 'N') {
            cout << "Please enter a valid answer!\n" ;
            cin.clear () ;
            while(cin.get () != '\n') ;
            cin >> retry ;
            retry = toupper (retry) ;
        }
        if (retry == 'N') {
            break ;
        }
    }
    cout << "Thank you for playing our game!\n" ;
    cout << "GOODBYE\n";

    return 0 ;
}



void print_matrix (char matrix [] [3] , int rows , int columns) {
    for (int i = 0 ; i< rows ; i++) {
        for (int j = 0 ; j < columns-1 ; j++){
            cout << " " << matrix [i][j] << " |" ;
        }
        cout << " " << matrix [i][columns-1] ;
        cout << "\n___|___|___" << '\n';
    }

}

void player_1_input (char matrix [] [3] ) {
    int row_number ;
    int column_number ;

    cout << "Player 1 Turn!\n";
    while (1) {
        cout << "enter number of row (1-3) : " ;
        while (!(cin>>row_number) || row_number != 1 && row_number != 2 && row_number != 3) {
            cout << "Please enter a valid number!\n";
            cin.clear () ;
            while(cin.get () != '\n') ;
            cout << "enter number of row (1-3) : " ;
        }
        cout << "enter number of column (1-3) : " ;
        while (!(cin>>column_number) || column_number != 1 && column_number != 2 && column_number != 3) {
            cout << "Please enter a valid number!\n";
            cin.clear () ;
            while(cin.get () != '\n') ;
            cout << "enter number of column (1-3) : " ;
        }
        if (matrix [row_number-1][column_number-1] != ' ') {
            cout << "The position that you have chosen is already taken!\n";
            cout << "Please choose an empty position!\n" ;
        }
        else {
            matrix [row_number-1][column_number-1] = 'X' ; 
            break ;
        }
    }
}

void player_2_input (char matrix [] [3] ) {
    int row_number ;
    int column_number ;

    cout << "Player 2 Turn!\n";
    while (1) {
        cout << "enter number of row (1-3) : " ;
        while (!(cin>>row_number) || row_number != 1 && row_number != 2 && row_number != 3) {
            cout << "Please enter a valid number!\n";
            cin.clear () ;
            while(cin.get () != '\n') ;
            cout << "enter number of row (1-3) : " ;
        }
        cout << "enter number of column (1-3) : " ;
        while (!(cin>>column_number) || column_number != 1 && column_number != 2 && column_number != 3) {
            cout << "Please enter a valid number!\n";
            cin.clear () ;
            while(cin.get () != '\n') ;
            cout << "enter number of column (1-3) : " ;
        }
        if (matrix [row_number-1][column_number-1] != ' ') {
            cout << "The position that you have chosen is already taken!\n";
            cout << "Please choose an empty position!\n" ;
        }
        else {
            matrix [row_number-1][column_number-1] = 'O' ; 
            break ;
        }
    }
}


bool player_1_wins_check (char matrix [] [3] , int rows , int columns) {
    for (int i = 0; i< rows ; i++) { // horizontals
        if (matrix[i][0] == matrix [i][1] && matrix [i][1] == matrix [i][2] && matrix [i][0] == 'X') {
            return true ;
        }
    }
    for (int i = 0 ; i < columns ; i++) { // verticals
        if (matrix [0][i] == matrix [1][i] && matrix [1][i] == matrix [2][i] && matrix [0][i] == 'X') {
            return true ;
        }
    } // diagonals
    if ((matrix[0][0] == matrix [1][1] && matrix [1][1] == matrix [2][2] && matrix [0][0] == 'X') || (matrix[0][2] == matrix [1][1] && matrix [1][1] == matrix [2][0] && matrix [0][2] == 'X') ) {
        return true ;
    }

    return false ;
}
bool player_2_wins_check (char matrix [] [3] , int rows , int columns) {
    for (int i = 0; i< rows ; i++) { // horizontals
        if (matrix[i][0] == matrix [i][1] && matrix [i][1] == matrix [i][2] && matrix [i][0] == 'O') {
            return true ;
        }
    }
    for (int i = 0 ; i < columns ; i++) { // verticals
        if (matrix [0][i] == matrix [1][i] && matrix [1][i] == matrix [2][i] && matrix [0][i] == 'O') {
            return true ;
        }
    } // diagonals
    if ((matrix[0][0] == matrix [1][1] && matrix [1][1] == matrix [2][2] && matrix [0][0] == 'O') || (matrix[0][2] == matrix [1][1] && matrix [1][1] == matrix [2][0] && matrix [0][2] == 'O') ) {
        return true ;
    }

    return false ;


}
bool players_draw_check (char matrix [] [3] , int rows , int columns) {
    int draw_counter = 0;
    for (int i = 0 ; i < rows ; i++){
        for (int j = 0 ; j < columns ; j++) {
            if (matrix [i][j] != ' ') {
                draw_counter += 1 ;
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

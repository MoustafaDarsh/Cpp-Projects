#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std ;

void user_enters_operand_1 (double &operand_1) ;
void user_enters_operand_2 (double &operand_2) ;
void user_chooses_op (char &op) ;
void calculator_operation (double operand_1 , double operand_2 , char op) ;
void user_wants_to_retry (char &retry) ;

int main () {
    char op ;
    double operand_1 ;
    double operand_2 ;
    char retry ;

    while (1) {
        cout << "Welcome to our calculator!\n" ;
        user_enters_operand_1 (operand_1);
        user_enters_operand_2 (operand_2);
        user_chooses_op (op) ;
        calculator_operation (operand_1,operand_2,op) ;
        user_wants_to_retry (retry) ;
        if (toupper(retry) == 'N') {
            break ;
        }
    }

    cout << "Thank you for your cooperation!\n" ;
    cout << "Goodbye!\n" ;

    return 0;
}

void user_enters_operand_1 (double &operand_1)  {
    cout << "Please enter operand 1 : " ;
    while (!(cin >> operand_1)) {
        cout << "please enter a valid number!\n" ;
        cin.clear () ;
        while (cin.get () != '\n' );
        cout << "Please enter operand 1 : " ;
    }

}
void user_enters_operand_2 (double &operand_2) {
    cout << "Please enter operand 2 : " ;
    while (!(cin >> operand_2)) {
        cout << "please enter a valid number!\n" ;
        cin.clear () ;
        while (cin.get () != '\n' );
        cout << "Please enter operand 2 : " ;
    }    

}
void user_chooses_op (char &op) {
    cout << "please choose op (+,-,*,/) : " ;
    cin >> op ;
    while (op != '+' && op != '-' && op != '*' && op != '/') {
        cout << "please enter a valid op!\n" ;
        cin.clear () ;
        while (cin.get () != '\n' );
        cout << "please choose op (+,-,*,/) : " ;
        cin >> op ;
    }
}

void calculator_operation (double operand_1 , double operand_2 , char op) {

    switch (op) {
        case '+' :
            cout << operand_1 << " " << op << " " << operand_2 << " = " << operand_1 + operand_2 << '\n' ;
            break ;
        case '-' :
            cout << operand_1 << " " << op << " " << operand_2 << " = " << operand_1 - operand_2 << '\n' ;
            break ;
        case '*' :
            cout << operand_1 << " " << op << " " << operand_2 << " = " << operand_1 * operand_2 << '\n' ;
            break ;    
        case '/' :
            cout << operand_1 << " " << op << " " << operand_2 << " = " << operand_1 / operand_2 << '\n' ;
            break ;
        default :
            cout << "invalid operation!\n" ;
    }
}

void user_wants_to_retry (char &retry) {
    cout << "would you like to make another operation (Y/N) ? " ;        
    cin >> retry ;
    while (toupper(retry) != 'Y' && toupper(retry) != 'N') {
        cout << "please enter a valid answer!\n";
        cin.clear () ;
        while (cin.get() != '\n') ;
        cout << "would you like to make another operation (Y/N) ? " ;
        cin >> retry ;   
    }
    

}

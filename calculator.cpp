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
    char continue_using_calc ;
    char op ;
    double operand1 ;
    double operand2 ;
    double result ;

int main () {

    while (1) {
        cout << "Welcome to our calculator!\n" ;
        cout << "Please enter operator you want (+ or - or * or /) : " ;
        cin >> op ;
        while (op != '+' && op != '-' && op != '*' && op != '/') { 
            cout << "please enter a valid operator!\n" ;
            cout << "Please enter operator you want (+ or - or * or /) : " ;
            cin.clear () ;
            while (cin.get() != '\n') ;
            cin >> op ;
        }
        cin.clear () ;
        while (cin.get() != '\n') ;
        cout << "Please enter operand 1 value : " ;
        while (!(cin >> operand1)) {
            cout << "please enter a valid number!\n";
            cout << "Please enter operand 1 value : " ;
            cin.clear () ;
            while (cin.get () != '\n') ;
        }
        cout << "Please enter operand 2 value : " ;
        while (!(cin >> operand2)) {
            cout << "please enter a valid number!\n";
            cout << "Please enter operand 2 value : " ;
            cin.clear () ;
            while (cin.get () != '\n') ;
        }
        switch (op) {
            case '+' :
                result = operand1 + operand2 ;
                break ;
            case '-' :
                result = operand1 - operand2 ;
                break ;
            case '*' :
                result = operand1 * operand2 ;
                break ;

            case '/' :
                result = operand1 / operand2 ;
                break ;
            default :
                cout <<"invalid op\n";
        }

        cout << operand1 << " " << op << " " << operand2 << " = " << result << '\n' ;

        cout << "Would you like to continue (Y/N) ? ";
        cin >> continue_using_calc ;
        continue_using_calc = toupper (continue_using_calc) ;
        while (continue_using_calc != 'Y' && continue_using_calc != 'N') {
            cout << "Please enter a valid answer!\n";
            cout << "Would you like to continue (Y/N) ? ";
            cin.clear () ;
            while (cin.get() != '\n') ;
            cin >> continue_using_calc ;
            continue_using_calc = toupper (continue_using_calc) ;
        }
        if (continue_using_calc == 'N') {
            break ;
        }
    } //// end of calculator program
    cout << "Thank you of using our calc program!\n";
    return 0;
}
    
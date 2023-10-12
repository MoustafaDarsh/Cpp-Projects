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


int main () {
    char grade ;
    cout << "please enter your grade : " ;
    cin >> grade ;
    while (grade != 'A' && grade != 'B' && grade != 'C'  && grade != 'F' ) {
        cout << "please enter a valid grade !\n" ;
        cin.clear () ;
        while (cin.get () != '\n') ;
        cout << "please enter your grade : " ;
        cin >> grade ; 
    }

    switch (grade) {
        case 'A' :
            cout << "your grade is Excellent!\n" ;
            break ;
        case 'B' :
            cout << "your grade is VeryGood!\n" ;
            break ;
        case 'C' :
            cout << "your grade is Good!\n" ;
            break ;
        case 'F' :
            cout << "your grade is Failed!\n" ;
            break ;
        default :
            cout << "invalid\n" ;
    }

    if (grade == 'F') {
        cout << "Unfortunately you have been failed!\n" ;
    }
    else {
        cout << "Congratulations you have been successed!\n" ;
    }

    return 0 ;
}




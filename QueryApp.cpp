// Copyright
// Purpose: Project 4
// Date 11/25/2022
// Author: Colton Sullivan
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <iostream>
#include "/home/sulli313/cse278/Project4/Film.h"

int main() {
    int choice;
    Film::showList();

    std::cin >> choice;

    if (choice == -1) {
        std::cout << "Bye!" << std::endl;
    }
    while (choice != -1) {
    while ( choice >  4 || choice < -1 || choice == 0 ) {
        std::cout << "The wrong choice!!!" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "to continue, press enter...";
        Film::showList();
        std::cin >> choice;
    }
    if ( choice == 1 ) {
        Film::showOne();
    }
    if ( choice == 2 ) {
        Film::showTwo();
    }
    if ( choice == 3 ) {
        Film::showThree();
    }
    if ( choice == 4 ) {
        Film::showFour();
    }
        std::cin >> choice;
        if ( choice == -1 ) {
        std::cout << "Bye!" << std::endl;
        }
    }
}

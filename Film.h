// Copyright
// Purpose: Project 4
// Date 11/25/2022
// Author: Colton Sullivan
#ifndef _HOME_SULLI313_PROJECT4_FILM_H_
#define _HOME_SULLI313_PROJECT4_FILM_H_
#include <iostream>
#include <string>

class Film {
 public:
    static void showList();
    static void showOne();
    static void showTwo();
    static void showThree();
    static void showFour();
    // myDB to start connection
    Film() : myDB("cse278F2022", "localhost", "cse278F2022",
            "raspberrySeltzer") {}

 private:
    mysqlpp::Connection myDB;
};

#endif  // _HOME_SULLI313_PROJECT4_FILM_H_


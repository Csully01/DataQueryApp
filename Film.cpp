// Copyright
// Purpose: Project 4
// Date 11/25/2022
// Author: Colton Sullivan
#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <iostream>
#include "/home/sulli313/cse278/Project4/Film.h"

void Film::showList() {
    // Prints the main menu
    std::cout << "\n-----------------------------------" << std::endl;
    std::cout << "         Query Application         " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << " 1 All letter name actors" << std::endl;
    std::cout << " 2 First # PG-13 and Above" << std::endl;
    std::cout << " 3 All active/inactive users by store" << std::endl;
    std::cout << " 4 Actor Movie titles and ids" << std::endl;
    std::cout << "-1 Exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << ">> Enter your choice:" << std::endl;
}
void Film::showOne() {
    mysqlpp::Connection myDB;
    // Create a query
    mysqlpp::Query query = myDB.query();
    std::cout << "Please enter a Letter A-Z!" << std::endl;
    std::string letter;
    std::cin >> letter;

    query << "SELECT first_name, last_name "
          << "FROM actor "
          << "WHERE first_name "
          << "LIKE '" + letter + "%'";

    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    // shows the selection for the user
    std::cout << "Here is your selection!\n" << std::endl;
    std::cout << "--First/Last Names of Actors Whos First ";
    std::cout << "Name Stars With " + letter + "--\n" << std::endl;

    std::cout << std::left << std::setw(12) << "First Name" <<
    std::setw(10) << "Last Name" << std::endl;
    std::cout << "------------------------" << std::endl;
    // prints the info
    for (const auto & row : result) {
        std::cout << std::left << std::setw(12) << row[0].c_str();
        std::cout << std::setw(5) << row[1] << std::endl;
    }

    std::cout << "\n" << "to continue, press enter..." << std::endl;
    showList();
}

void Film::showTwo() {
    mysqlpp::Connection myDB;

    // Selecting the second option's query
    std::cout << "Please type a limit 1-30!" << std::endl;
    std::string limit;
    std::cin >> limit;

    mysqlpp::Query query = myDB.query();
    query << "SELECT title "
          << "FROM film "
          << "WHERE rating = 'PG-13' "
          << "OR rating = 'R' "
          << "OR rating = 'NC-17' "
          << "LIMIT " + limit + " ";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    // shows the selection for the user
    std::cout << "Here is your selection!\n" << std::endl;
    std::cout << "--First "+ limit +" Titles PG-13 to NC-17--\n" << std::endl;

    std::cout << std::left <<std::setw(20)<< "Title" << std::endl;
    std::cout << "------------------------------" <<std::endl;

    for (const auto & row : result) {
        std::cout << std::left << std::setw(20) << row[0].c_str()<< std::endl;
    }

    std::cout << "\n" << "to continue, press enter..." << std::endl;
    showList();
}

void Film::showThree() {
    mysqlpp::Connection myDB;

    // bind variable
    std::cout << "Please type 1 for active and 0 for inactive!" << std::endl;
    std::string active;
    std::cin >> active;
    if ( active != "1" && active != "0" ) {
        std::cout << "Wrong!" << std::endl;
        std::cout << "Please type 1 for active and ";
        std::cout << "0 for inactive!" << std::endl;
        std::cin >> active;
    }

    // Selecting the second option's query
    mysqlpp::Query query = myDB.query();
    query << "SELECT Count(*) "
          << "FROM customer "
          << "WHERE active = '"+ active + "' "
          << "GROUP BY store_id";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    // shows the selection for the user
    std::cout << "Here is your selection!\n" << std::endl;
    // shows a different title if its the active or inactive users
    if ( active == "1" ) {
    std::cout << "--Count of All Active Users Grouped ";
    std::cout << "by Store Id--\n" << std::endl;
    std::cout << std::left << std::setw(20);
    std::cout << "Active User Ids" << std::endl;
    std::cout << "--------------------" << std::endl;
    } else {
    std::cout << "--Count of All Inactive Users Grouped ";
    std::cout << "by Store Id--\n" << std::endl;
    std::cout << std::left << std::setw(20);
    std::cout << "Inactive User Ids" << std::endl;
    std::cout << "--------------------" <<std::endl;
    }

    for (const auto & row : result) {
        std::cout << std::left << std::setw(20) << row[0].c_str()<< std::endl;
    }

    std::cout << "\n" << "to continue, press enter..." << std::endl;
    showList();
}

void Film::showFour() {
    mysqlpp::Connection myDB;

    // bind variable
    std::cout << "Please type an actor id that is 1-200!" << std::endl;
    std::string act_id;
    std::cin >> act_id;


    // Selecting the second option's query
    mysqlpp::Query query = myDB.query();
    query << "SELECT film.title, film.film_id, film_actor.actor_id "
          << "FROM film, film_actor "
          << "WHERE film_actor.actor_id = "+ act_id +" "
          << "GROUP BY title "
          << "LIMIT 20";
    query.parse();
    mysqlpp::StoreQueryResult result = query.store();
    // prints the selection
    std::cout << "Here is your selection!\n" << std::endl;
    std::cout << "--First 20 Titles and IDs of Actor Id 25--\n" << std::endl;

    std::cout << std::left <<std::setw(22)<< "Title" <<
                    std::setw(10) << "Film_id" <<
                    std::setw(0) <<"Actor_id" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for (const auto & row : result) {
        std::cout << std::left << std::setw(22) << row[0].c_str() <<
        std::setw(10) << row[1] << std::setw(0) <<
        row[2].c_str() << std::endl;
    }

    std::cout << "\n" << "to continue, press enter..." << std::endl;
    showList();
}

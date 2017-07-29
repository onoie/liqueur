
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "slib.h"
#include "bmp.h"
#include "sl3.h"
using namespace std;

int main(int argc, char *argv[]) {
    cout << "boost:v" << (BOOST_VERSION / 100000) << "." << (BOOST_VERSION / 100 % 1000) << "." << (BOOST_VERSION % 100) << endl;
    wcout << "date:" << formatDateWstr(boost::posix_time::second_clock::local_time()) << endl;
    cout << echo("test");
    if(EXIT_SUCCESS==createBMP("test.bmp")){
        cout << "bmp success" << endl;
    }
    if(EXIT_SUCCESS==sl3("./db_test.sqlite3")){
        cout << "sl3 success" << endl;
    }else{
        cout << "sl3 failed" << endl;
    }
    return 0;
}



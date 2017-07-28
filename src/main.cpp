
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"
#include "slib.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "boost:v" << (BOOST_VERSION / 100000) << "." << (BOOST_VERSION / 100 % 1000) << "." << (BOOST_VERSION % 100) << endl;
    wcout << "date:" << formatDateWstr(boost::posix_time::second_clock::local_time()) << endl;
    return 0;
}



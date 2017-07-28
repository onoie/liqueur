
#include <iostream>
#include <fstream>
#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;

void hello(){
    std::cout << "Hello, World!" << std::endl;
}
void createSampleText(){
    typedef boost::iostreams::tee_device<ostream,ofstream> TeeDevice;
    ofstream ofs("sample.txt");
    TeeDevice my_tee(std::cout, ofs);
    boost::iostreams::stream<TeeDevice> my_split(my_tee);
    my_split << "Hello, World!\n";
    my_split.flush();
    my_split.close();
}
std::wstring formatDateWstr(boost::posix_time::ptime now) {
    basic_stringstream<wchar_t> wss;
    wss.imbue(
        locale(
            wcout.getloc(),
            new boost::posix_time::wtime_facet(L"%Y/%m/%d %H:%M:%S")
        )
    );
    wss << now;
    return wss.str();
}
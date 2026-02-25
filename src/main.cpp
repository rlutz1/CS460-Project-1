
#include "main.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;

int main(int argc, char *argv[]) {
    if (((string)argv[1]).compare("-d") == 0) {
        cout << "Booting up parking demo..." << std::endl;
        // run_parking_lot(argc, argv);
    } else {
        cout << "Booting up admin app..." << std::endl;
        // run_admin(argc, argv);
    } // end if
} // end main
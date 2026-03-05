
/**
 * LOCATION OF MAIN DRIVER FOR BOTH PMS AND ADMIN APPS
 */

#include "PMS/run_demo.h"
#include "Admin/run_admin.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;

int main(int argc, char *argv[]) {
    if (argc > 1 && ((string)argv[1]).compare("-d") == 0) {
        cout << "Booting up parking demo..." << std::endl;
        run_demo(argc, argv);
    } else {
        cout << "Booting up admin app..." << std::endl;
        run_admin(argc, argv);
    } // end if
} // end main
//
// Created by lutzr on 2/22/2026.
//


#include "run_demo.h"

#include <iostream>

int main(int argc, char *argv[]) {
    // std::cout << *argv[argc - 1];
    if (*argv[argc - 1] == 'p') {
        run_parking_lot(argc, argv);
    } else {
        run_admin(argc, argv);
    } // end if
} // end main

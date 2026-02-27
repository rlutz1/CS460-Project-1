cmake_minimum_required(VERSION 4.1)
project(CS460_Project_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# TODO: Ensure this works across our environments/laptops to find Qt.
if (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.10.2/mingw_64/lib/cmake")
elseif (APPLE)
    set(CMAKE_PREFIX_PATH "~/Qt/6.10.2/macos/lib/cmake")
endif()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

#TODO: add your executables along the way . i.e. add_executable(<projName>  <sourceFiles>)
add_executable(CS460_Project_1
        src/main.cpp
        src/PMS/run_demo.cpp
        src/PMS/run_demo.h
        src/PMS/Initialization.h
        src/PMS/PMC/ParkingManagementController.cpp
        src/PMS/PMC/ParkingManagementController.h
        src/PMS/PMSGUI/DemoManager.cpp
        src/Admin/run_admin.cpp
        src/Admin/run_admin.h
        src/PMS/PMSGUI/ParkingLot/ParkingLotGUI.cpp
        src/PMS/PMSGUI/ParkingLot/ParkingLotGUI.h
        src/PMS/PMSGUI/ParkingLot/ParkingSpotGUI.cpp
        src/PMS/PMSGUI/ParkingLot/ParkingSpotGUI.h
        src/PMS/PMSGUI/ParkingLot/ParkingFloorGUI.cpp
        src/PMS/PMSGUI/ParkingLot/ParkingFloorGUI.h
        src/PMS/PMSGUI/Gate/GateGUI.cpp
        src/PMS/PMSGUI/Gate/GateGUI.h
        src/PMS/PMSGUI/Gate/EntranceGateGUI.cpp
        src/PMS/PMSGUI/Gate/EntranceGateGUI.h
        src/PMS/PMSGUI/Gate/ExitGateGUI.cpp
        src/PMS/PMSGUI/Gate/ExitGateGUI.h
        src/PMS/PMSGUI/Hardware/SpikesGUI.cpp
        src/PMS/PMSGUI/Hardware/SpikesGUI.h
        src/PMS/PMSGUI/Hardware/SensorGUI.cpp
        src/PMS/PMSGUI/Hardware/SensorGUI.h
        src/PMS/PMSGUI/Hardware/LedGUI.cpp
        src/PMS/PMSGUI/Hardware/LedGUI.h
        src/PMS/PMSGUI/Availability/AvailabilityGUI.cpp
        src/PMS/PMSGUI/Availability/AvailabilityGUI.h
        src/PMS/PMSGUI/GUIStructs/GUIStructs.h
        src/PMS/PMC/ParkingLot/ParkingFloor.h
        src/PMS/PMC/ParkingLot/ParkingFloor.cpp
        src/PMS/PMC/ParkingLot/ParkingLot.cpp
        src/PMS/PMC/ParkingLot/ParkingSpotController.cpp
)


target_link_libraries(CS460_Project_1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)


# specifically for windows:
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
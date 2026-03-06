# CS460: Project 1
CS460 Project 1: Parking Garage. This repository is for housing all documentation and inevitable codebase when building a demo.

## Code Files

All code is housed in the top level `src` directory. It is split into 2 primary folders:
+ **Admin** - houses all code intended for an admin application.
+ **PMS** - houses all code used for the backend logic and frontend simulation.

The file `main.cpp` is the main driver of the demo.

### Admin

This code was not utilized during the live demonstration, but contains the initial attempt to create the admin application. `run_admin.cpp` is the main driver of the application, but the code base is not fully completed.

### PMS

The driver of the demo is within `run_demo.cpp`. This generates the main window and sets up all simulated wired connections between the backend and our "physical" lot.

One extra file, `Initialization.h`, is made accessible to all components and contains simple hardcoded details about the lot, how many spots of each type on each floor. This is used only as metadata to initialize the back and front end with the same information.

#### PMC

This directory primarily houses all backend components used by the demonstration. The components included follow the software architecture diagram included in our SAD, and the communications from the front end GUI communicate back and forth with these components as outlined by the SAD.

Specifically, the components from our architecture can be found as follows:

+ **ParkingManagementController.cpp** - the main top-level controller, also known as "PMC".
+ **Availability Directory** - contains the Availability Controller.
+ **Gate Directory** - Contains the Gate, Entrance Gate, and Exit Gate Controllers.
+ **ParkingLot Directory** - Contains Parking Lot, Floor, and Spot Controllers

Additional software items in order to enable development in this folder are as follows:

+ **PMCInterfaces Directory** - contains abstract classes for hardware components to implement/derive from in order to receive communcations from lower level logical controllers; acts as a simulated wire communication.
  + **IAvailabilityInstructionSink.h** - signatures to send instructions from availability controller to availability display driver. 
  + **IGateInstructionsSink.h** - signatures to send instructions from gate controllers to gate component (gate, spikes, sensors) drivers.
  + **IParkingSpotHardwareSink.h** - signatures to send instructions from parking spot controllers to parking spot hardware (LED, sensors) drivers. 

#### PMSAPI

This was intended as use for developing a simple API for the admin application. This remains empty as the admin application was not finished. However, it remains since it was a part of our software architecture.

#### PMSGUI

This holds the frontend GUI simulation pieces. The organization somewhat mimics the PMC directory for simplicity (see folders `Availability`, `Gate`, and `ParkingLot`). This code base was developed in <a href = "https://www.qt.io/">QT</a>, and is intended to take the place of a physical lot with the hardware that would be installed as dictated by our SRS.

At the top level, we have:

+ **DemoManager.cpp** - acts as the main window for the visual parking lot, and provide actions to the buttons to run the demo; creates vehicles on demo run click and adds them to the scene. 
+ **VehicleGUI.cpp** - a basic visual vehicle with an animation; the animation segment finish signals are what truly simulate the "sensor triggers" (see method `VehicleGUI::initSignals()`).

Further, the directories contain:

+ **Availability Directory** - contains the representative Availability Display visual component, doubling as a driver.
+ **Gate Directory** - contains the top level visual gates; the `EntranceGateGUI` and `ExitGateGUI` specifically contain visual components of gate hardware (gate, sensors, spikes) and act as a general gate driver and a communication delivery system for its further associated hardware drivers. 
+ **ParkingLot Directory** - contains top level visual parking lot, floors, and spots; `ParkingSpotGUI` contains visual components of spot hardware (LED, sensors) and acts as a communication delivery system for these hardware drivers.
+ **Hardware Directory** - contains the lowest level hardware driver visual and software representations; the hardware includes sensors, LEDs and spikes.

Additional software items in order to enable development in this folder are as follows:

+ **PMSGUIInterfaces** - contains abstract classes for PMC to implement/derive from in order to receive communcations from hardware components; acts as a simulated wire communication.
  + **IInductionSensorDataSink.h** - definition of sensor to PMC communcations from the gate induction sensors. 
  + **IParkingSpotSensorDataSink.h** - definition of sensor to PMC communications from the parking spot sensors (weight and ultrasonic).
+ **GUIStructs** - structs useful for GUI development only; no logical purpose.

#### Definitions

This directory contains a single header file for useful identifying structs for IDing gates, spots, and sensors. Contains any special enums or IDs that eased the development pain. 

## Demo 

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# maybe put the demo report stuff pasted here?
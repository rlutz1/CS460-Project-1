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

+ **PMSGUIInterfaces Directory** - contains abstract classes for PMC to implement/derive from in order to receive communcations from hardware components; acts as a simulated wire communication.
  + **IInductionSensorDataSink.h** - definition of sensor to PMC communcations from the gate induction sensors. 
  + **IParkingSpotSensorDataSink.h** - definition of sensor to PMC communications from the parking spot sensors (weight and ultrasonic).
+ **GUIStructs Directory** - structs useful for GUI development only; no logical purpose.

#### Definitions

This directory contains a single header file for useful identifying structs for IDing gates, spots, and sensors. Contains any special enums or IDs that eased the development pain. 

## Demo 

NOTE: the slides of our presentation can be found under `documentation/demo-slides` in this repository if desired in both PDF and PPTX format.

The demo runs as follows: (1) the showing of a single car entering, parking, and exiting the structure, and (2) multiple cars cycling through, in and out of the parking lot, interacting with different types of spots (e.g., motorcycle and EV spots).

For visual context, our demo was a singular GUI window representing a parking lot with an availability display beside it. This window displayed hardware graphically, such as gates, spikes, sensors, and LEDs placed on a 2 floored parking structure (separated by a fine line to indicate the first floor on the left, and the second floor on the right). The parking lot contained one entrance gate and one exit gate, with their respective spikes; the parking lot’s floors had a variety of different parking spot types (e.g., EV, Motorcycle, etc). The availability display was represented near the lot graphic to detail the parking availability count during the runs of the demo for each spot type and floor - it also depicted the in-transit vehicle count.

### Demo Decisions & Justifications

#### Demo Inclusions

##### Actual Components

The backend logic for nearly the entirety of the PMS was implemented and showcased in our demo, minus the Administrator process component, the Power Controller, and the physical hardware components. We wanted to showcase how our backend handles signals given to the PMC by the simulated, graphical hardware, to then trickle down into the respective lower-level logical controllers pertaining to the specific hardware drivers that signaled to the PMC. Additionally, we wanted to highlight the proper tracking of our availability displays when the PMC dictates the updates for parking availability by spot-type and floor level. This backend followed our architecture, as we composed the PMC to be the actual mediator to all those signals, and structured our components to match the SAD structure, from the Gate Controllers, Parking Lot/Floor/Spot, and Availability Controllers.

##### Substituted Components

We substituted actual hardware, like gates, spikes, LEDs, sensors, and availability displays, for graphical versions of them. This allowed us to interact with gate and parking drivers by simulating sensors getting triggered via vehicles passing through them. With this, we can easily demonstrate that our PMC could interact with a form of vehicle and a parking lot's respective gates/parking spots and ensure that it could receive signals, to then be able to update their corresponding hardware - following the path through all the components laid out in the lower-level logic controllers and into the simulated hardware. Despite the simulated hardware, in practice, they were still connected to their respective controllers as detailed in our architecture and communicated via their drivers to the PMC as depicted in our software architecture design.

We used Qt signals (see **Technologies Used**) in order to attach our simulated sensors to their corresponding device drivers so that vehicles triggering them  - i.e. their animations being near the sensors -  could let our backend recognize their presence; the Qt signals let the sensors’ device drivers know about the presence of a vehicle to then have those device drivers formulate a signal to the PMC [2].

#### Demo Inclusions

1. Decided to omit showcasing our Power Controller in our demo. We decided not to showcase the capabilities of our PMS in handling power outages; hence, we decided to omit the idea of handling switching between our main power grid and emergency battery packs. Thus, constructing our demo with the assumption that the power for all technology remains on.
2. Decided not to showcase our Administrator process component (and consequently our PMS API for it), in order to highlight the primary signal, circulation logic between the PMC and the hardware.

### Illustrated Use Cases

1. Vehicle Entry/Exit and Parking Structure Capacity Management \
   + To handle the core operational flow of vehicles entering and exiting the parking structure while maintaining accurate capacity counts at both the structure and floor levels.
2. Parking Spot Occupation and State Update
   + Accurately reflect the occupancy status of a parking spot and update the floor and structure availability.

### Technologies Used 

+ **C++** - Sole programming language used. 
+ **Qt (ver. 6.10.2)**  - framework to assemble and interact with our GUI [2]. 
+ **Clion** - IDE for C++ and running/showcasing our GUI demo [1]. 
+ **Git/GitHub** - code versioning and code history with a repository.

### References

[1] JetBrains, “CLion,” JetBrains. https://www.jetbrains.com/clion/ \
[2] Qt, “Get and Install Qt,” Qt Group | Documentation.   https://doc.qt.io/qt-6/get-and-install-qt.html 

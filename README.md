#Implementation of a Dual-Axis Tracking
System for Parabolic Dish Collectors
## System Description

Solar energy is abundant in our environment, and making use of it is a must as it is clean and renewable, and solar generation has seen growth over the last decades. Thus, this experimental study examines the implementation challenges faced in the development process of a dual-axis solar tracker for a parabolic dish collector (PDC) in the Egyptian market. Firstly,this system uses chronological solar tracking technology which is time basedand automatic, and the movement degrees of this system is 2D since based on various previous research, is more energy efficient. Secondly, This system uses a simple economical electro-mechanical system that consists of motors, drivers, and a microcontroller to execute the program performing the solar tracking. Finally, the hardware was machined and assembled in a factory using lathe machines and other machining tools to make sure the system is as precise as needed. The system was tested and successfully achieved accurate solar tracking of the sun throughout the day. Thus, we conclude that a relatively large-scale solar tracker for PDCs is possible to create with a manageable budget.

## Electronic Schamtic diagram of the system

Here’s an electronic schematic of the system showing the connections between
the components of the system.

![Schematic diagram](https://user-images.githubusercontent.com/96639538/229315419-89a1bec9-e328-4acd-96cf-6917e8a6276c.png)

## Sun position calculator code

The project involved creating calculations in C, implemented on an MCS for a microcontroller. The code includes variables for time and location, which can be changed to any location worldwide for the next 27 years. The project follows the AutoSAR Layered Architecture and is split into four system layers: Microcontroller Abstraction Layer, Electronic Unit Abstraction Layer, Application, and Utilities. The code is designed to take a step every 10 minutes, with peak efficiency achieved at 10-15 minute intervals. The lack of sensors means the code had to be more extensive, and a flowchart is provided to illustrate how elevation and azimuth angles are reached.

Note that all of this is explained in detail in the thesis attached above.

Here's a flowchart illustrating the logic and sequence behind the system's operation.

![Flowchart of the code](https://user-images.githubusercontent.com/96639538/229315514-b3090b51-1346-4c88-90db-b2736a04a5e9.png)

## Hardware Implementation

Details about the setup and implementation are included in the thesis

![Picture of the whole assembly](https://user-images.githubusercontent.com/96639538/229315579-2e92928c-c237-46be-8021-033fbd4b0710.png)


### Timelape of the Solar Tracker operating

<video width="320" height="240" controls>
  <source src="https://imgur.com/a/eIkEbnb" type="video/mp4">
  Your browser does not support the video tag.
</video>



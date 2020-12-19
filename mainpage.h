/**
* @mainpage
* @section intro Introduction
* The Tower of Hanoi is a mathematical game or puzzle. 
* The board consists of three rods and a number of disks of different sizes, which can slide onto any rod. 
* At the beginning, all disks are placed on the left rod in ascending order of their size, the smallest disk at the top.
* 
* The objective of the puzzle is to move the entire stack of disks from the left to the right rod, obeying the following rules:
* + Only one disk can be moved at a time.
* + Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
* + No larger disk may be placed on top of a smaller disk.
* 
* The minimal number of moves required to solve a Tower of Hanoi puzzle is 2n − 1, where n is the number of disks.
* (source: Wikipedia)
* 
* @section objective Assignment Objective
* In this assignment the recursiver solver for the Tower of Hanoi puzzle shall be implemented together with
* the required Abstract Data Types.

* Abstract Data Types for single disks (`toh_disc.*`) and the 'Tower of Hanoi' board (`toh_board.*`) are required.
* The 'Tower of Hanoi' solver (`toh_solver.*`) is not an ADT but a function library.
* 
* **Configuration**

* A configurable number of disk instances shall be available, this number is configered in `config.c` `MAX_DISKS`.
* There shall be exactly one instance of a board available.
*
* Other configuration options affects the visualization only, but has no effect on the game.
* 
* **Setup and Execution**

* The solver shall initialize the board with a given number of disks. This number must be less the configured
* maximum number of disks. Whereas the `MAX_DISKS` defines the number of avialable disk instances, 
* the number of disks applied to the initialization function of the solver defines the number of disks for the
* next game.
*
* After the board is initialized via solver, the solver shall solve that game using the following recursive algorithm:
* -# move (n-1) disks from source rod to intermediate rod using target rod as buffer
* -# move remaining (1) disk from source rod to target rod
* -# move (n-1) disks from intermediate rod to target rod using source rod as buffer
* until all disks are moved from the left to the right rod.
*
* **Visualization**

* The solver uses the ready-to-use Tower of Hanoi visualizer (`toh_visualizer.h`) to present the ANSI graphic of the game.
* A printout using function `toh_visualize(...)` is required 
* + after the board is initialized
* + after the move of a single disk
* + after the game is completely solved, a message telling about success or error can be applied to this viusalization step.
*
* @section assignment Assignment
* -# Complete forward declarations, types, and function for ADTs in `toh_disk.h` and `toh_board.h` as well as in `toh_solver.h`.
*   - Types in template files may be marked as `<type>` within header and source files or may be omitted completely. Replace `<type>`
*     with the correct type and complete missing types.
*   - Parameter lists of function in a template files may be missing or incomplete
* -# Make the program and tests compile: Implement all functions declared in the headers EMTPY (return nothing, 0, false as required)
*   - All unit tests shall run but FAIL after this step
*   - **--COMMIT--**
* -# Implement the empty functions one by one to make the unit tests pass one by one.
*   - Proposed order: disk, board, solver.
*   - The purpose of a function is specified as API documentation within the header files.
*   - Obey comments in source files.
*   - **--COMMIT-- after each implemented function.**
* -# Implement the missing parts to run the game in `toh_main_driver.c` methods
* -# Run the game and enjoy
*
* @section notes Notes
* -# This program requires compile option `-std=gnu11` becuase timer functions, please don't change. 
*    gnu11 extends c11 and is expected not to cause an troubles or differences in implementation
* -# Visualization is implemented for Linux shell, it will not work on Windows.
* -# Sometimes changes are not properly detected by incremental builds. If something very strange 
*    happens during compilation, try to run `make clean` followed by `make` to start a clean build.
*    This approach is also recommended after everthing is done, because some compiler warning appears
*    only in clean builds. 
*/
/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Visualizer
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Prints the Tower of Hanoi to standard output
 * ----------------------------------------------------------
 */
#ifndef ___TOH_VISUALIZER_H
#define ___TOH_VISUALIZER_H

#include <stdbool.h>

#include "toh_board.h"
#include "toh_disk.h"

/**
 * Initializes the ToH visualization with required attributes.
 * 
 * @param disk_count The total number of disks on the board.
 */
void toh_init_visualizer(unsigned short disk_count);

/**
 * Specifies whether or not visualization is enabled.
 * With enabled visualization, ToH board is shown on
 * standard output and each visualization step adds a delay.
 * Disabled visualization does neither print the board
 * nor does it add a delay. 
 * 
 * Default value is enabled. This feature is intended for 
 * automatic testing.
 * 
 * @param disable True to disable, false to enable the visualizer.
 */
void toh_disable_visualizer(bool disable);

/**
 * Prints the current configuration of the Tower of Hanoi board.
 * 
 * @param TohBoard The Tower of Hanoi Board to print.
 * @param move_count The number of moves so far.
 * @param msg The status message to print, may be 0 or empty.
 */
void toh_visualize(TohBoard board, unsigned int move_count);

/**
 * Same as function `toh_visualize(board, move_count)` but is
 * capable of printing an additional text message.
 * 
 * @param TohBoard The Tower of Hanoi Board to print.
 * @param move_count The number of moves so far.
 * @param msg The status message to print, may be 0 or empty.
 */
void toh_visualize_with_msg(TohBoard board, unsigned int move_count, char* msg);

#endif
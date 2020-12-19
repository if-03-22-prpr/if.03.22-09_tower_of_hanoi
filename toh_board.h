/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Board / Game
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
 * The declaration of an Abstract Data Type representing
 * a game board for Tower of Hanoi.
 * 
 * @see toh_solver.h for details regarding *Tower of Hanoi*.
 * ----------------------------------------------------------
 */

/* == !Include guard and required includes need to be added */


/** The enumeration of available rods: LEFT, MIDDLE, RIGHT. */

/** Declares type for the 'Tower of Hanoi' board */

/**
 * Provides the instance of the 'Tower of Hanoi' board.
 * Exactly one instance is supported.
 * 
 * @return TohBoard The board instance.
 */
<type> tb_get_board();

/**
 * Removes all disks from any rod of the given board.
 * 
 * @param board The board instance in focus.
 */
<type> tb_clear_board(<params>);

/**
 * Determines whether or not the given board is valid.
 * A board is NOT valid, if it is 0.
 * 
 * @param board The board to evaluate.
 * @return If the given board is valid, false otherwise.
 */
<type> tb_is_valid(<params>);

/**
 * Provides the top-most disk of the given rod and removes it from this rod.
 * 
 * @param board The board instance in focus.
 * @param rodName The rod from which the disk shall be taken and removed.
 * @return The removed disk or 0, if no disk was on the rod.
 */
<type> tb_pop_disk(<params>);

/**
 * Applies the given disk to the given rod, if this 
 * is allowed according to the rules.
 * 
 * @param board The board instance in focus.
 * @param rodName The rod on which the disk shall be placed.
 * @param disk The disk to place on the rod.
 * @return True if the disk could be legally placed on the rod 
 * (move is allowed and disk is valid), false otherwise.
 */
<type> tb_push_disk(<params>);

/**
 * Provides the disk from the named rod at the given position.
 * 
 * @param board The board instance in focus.
 * @param rodName The rod on which the disk shall be placed.
 * @param idx The index of the desired disk on the named rod. 
 *        Index 0 addresses the bottom-most disk.
 * @return The addressed disk or 0, if not disk is located on the
 *         index position of the named rod.
 */
<type> tb_get_disk(<params>);

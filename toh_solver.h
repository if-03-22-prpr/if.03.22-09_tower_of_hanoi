/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Board / Game
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
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
 * ----------------------------------------------------------
 */

/* == !Include guard and required includes need to be added */

/**
 * Initials a 'Tower of Hanoi' board with the given number of disks.
 * To initialize the board, all reqired disks are placed on the left rod
 * in ascending order of their size, the smallest disk at the top. 
 * The middle and right rod are empty.
 * 
 * All disks are initialized accordingly.
 * 
 * @param disk_count The number of disks to use. Must be less than 'MAX_DISKS'.
 */
<type> ts_init(<params>);

/**
 * Solves the puzzle by moving all disks from the left rod to the right rod.
 * In fact, this is the only function needed to 'play' the game after the
 * board was initialized.
 * 
 */
<type> ts_solve();

#endif

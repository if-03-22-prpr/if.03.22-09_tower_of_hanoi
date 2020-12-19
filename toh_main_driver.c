/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Truth Table
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
 * Truth Table Generator Application.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "toh_solver.h"
#include "toh_visualizer.h"

/* Forward declaration, required for test mode only. */
void toh_visualize_last();

/** 
 * Prompts the user for the number of disk of the next game.
 * and returns that value.
 */
unsigned short ui_prompt_for_disk_count();

/** 
 * ui_branch handles the user interface mode of the application.
 * @see main, test_branch.
 */
void ui_branch(unsigned short disk_count);

/* Main function evaluates the number of command line arguments.
 * If the user passed one main switches into test mode, i.e., that
 * the function test_branch() is called and the command line argument
 * is handed over to this function. If no command line argument is given
 * main switches into user interface mode and delegates the handling
 * of this to the function ui_branch().
 * @see test_branch, ui_branch.
 */
int main(int argc, char *argv[])
{
	char* tmp;
	unsigned short disk_count = 1;

	/* NOTE: Don't change this function, required for auto. testing */
	/* Implement ui_branch and ui_prompt_for_disk_count instead */
	if (argc > 1) {
		disk_count = strtoul(argv[1], &tmp, 10);
		toh_disable_visualizer(true);
	} else {
		disk_count = ui_prompt_for_disk_count();
	}
	ui_branch(disk_count);
	if (argc > 1) {
		toh_visualize_last();
	}
	return 0;
}

unsigned short ui_prompt_for_disk_count() {

	/* == YOUT IMPLEMENTATION GOES HERE == */

	/* Hint: scanf for interactive disk count */
}

void ui_branch(unsigned short disk_count) {

	/* == YOUT IMPLEMENTATION GOES HERE == */
	
	/* initialize the solver */

	/* solve the game */

}

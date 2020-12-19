/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Implementation of UTs for Tower of Hanoi Disk
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT ToH Disk.
 * ----------------------------------------------------------
 */

#include "test_toh_solver.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "toh_solver.h"
#include "toh_disk.h"
#include "toh_visualizer.h"

#define ASSERT_DISK_PILE_ON_ROD(board, rod_name, count, rod_label) _assert_disk_pile_on_rod(tc, board, rod_name, count, rod_label)
void _assert_disk_pile_on_rod(struct TestCase* tc, TohBoard board, RodName rod_name, unsigned short count, const char* rod_label) {
	Disk disk = 0;
	int idx = 0;

	/* check for expected disks */
	for (; idx < count; idx++) {
		disk = tb_get_disk(board, rod_name, idx);		
		ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk on position [%u] on %s rod", idx, rod_label));
		unsigned short act_size = td_get_size(disk);
		unsigned short exp_size = count - idx;
		ASSERT_TRUE(act_size == exp_size, MSG("Incorrect disk size on position [%u] on %s rod, expected [%u] but was [%u]", idx, rod_label, exp_size, act_size));
	}

	/* check empty positions */
	for (; idx < MAX_DISKS; idx++) {
		disk = tb_get_disk(board, rod_name, idx);		
		ASSERT_FALSE(td_is_valid(disk), MSG("Expected invalid disk on position [%u] on %s rod", idx, rod_label));
	}
}

#define TEST_SOLVE(disk_count) _test_solve(tc, disk_count)
void _test_solve(struct TestCase* tc, unsigned short disk_count) {
	ts_init(disk_count);
	toh_disable_visualizer(true);
	TohBoard board = tb_get_board();
	ASSERT_DISK_PILE_ON_ROD(board, LEFT,   disk_count, "left");
	ASSERT_DISK_PILE_ON_ROD(board, MIDDLE, 0, "middle");
	ASSERT_DISK_PILE_ON_ROD(board, RIGHT,  0, "right");
	ts_solve();
	ASSERT_DISK_PILE_ON_ROD(board, LEFT,   0, "left");
	ASSERT_DISK_PILE_ON_ROD(board, MIDDLE, 0, "middle");
	ASSERT_DISK_PILE_ON_ROD(board, RIGHT,  disk_count, "right");
}

/* ===================================================================== */

TEST(test_ts_init__with_one_disk) {
	ts_init(1);
	TohBoard board = tb_get_board();
	ASSERT_DISK_PILE_ON_ROD(board, LEFT,   1, "left");
	ASSERT_DISK_PILE_ON_ROD(board, MIDDLE, 0, "middle");
	ASSERT_DISK_PILE_ON_ROD(board, RIGHT,  0, "right");
}

TEST(test_ts_init__with_many_disks) {
	ts_init(MAX_DISKS);
	TohBoard board = tb_get_board();
	ASSERT_DISK_PILE_ON_ROD(board, LEFT,   MAX_DISKS, "left");
	ASSERT_DISK_PILE_ON_ROD(board, MIDDLE, 0, "middle");
	ASSERT_DISK_PILE_ON_ROD(board, RIGHT,  0, "right");
}

TEST(test_ts_init__subsequent_inits) {
	ts_init(MAX_DISKS);
	TohBoard board = tb_get_board();
	ASSERT_DISK_PILE_ON_ROD(board, LEFT,   MAX_DISKS, "left");
	ASSERT_DISK_PILE_ON_ROD(board, MIDDLE, 0, "middle");
	ASSERT_DISK_PILE_ON_ROD(board, RIGHT,  0, "right");

	ts_init(2);
	ASSERT_DISK_PILE_ON_ROD(board, LEFT,   2, "left");
	ASSERT_DISK_PILE_ON_ROD(board, MIDDLE, 0, "middle");
	ASSERT_DISK_PILE_ON_ROD(board, RIGHT,  0, "right");
}

TEST(test_ts_solve__one) {
	TEST_SOLVE(3);
}

TEST(test_ts_solve__two) {
	TEST_SOLVE(5);
}

TEST(test_ts_solve__three) {
	TEST_SOLVE(11);
}

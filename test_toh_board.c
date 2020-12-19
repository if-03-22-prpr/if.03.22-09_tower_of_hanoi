/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Implementation of UTs for Tower of Hanoi Borad
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT ToH Board.
 * ----------------------------------------------------------
 */

#include "test_toh_disk.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "toh_board.h"
#include "toh_disk.h"

#define ASSERT_VALID_DISK_BY_SIZE(disk, exp_size, rod_label) _assert_valid_disk_by_size(tc, disk, exp_size, rod_label)
void _assert_valid_disk_by_size(struct TestCase* tc, Disk disk, unsigned short exp_size, const char* rod_label) {
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk from %s rod", rod_label));
	unsigned short act_size = td_get_size(disk);
	ASSERT_TRUE(act_size == exp_size, MSG("Incorrect disk size, expected [%u] but was [%u]", exp_size, act_size));
}

TEST(test_tb_get_board__shall_provide_valid_board) {
	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
}

TEST(test_tb_get_board__shall_provide_the_same_board_each_time) {
	TohBoard ref_board = tb_get_board();
	for (int i = 0; i <= MAX_DISKS; i++) {
		TohBoard board = tb_get_board();
		ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
		ASSERT_TRUE(board == ref_board, MSG("Expected same board"));
	}
}

TEST(test_tb_clear_board__shall_ignore_invalid_board) {
	tb_clear_board(0);
}

TEST(test_tb_is_valid__shall_be_invalid_for_0_board) {
	ASSERT_FALSE(tb_is_valid(0), MSG("Expected board to be invalid"));
}

TEST(test_tb_push_disk__shall_push_valid_disks_on_each_rod) {
	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	tb_clear_board(board);

	Disk disk = 0;
	for (int size = MAX_DISKS; size > 0; size--) {
		disk = td_get_disk(size);
		ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", size));

		ASSERT_TRUE(tb_push_disk(board, LEFT, disk), MSG("Expected valid disk push on left rod of disk with size [%u]", size));
		ASSERT_TRUE(tb_push_disk(board, MIDDLE, disk), MSG("Expected valid disk push on middle rod of disk with size [%u]", size));
		ASSERT_TRUE(tb_push_disk(board, RIGHT, disk), MSG("Expected valid disk push on right rod of disk with size [%u]", size));
	}
}

TEST(test_tb_push_disk__shall_not_push_on_invalid_board) {
	Disk disk = td_get_disk(1);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk"));
	ASSERT_FALSE(tb_push_disk(0, LEFT,   disk), MSG("Expected invalid disk push on left rod of invalid board"));
	ASSERT_FALSE(tb_push_disk(0, MIDDLE, disk), MSG("Expected invalid disk push on middle rod of invalid board"));
	ASSERT_FALSE(tb_push_disk(0, RIGHT,  disk), MSG("Expected invalid disk push on right rod of invalid board"));
}

TEST(test_tb_push_disk__shall_not_push_invalid_disks_on_each_rod) {
	TohBoard board = tb_get_board();
	tb_clear_board(board);
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	ASSERT_FALSE(tb_push_disk(board, LEFT,   0), MSG("Expected invalid disk push on left rod for invalid disk"));
	ASSERT_FALSE(tb_push_disk(board, MIDDLE, 0), MSG("Expected invalid disk push on middle rod for invalid disk"));
	ASSERT_FALSE(tb_push_disk(board, RIGHT,  0), MSG("Expected invalid disk push on right rod for invalid disk"));
}

TEST(test_tb_push_disk__shall_not_push_wrong_disks_on_any_rod) {
	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	tb_clear_board(board);

	Disk disk = td_get_disk(1);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk"));
	tb_push_disk(board, LEFT, disk);
	tb_push_disk(board, MIDDLE, disk);
	tb_push_disk(board, RIGHT, disk);

	for (int size = 2; size <= MAX_DISKS; size++) {
		disk = td_get_disk(size);
		ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", size));
		ASSERT_FALSE(tb_push_disk(board, LEFT, disk),   MSG("Expected invalid disk push on left rod of disk with size [%u]", size));
		ASSERT_FALSE(tb_push_disk(board, MIDDLE, disk), MSG("Expected invalid disk push on middle rod of disk with size [%u]", size));
		ASSERT_FALSE(tb_push_disk(board, RIGHT, disk),  MSG("Expected invalid disk push on right rod of disk with size [%u]", size));
	}
}

TEST(test_tb_pop_disk__shall_pop_valid_disks_from_each_rod) {
	unsigned short larger = 2;
	unsigned short smaller = 1;

	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	tb_clear_board(board);

	Disk disk = td_get_disk(larger);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", larger));
	tb_push_disk(board, LEFT, disk);
	tb_push_disk(board, MIDDLE, disk);
	tb_push_disk(board, RIGHT, disk);
	disk = td_get_disk(1);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", smaller));
	tb_push_disk(board, RIGHT, disk);

	ASSERT_VALID_DISK_BY_SIZE(tb_pop_disk(board, LEFT), larger, "left");
	ASSERT_TRUE(tb_pop_disk(board, LEFT) == 0, MSG("Did not disk from empty left rod"));

	ASSERT_VALID_DISK_BY_SIZE(tb_pop_disk(board, MIDDLE), larger, "middle");
	ASSERT_TRUE(tb_pop_disk(board, MIDDLE) == 0, MSG("Did not disk from empty middle rod"));

	ASSERT_VALID_DISK_BY_SIZE(tb_pop_disk(board, RIGHT), smaller, "right");
	ASSERT_VALID_DISK_BY_SIZE(tb_pop_disk(board, RIGHT), larger, "right");
	ASSERT_TRUE(tb_pop_disk(board, RIGHT) == 0, MSG("Did not disk from empty right rod"));
}

TEST(test_tb_pop_disk__shall_pop_invalid_disks_from_each_empty_rod) {
	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	tb_clear_board(board);

	ASSERT_TRUE(tb_pop_disk(board, LEFT) == 0,   MSG("Did not disk from empty left rod"));
	ASSERT_TRUE(tb_pop_disk(board, MIDDLE) == 0, MSG("Did not disk from empty middle rod"));
	ASSERT_TRUE(tb_pop_disk(board, RIGHT) == 0,  MSG("Did not disk from empty right rod"));
}

TEST(test_tb_pop_disk__shall_pop_invalid_disks_from_invalid_board) {
	ASSERT_TRUE(tb_pop_disk(0, LEFT) == 0,   MSG("Did not disk from empty board"));
	ASSERT_TRUE(tb_pop_disk(0, MIDDLE) == 0, MSG("Did not disk from empty board"));
	ASSERT_TRUE(tb_pop_disk(0, RIGHT) == 0,  MSG("Did not disk from empty board"));
}

TEST(test_tb_get_disk__shall_provide_valid_disks_from_each_rod) {
	unsigned short larger = 3;
	unsigned short large = 2;
	unsigned short small = 1;

	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	tb_clear_board(board);

	Disk disk = td_get_disk(larger);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", larger));
	tb_push_disk(board, RIGHT, disk);

	disk = td_get_disk(large);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", larger));
	tb_push_disk(board, MIDDLE, disk);
	tb_push_disk(board, RIGHT, disk);

	disk = td_get_disk(small);
	ASSERT_TRUE(td_is_valid(disk), MSG("Expected valid disk [%u]", larger));
	tb_push_disk(board, LEFT, disk);
	tb_push_disk(board, MIDDLE, disk);
	tb_push_disk(board, RIGHT, disk);

	ASSERT_VALID_DISK_BY_SIZE(tb_get_disk(board, LEFT, 0), small, "left");

	ASSERT_VALID_DISK_BY_SIZE(tb_get_disk(board, MIDDLE, 0), large, "middle");
	ASSERT_VALID_DISK_BY_SIZE(tb_get_disk(board, MIDDLE, 1), small, "middle");

	ASSERT_VALID_DISK_BY_SIZE(tb_get_disk(board, RIGHT, 0), larger, "left");
	ASSERT_VALID_DISK_BY_SIZE(tb_get_disk(board, RIGHT, 1), large, "left");
	ASSERT_VALID_DISK_BY_SIZE(tb_get_disk(board, RIGHT, 2), small, "right");
}

TEST(test_tb_get_disk__shall_provide_0_for_invalid_board) {
	ASSERT_TRUE(tb_get_disk(0, LEFT, 0) == 0, MSG("Expected 0 disk for invalid board"));
	ASSERT_TRUE(tb_get_disk(0, MIDDLE, 0) == 0, MSG("Expected 0 disk for invalid board"));
	ASSERT_TRUE(tb_get_disk(0, RIGHT, 0) == 0, MSG("Expected 0 disk for invalid board"));
}

TEST(test_tb_get_disk__shall_provide_0_for_empty_rod_positions) {
	TohBoard board = tb_get_board();
	ASSERT_TRUE(tb_is_valid(board), MSG("Expected valid board"));
	tb_clear_board(board);

	for (int i = 0; i < MAX_DISKS + 10; i++) {
		ASSERT_TRUE(tb_get_disk(board, LEFT,   i) == 0, MSG("Expected 0 disk for empty rod"));
		ASSERT_TRUE(tb_get_disk(board, MIDDLE, i) == 0, MSG("Expected 0 disk for empty rod"));
		ASSERT_TRUE(tb_get_disk(board, RIGHT,  i) == 0, MSG("Expected 0 disk for empty rod"));
	}
}

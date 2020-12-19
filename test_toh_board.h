/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Unit Tests for Tower of Hanoi Board
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT ToH Board.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_TOH_BOARD_H
#define ___TEST_TOH_BOARD_H

#include "shortcut.h"

TEST(test_tb_get_board__shall_provide_valid_board);
TEST(test_tb_get_board__shall_provide_the_same_board_each_time);
TEST(test_tb_is_valid__shall_be_invalid_for_0_board);

TEST(test_tb_push_disk__shall_push_valid_disks_on_each_rod);
TEST(test_tb_push_disk__shall_not_push_on_invalid_board);
TEST(test_tb_push_disk__shall_not_push_invalid_disks_on_each_rod);
TEST(test_tb_push_disk__shall_not_push_wrong_disks_on_any_rod);

TEST(test_tb_pop_disk__shall_pop_valid_disks_from_each_rod);
TEST(test_tb_pop_disk__shall_pop_invalid_disks_from_each_empty_rod);
TEST(test_tb_pop_disk__shall_pop_invalid_disks_from_invalid_board);

TEST(test_tb_get_disk__shall_provide_valid_disks_from_each_rod);
TEST(test_tb_get_disk__shall_provide_0_for_invalid_board);
TEST(test_tb_get_disk__shall_provide_0_for_empty_rod_positions);

#endif

/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Test Driver for Truth Table Generator
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Executes all unit tests of Truth Table Generator.
 * ----------------------------------------------------------
 */

#include "shortcut.h"
#include "test_toh_disk.h"
#include "test_toh_board.h"
#include "test_toh_solver.h"

int main(int argc, char *argv[])
{
	ADD_TEST(test_td_get_disk__shall_provide_valid_disk_for_each_size);
	ADD_TEST(test_td_get_disk__shall_provide_0_for_invalid_size);

	ADD_TEST(test_td_is_valid__shall_be_valid_for_valid_disks);
	ADD_TEST(test_td_is_valid__shall_be_invalid_for_0_disks);
	ADD_TEST(test_td_is_valid__shall_be_invalid_for_disks_with_invalid_sizes);

	ADD_TEST(test_td_get_size__shall_provide_size_of_valid_disk);
	ADD_TEST(test_td_get_size__shall_provide_0_for_invalid_disk);

	ADD_TEST(test_td_is_smaller__shall_be_true_for_smaller_disks);
	ADD_TEST(test_td_is_smaller__shall_be_false_for_larger_disks);
	ADD_TEST(test_td_is_smaller__shall_be_false_for_invalid_disk);
	ADD_TEST(test_td_is_smaller__shall_be_false_for_invalid_candidates);

	ADD_TEST(test_td_is_smaller__shall_be_false_for_invalid_attributes);

	ADD_TEST(test_tb_get_board__shall_provide_valid_board);
	ADD_TEST(test_tb_get_board__shall_provide_the_same_board_each_time);
	ADD_TEST(test_tb_is_valid__shall_be_invalid_for_0_board);

	ADD_TEST(test_tb_push_disk__shall_push_valid_disks_on_each_rod);
	ADD_TEST(test_tb_push_disk__shall_not_push_on_invalid_board);
	ADD_TEST(test_tb_push_disk__shall_not_push_invalid_disks_on_each_rod);
	ADD_TEST(test_tb_push_disk__shall_not_push_wrong_disks_on_any_rod);

	ADD_TEST(test_tb_pop_disk__shall_pop_valid_disks_from_each_rod);
	ADD_TEST(test_tb_pop_disk__shall_pop_invalid_disks_from_each_empty_rod);
	ADD_TEST(test_tb_pop_disk__shall_pop_invalid_disks_from_invalid_board);

	ADD_TEST(test_tb_get_disk__shall_provide_valid_disks_from_each_rod);
	ADD_TEST(test_tb_get_disk__shall_provide_0_for_invalid_board);
	ADD_TEST(test_tb_get_disk__shall_provide_0_for_empty_rod_positions);

	ADD_TEST(test_ts_init__with_one_disk);
	ADD_TEST(test_ts_init__with_many_disks);
	ADD_TEST(test_ts_init__subsequent_inits);

	ADD_TEST(test_ts_solve__one);
	ADD_TEST(test_ts_solve__two);
	ADD_TEST(test_ts_solve__three);
	
	run_tests();
	return 0;
}

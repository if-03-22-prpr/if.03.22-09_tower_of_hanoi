/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Unit Tests for Boolean Term
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT ToH Disk.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_TOH_DISK_H
#define ___TEST_TOH_DISK_H

#include "shortcut.h"

TEST(test_td_get_disk__shall_provide_valid_disk_for_each_size);
TEST(test_td_get_disk__shall_provide_0_for_invalid_size);

TEST(test_td_is_valid__shall_be_valid_for_valid_disks);
TEST(test_td_is_valid__shall_be_invalid_for_0_disks);
TEST(test_td_is_valid__shall_be_invalid_for_disks_with_invalid_sizes);

TEST(test_td_get_size__shall_provide_size_of_valid_disk);
TEST(test_td_get_size__shall_provide_0_for_invalid_disk);

TEST(test_td_is_smaller__shall_be_true_for_smaller_disks);
TEST(test_td_is_smaller__shall_be_false_for_larger_disks);
TEST(test_td_is_smaller__shall_be_false_for_invalid_disk);
TEST(test_td_is_smaller__shall_be_false_for_invalid_candidates);

TEST(test_td_is_smaller__shall_be_false_for_invalid_attributes);
#endif

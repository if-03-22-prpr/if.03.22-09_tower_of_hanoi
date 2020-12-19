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

#include "test_toh_disk.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "toh_disk.h"


TEST(test_td_get_disk__shall_provide_valid_disk_for_each_size) {
	Disk disk = 0;
	for (int size = 1; size <= MAX_DISKS; size++) {
		disk = td_get_disk(size);
		ASSERT_TRUE(disk != 0, MSG("Valid disk expected for size [%u]", size));
	}
}

TEST(test_td_get_disk__shall_provide_0_for_invalid_size) {
	int sizes[] = {0, MAX_DISKS + 1};
	Disk disk = 0;
	for (int i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
		disk = td_get_disk(sizes[i]);
		ASSERT_TRUE(disk == 0, MSG("0 disk expected for size [%u]", 0));
	}
}

TEST(test_td_is_valid__shall_be_valid_for_valid_disks) {
	Disk disk = 0;
	for (int size = 1; size <= MAX_DISKS; size++) {
		disk = td_get_disk(size);
		ASSERT_TRUE(td_is_valid(disk), MSG("Valid expected for disk of size [%u]", size));
	}
}

TEST(test_td_is_valid__shall_be_invalid_for_0_disks) {
	Disk disk = 0;
	ASSERT_FALSE(td_is_valid(disk), MSG("Invalid expected for 0 disk"));
}

TEST(test_td_is_valid__shall_be_invalid_for_disks_with_invalid_sizes) {
	/* size cannot be set via public API */
}

TEST(test_td_get_size__shall_provide_size_of_valid_disk) {
	Disk disk = 0;
	for (int size = 1; size <= MAX_DISKS; size++) {
		disk = td_get_disk(size);
		ASSERT_TRUE(td_is_valid(disk), MSG("Valid expected for disk of size [%u]", size));
		unsigned short act_size = td_get_size(disk);
		ASSERT_TRUE(act_size == size, MSG("Incorrect size, expected [%u] but was [%u]", size, act_size));
	}
}

TEST(test_td_get_size__shall_provide_0_for_invalid_disk) {
	unsigned short act_size = td_get_size(0);
	ASSERT_TRUE(act_size == 0, MSG("Incorrect size for 0 disk, expected [%u] but was [%u]", 0, act_size));
}

TEST(test_td_is_smaller__shall_be_true_for_smaller_disks) {
	Disk disk = td_get_disk(MAX_DISKS);
	Disk candidate = 0;
	for (int size = MAX_DISKS - 1; size > 0; size--) {
		candidate = td_get_disk(size);
		ASSERT_TRUE(td_is_smaller(disk, candidate), MSG("Disk of size [%u] is expected being smaller than disk of size [%u]", td_get_size(disk), td_get_size(candidate)));
		disk = candidate;
	}
}

TEST(test_td_is_smaller__shall_be_false_for_larger_disks) {
	Disk disk = td_get_disk(1);
	Disk candidate = 0;
	for (int size = 2; size <= MAX_DISKS; size++) {
		candidate = disk;
		ASSERT_FALSE(td_is_smaller(disk, candidate), MSG("Disk of size [%u] is NOT expected being smaller than disk of size [%u]", td_get_size(disk), td_get_size(candidate)));
		candidate = td_get_disk(size);
		ASSERT_FALSE(td_is_smaller(disk, candidate), MSG("Disk of size [%u] is NOT expected being smaller than disk of size [%u]", td_get_size(disk), td_get_size(candidate)));
		disk = candidate;
	}
}

TEST(test_td_is_smaller__shall_be_false_for_invalid_disk) {
	Disk disk = td_get_disk(1);
	ASSERT_TRUE(td_is_valid(disk), MSG("Valid disk expected"));
	ASSERT_FALSE(td_is_smaller(0, disk), MSG("False expected for invalid target disk"));
}

TEST(test_td_is_smaller__shall_be_false_for_invalid_candidates) {
	Disk disk = td_get_disk(1);
	ASSERT_TRUE(td_is_valid(disk), MSG("Valid disk expected"));
	ASSERT_FALSE(td_is_smaller(disk, 0), MSG("False expected for invalid candidate disk"));
}

TEST(test_td_is_smaller__shall_be_false_for_invalid_attributes) {
	ASSERT_FALSE(td_is_smaller(0, 0), MSG("False expected for invalid disks"));
}

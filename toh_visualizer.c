/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: n/a
 * ---------------------------------------------------------
 * Exercise Number: 09
 * Title:			Tower of Hanoi Visualizer
 * Author:			S. Schraml
 * Due Date:		n/a
 * ----------------------------------------------------------
 * Description:
 * Implementation of ToH Visualizer.
 * ----------------------------------------------------------
 */

#include "toh_visualizer.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "config.h"

/* The encapsulated visualizer data */
struct VisData {
    bool disabled;
    unsigned short refresh_line_count;
    unsigned short disk_count;
    int offset;
    int board_oversize;
    int left_rod_pos;
    int middle_rod_pos;
    int right_rod_pos;
    int last_move_count;
    int total_move_count;
    char* last_msg;
    unsigned short last_disk_count_left;
    unsigned short last_disk_count_middle;
    unsigned short last_disk_count_right;
};

/* The visualizer instance */
static struct VisData vis_data = {0};

/* Provides the number output lines for a configured game. */ 
static void _print_new_line() {
    vis_data.refresh_line_count++;
    printf("\n");
}

/* Prints the given disk on the given rod or a 'rod' marker if no disk is given */
static void _print_centered_disk(Disk disk, int center) {
    char symbol = '|';
    int width = 1;

    /* determine disk properties */
    if (td_is_valid(disk)) {
        width = 2 * td_get_size(disk) - 1;
        symbol = '#';
    }

    printf("\033[%dG", center - (width / 2)); /* set the cursor to the left border of the disk */
    for (int c = 0; c < width; c++) {
        printf("%c", symbol);
    }
}

/* Prints the bottom line of the board. */
static void _print_board() {
    if (vis_data.disk_count > 0) {
        printf("\033[2K");                   /* clear current line */
        printf("\033[%dG", vis_data.offset); /* set cursor to end of offset */
        int board_width = vis_data.left_rod_pos + vis_data.right_rod_pos + 2 * vis_data.board_oversize;
        for (int i = 0; i < board_width; i++) {
            printf("="); 
        }
        _print_new_line();
    }
}

/* Prints the status line */
static void _print_status_line(unsigned int move_count) {
    printf("\033[2K");                   /* clear current line */
    printf("\033[%dG", vis_data.offset); /* set cursor to end of offset */
    printf("Move %4u of %u", move_count, vis_data.total_move_count);
    _print_new_line();
}

/* Prints the message line */
static void _print_message(char* msg) {
    printf("\033[2K");                   /* clear current line */
    printf("\033[%dG", vis_data.offset); /* set cursor to end of offset */
    if (msg != 0) {
        printf("%s", msg);
    }
    _print_new_line();
}

/* Prints the game: disks and board */
static void _print_game(TohBoard board, unsigned int move_count, char* msg) {
    printf("\033[%dA", vis_data.refresh_line_count); /* move cursor to the first line of the game output */
    vis_data.refresh_line_count = 0;
    _print_new_line(); /* print an empty heading line */

    for (int disk_idx = vis_data.disk_count; disk_idx >= 0; disk_idx--) {
        printf("\033[2K");  /* clear current line */
        int offset = vis_data.offset + vis_data.board_oversize;
        _print_centered_disk(tb_get_disk(board, LEFT,   disk_idx), offset + vis_data.left_rod_pos);
        _print_centered_disk(tb_get_disk(board, MIDDLE, disk_idx), offset + vis_data.middle_rod_pos);
        _print_centered_disk(tb_get_disk(board, RIGHT,  disk_idx), offset + vis_data.right_rod_pos);
        _print_new_line();
    }
    _print_board(vis_data.disk_count + 2);
    _print_status_line(move_count);
    _print_message(msg);
    _print_new_line(); /* blank line */
}

void toh_init_visualizer(unsigned short disk_count) {
    if (disk_count > 0) {
        vis_data.refresh_line_count = 0;
        vis_data.disk_count = disk_count;
        vis_data.total_move_count = pow(2, disk_count) - 1;
        vis_data.offset = VIS_BOARD_OFFSET;
        vis_data.board_oversize = 2;
        int rod_distance = 2 * disk_count - 1 + 2; /* width of the largest disk + 1 gap on each side */
        vis_data.left_rod_pos = rod_distance / 2 ;
        vis_data.middle_rod_pos = vis_data.left_rod_pos + rod_distance;
        vis_data.right_rod_pos = vis_data.middle_rod_pos + rod_distance;
    }
}

void toh_disable_visualizer(bool disable) {
    vis_data.disabled = disable;
}

void toh_visualize(TohBoard board, unsigned int move_count) {
    toh_visualize_with_msg(board, move_count, 0);
}

void toh_visualize_with_msg(TohBoard board, unsigned int move_count, char* msg) {
    vis_data.last_move_count = move_count;
    vis_data.last_msg = msg;

    if (!vis_data.disabled) {
        if (!tb_is_valid(board)) {
            printf("invalid board given!");
        } else {
            _print_game(board, move_count, msg);
            if (MOVE_DELAY > 0) {
                usleep(MOVE_DELAY * 100 * 1000);
            }
        }
    }
}

void toh_visualize_last() {
    bool disabled = vis_data.disabled;
    vis_data.disabled = false;
    TohBoard board = tb_get_board();
    toh_visualize_with_msg(board, vis_data.last_move_count, vis_data.last_msg);
    vis_data.disabled = disabled;
}

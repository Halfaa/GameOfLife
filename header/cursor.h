#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <termcap.h>
#include <curses.h>
#include <string.h>


int init_term();
void check_input(int height,int width,Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void move_cursor(int x,int y);
void disable_raw_mode();
void enable_raw_mode();
void disable_block_mode();
void enable_block_mode();
void enable_input_mode();
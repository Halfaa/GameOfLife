#ifndef __GRID_H_
    #define __GRID_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define NEIGHBOURS_MAX 8

struct cell_s {
    int x;
    int y;
    int state;
};

typedef struct cell_s Cell;

void generate_grid(int height,int width,Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void print_grid(Cell grid[MAX_HEIGHT][MAX_WIDTH],int height,int width);
int count_neighbors(Cell grid[MAX_HEIGHT][MAX_WIDTH],int x, int y);
void print_neighbours(Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void place_cell(Cell grid[MAX_HEIGHT][MAX_WIDTH], int x, int y,int height,int width);
void generate_blank_grid(int height,int width,Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void fill_grid(Cell grid[MAX_HEIGHT][MAX_WIDTH],int height,int widht,char *patern);
void copyGrid(Cell grid[MAX_HEIGHT][MAX_WIDTH],Cell copy[MAX_HEIGHT][MAX_WIDTH],int height,int width);


#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <grid.h>

int getFileSettings(Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void getWidhtHeight(int *height,int *widht,FILE *settings);
void getPatern(FILE *settings,int height,int widht,char *patern);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <grid.h>

int getFileSettings(Cell grid[MAX_HEIGHT][MAX_WIDTH],int *widht,int *height);
void getWidhtHeight(int *height,int *widht,FILE *settings);
char* getPatern(FILE *settings,int height,int widht,char *patern);
#include <grid.h>
#include <unistd.h>

#define DEFAULT_HEIGHT 20
#define DEFAULT_WIDTH 20
#define DEFAULT_GEN 1

void next_generation(Cell grid[MAX_HEIGHT][MAX_WIDTH], int height,int width);
void randomMod(int compteur,int gen,int speed,Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void paternMod(int compteur,int gen,int height,int width,int speed,Cell grid[MAX_HEIGHT][MAX_WIDTH]);
void customMod(Cell grid[MAX_HEIGHT][MAX_WIDTH],int gen,int speed);
void customPatern(Cell grid[MAX_HEIGHT][MAX_WIDTH],int gen,int speed);
int askGenNumber();
int askSpeed();
int askPatern();
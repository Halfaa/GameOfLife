#include <grid.h>
#include <game.h>
#include <settings.h>
#include <main.h>
#include <cursor.h>


int main(){
    
    Cell grid[MAX_HEIGHT][MAX_WIDTH];

    initGame(grid);
    atexit(reset_terminal);
    return 0;
}


void initGame(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    int compteur = 0;
    int gen = askGenNumber();
    int speed = askSpeed();
    int choix = askPatern();
    int height,width = 0;

    switch(choix){
        case 1:
            getFileSettings(grid,&height,&width);
            paternMod(compteur,gen,height,width,speed,grid);
            break;
        case 2:
            generate_grid(DEFAULT_HEIGHT,DEFAULT_WIDTH,grid);
            randomMod(compteur,gen,speed,grid);
            break;
        case 3:
            customMod(grid,gen,speed);
            break;
    }
}

void reset_terminal(){
    disable_raw_mode();
}


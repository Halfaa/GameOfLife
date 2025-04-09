#include <grid.h>
#include <game.h>
#include <settings.h>
#include <main.h>


int main(){
    
    Cell grid[MAX_HEIGHT][MAX_WIDTH];
    initGame(grid);
    return 0;
}


void initGame(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    int compteur = 0;
    int gen = askGenNumber();
    int speed = askSpeed();
    int height,width = 0;
    if(askPatern() == 1){
        getFileSettings(grid,&height,&width);
        paternMod(compteur,gen,height,width,speed,grid);
        
    }else{
        generate_grid(DEFAULT_HEIGHT,DEFAULT_WIDTH,grid);
        randomMod(compteur,gen,speed,grid);
    }
}

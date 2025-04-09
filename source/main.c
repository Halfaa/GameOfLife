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
    if(askPartern() == 1){
        generate_grid(MAX_HEIGHT,MAX_WIDTH,grid);
        getFileSettings(grid);
    }else{
        generate_grid(MAX_HEIGHT,MAX_WIDTH,grid);
    }
    while(compteur<gen){
        system("clear");
        next_generation(grid);
        printf("Next generation %d \n",compteur+1);
        print_grid(grid);
        usleep(speed);
        compteur+=1;
    }

}

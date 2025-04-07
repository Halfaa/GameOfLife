#include <grid.h>
#include <game.h>

int main(){
    Cell grid[MAX_HEIGHT][MAX_WIDTH];
    generate_grid(MAX_HEIGHT,MAX_WIDTH,grid);
    print_grid(grid);
    //print_neighbours(grid);
    int gen = 0;
    while(gen<10){
        printf("Next generation %d \n",gen);
        next_generation(grid);
        print_grid(grid);
        gen+=1;
    }
    

    return 0;
}
#include <grid.h>
#include <game.h>
#include <settings.h>
#include <main.h>

int main(){
    //initGame();
    getFileSettings();

    return 0;
}


void initGame(){
    int gen,compteur = 0;
    Cell grid[MAX_HEIGHT][MAX_WIDTH];
    generate_grid(MAX_HEIGHT,MAX_WIDTH,grid);
    printf("Entrez le nombre de générations voulu : ");
    scanf("%d", &gen);

    while(compteur<gen){
        system("clear");
        next_generation(grid);
        printf("Next generation %d \n",compteur+1);
        print_grid(grid);
        usleep(100000);
        compteur+=1;
    }

}

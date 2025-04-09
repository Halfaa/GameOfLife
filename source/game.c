#include <grid.h>

void next_generation(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    Cell copy[MAX_HEIGHT][MAX_WIDTH];
    copyGrid(grid,copy);

    for (int x = 0; x < MAX_HEIGHT; x++) {
        for (int y = 0; y < MAX_WIDTH; y++) {
            Cell cell;
            cell.x = copy[x][y].x;
            cell.y = copy[x][y].y;
            cell.state = copy[x][y].state;
            int neighbors = count_neighbors(copy, cell.x, cell.y);
            if (cell.state == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    cell.state = 0;
                }
            } else {
                if (neighbors == 3) {
                    cell.state = 1;
                }
            }
            grid[x][y].state = cell.state;
        }
    }  
}

int askPartern(){
    int patern = 0;
    printf("Entrez 1 pour un patern prédéfinis / Entrez 2 pour un patern aléatoire : ");
    scanf("%d", &patern);
    return patern;
}

int askSpeed(){
    int speed=0;
    printf("Entrez la vitesse d'évolution voulu (en seconde) : ");
    scanf("%d", &speed);
    return speed*100000;
}

int askGenNumber(){
    int gen = 0;
    printf("Entrez le nombre de générations voulu : ");
    scanf("%d", &gen);
    return gen;

}


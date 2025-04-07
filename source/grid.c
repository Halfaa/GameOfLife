#include <grid.h>

void generate_grid(int height,int width,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    srand(time(NULL));
    for (int x = 0; x < MAX_HEIGHT; x++) {
        for (int y = 0; y < MAX_WIDTH; y++) {
            Cell cell = {x,y,rand()%2};
            grid[x][y].x = cell.x;
            grid[x][y].y = cell.y;
            grid[x][y].state = cell.state;
        }
    }
}

void print_grid(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    for (int x = 0; x < MAX_HEIGHT; x++) {
        for (int y = 0; y < MAX_WIDTH; y++) {
            Cell cell = grid[x][y];
            printf("%d ", cell.state);
        }
        printf("\n");
    }
}

int count_neighbors(Cell grid[MAX_HEIGHT][MAX_WIDTH],int x, int y){
    int count=0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int new_x = x + i;
            int new_y = y + j;
            if (new_x >= 0 && new_x < MAX_HEIGHT && new_y >= 0 && new_y < MAX_WIDTH) {
                Cell neighbor = grid[new_x][new_y];
                count += neighbor.state;
            }
        }
    }
    return count;
}

void print_neighbours(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    for (int x = 0; x < MAX_HEIGHT; x++) {
        for (int y = 0; y < MAX_WIDTH; y++) {
            Cell cell = grid[x][y];
            printf("Nb voisin de %d:%d = %d ", x,y,count_neighbors(grid,cell.x,cell.y));
            printf("\n");
        }
        
    }
}

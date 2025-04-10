#include <grid.h>
#include <cursor.h>

void generate_grid(int height,int width,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    srand(time(NULL));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Cell cell = {x,y,rand()%2};
            grid[x][y].x = cell.x;
            grid[x][y].y = cell.y;
            grid[x][y].state = cell.state;
        }
    }
}

void print_grid(Cell grid[MAX_HEIGHT][MAX_WIDTH],int height,int width){
    printf ("\033[2J");
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            Cell cell = grid[x][y];
            if(cell.state == 0){
                printf("\e[30m%d", cell.state);
            }else if(cell.state == 1){
                printf("\e[32m%d",cell.state);
            }
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

void fill_grid(Cell grid[MAX_HEIGHT][MAX_WIDTH],int height,int widht,char *patern){
    int index = 0;
    
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < widht; y++) {
            Cell cell = {x,y,patern[index] - '0'};
            index+=1;
            grid[x][y].x = cell.x;
            grid[x][y].y = cell.y;
            grid[x][y].state = cell.state;
        }
    }
}

void generate_blank_grid(int height,int width,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            Cell cell = {x,y,0};
            grid[x][y].x = cell.x;
            grid[x][y].y = cell.y;
            grid[x][y].state = cell.state;
        }
    }
}

void place_cell(Cell grid[MAX_HEIGHT][MAX_WIDTH], int x, int y,int height,int width){
    if(grid[x][y].state == 1){
        grid[x][y].state = 0;
    }else{
        grid[x][y].state = 1;
    }
    move_cursor(x,y);
    print_grid(grid,height,width);
    

}

void copyGrid(Cell grid[MAX_HEIGHT][MAX_WIDTH],Cell copy[MAX_HEIGHT][MAX_WIDTH], int height,int width){
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            copy[x][y].x = grid[x][y].x;
            copy[x][y].y = grid[x][y].y;
            copy[x][y].state = grid[x][y].state;
        }
    }
}
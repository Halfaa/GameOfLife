#include <grid.h>

void next_generation(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    for (int x = 0; x < MAX_HEIGHT; x++) {
        for (int y = 0; y < MAX_WIDTH; y++) {
            Cell cell;
            cell.x = grid[x][y].x;
            cell.y = grid[x][y].y;
            cell.state = grid[x][y].state;
            int neighbors = count_neighbors(grid, cell.x, cell.y);
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


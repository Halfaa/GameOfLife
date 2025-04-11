#include <grid.h>
#include <game.h>
#include <cursor.h>

void next_generation(Cell grid[MAX_HEIGHT][MAX_WIDTH], int height,int width){
    Cell copy[MAX_HEIGHT][MAX_WIDTH];
    copyGrid(grid,copy,height,width);

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
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

void paternMod(int compteur,int gen,int height,int width,int speed,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    char read_buffer;
    bool pause = false;
    while(compteur < gen){
        enable_raw_mode();
        disable_block_mode();
        if((read(STDIN_FILENO, &read_buffer, 1)) > 0){
            if(read_buffer == 'p'){
                pause = !pause;
            }
        }
        if(!pause){
                if(next_step(&compteur,gen,grid)==0){
                    break;
                };
                
            }
        usleep(speed);
    }
    disable_raw_mode();
}

void randomMod(int compteur,int gen,int speed,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    char read_buffer;
    bool pause = false;
    while(compteur < gen){
        enable_raw_mode();
        disable_block_mode();
        if((read(STDIN_FILENO, &read_buffer, 1)) > 0){
            if(read_buffer == 'p'){
                pause = !pause;
            }
        }
        if(!pause){
                if(next_step(&compteur,gen,grid)==0){
                    break;
                };
                
            }
        usleep(speed);
    }
    disable_raw_mode();
}

void customMod(Cell grid[MAX_HEIGHT][MAX_WIDTH],int gen,int speed){
    int ret = init_term();
    generate_blank_grid(DEFAULT_HEIGHT,DEFAULT_WIDTH,grid);
    enable_raw_mode();
    if(ret == 0){
        print_grid(grid,DEFAULT_HEIGHT,DEFAULT_WIDTH,DEFAULT_GEN);
        check_input(DEFAULT_HEIGHT,DEFAULT_WIDTH,grid);
        move_cursor(DEFAULT_WIDTH+1,0);
    }

    disable_raw_mode();
    customPatern(grid,gen,speed);
}

int askPatern(){
    int patern = 0;
    char buffer[4];
    printf("Entrez 1 pour un patern prédéfinis / Entrez 2 pour un patern aléatoire / Entrez 3 pour avoir accès au mod Custom : ");
    fflush(0);
    read(STDIN_FILENO,&buffer,sizeof(buffer));
    patern = atoi(buffer);
    return patern;
}

int askSpeed(){
    int speed=0;
    char buffer[4];
    printf("Entrez la vitesse d'évolution voulu (en seconde) : ");
    fflush(0);
    read(STDIN_FILENO,&buffer,sizeof(buffer));
    speed = atoi(buffer);
    return speed*100000;
}

int askGenNumber(){
    int gen = 0;
    char buffer[4];
    printf("Entrez le nombre de générations voulu : ");
    fflush(0);
    read(STDIN_FILENO,&buffer,sizeof(buffer));
    gen = atoi(buffer);
    return gen;
}

void customPatern(Cell grid[MAX_HEIGHT][MAX_WIDTH],int gen,int speed){
    int compteur = 0;
    char read_buffer;
    bool pause = false;
    while(compteur < gen){
        enable_raw_mode();
        disable_block_mode();
        if((read(STDIN_FILENO, &read_buffer, 1)) > 0){
            if(read_buffer == 'p'){
                pause = !pause;
            }
        }
        if(!pause){
                if(next_step(&compteur,gen,grid)==0){
                    break;
                };
                
            }
        if(pause && read_buffer=='n'){
                read_buffer='\0';
                if(next_step(&compteur,gen,grid)==0){
                    break;
                };
        }
        usleep(speed);
    }
    disable_raw_mode();
}


int next_step(int *compteur, int gen,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    next_generation(grid,DEFAULT_HEIGHT,DEFAULT_WIDTH);
    print_grid(grid,DEFAULT_HEIGHT,DEFAULT_WIDTH,*compteur+1);
    *compteur+=1;
    if(*compteur>=gen){return 0;};
    return 1;
}

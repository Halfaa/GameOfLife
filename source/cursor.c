#include <main.h>
#include <cursor.h>
#include <grid.h>

struct termios original;
struct termios terminal;
char *cm_cap;
char *term_type;

int init_term()
{
    int ret;
    term_type = getenv("TERM");
    cm_cap = tgetstr("cm", NULL);

    if (term_type == NULL)
    {
        fprintf(stderr, "TERM must be set (see 'env').\n");
        return -1;
    }

    ret = tgetent(NULL, term_type);

    if (ret == -1)
    {
        fprintf(stderr, "Could not access to the termcap database..\n");
        return -1;
    }
    else if (ret == 0)
    {
        fprintf(stderr, "Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_type);
        return -1;
    }

    return 0;
}

void check_input(int height, int widht,Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    char read_buffer[1] = {0};
    int x = 0;
    int y = 0;

    move_cursor(x,y);

    while(read(0, read_buffer, 1) != 0){
        fflush(0);
        read_buffer[0] = read_buffer[0];
        move_cursor(x,y);
        if (read_buffer[0] == 'd'){
            y++;
            if(y>=height){y=0;}
            move_cursor(x,y);
            
        }
        if (read_buffer[0] == 'z'){
            x--;
            if(x<0){x=widht;}
            move_cursor(x,y);
        }
        if (read_buffer[0] == 'q'){
            y--;
            if(y<0){y=height;}
            move_cursor(x,y);
            
        }
        if (read_buffer[0] == 's'){
            x++;
            if(x>=widht){x=0;}
            move_cursor(x,y);
        }
        if(read_buffer[0] == 'e'){
            place_cell(grid,x-1,y-1,height,widht);
            move_cursor(x,y);
        }
        if(read_buffer[0]=='c'){
            break;
        }
    }
}

void move_cursor(int x,int y){
    printf ("\033[%d;%dH",x,y);
    fflush(0);
}

void disable_raw_mode(){
    terminal.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}
void enable_raw_mode(){
    terminal = original;
    tcgetattr(STDIN_FILENO, &terminal);

    terminal.c_lflag &= ~(ICANON);
    terminal.c_lflag &= ~ECHO;
    terminal.c_cc[VMIN] = 1;
    terminal.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}



#include <settings.h>
#include <grid.h>

void getFileSettings(){
    FILE *settings;
    char caractere;
    int height,widht=0;
    settings= fopen("settings_grid.txt","rt");
    while((caractere = fgetc(settings)) != EOF){
        if(caractere == '\n'){
            height++;
            widht=0;
        }else{
            widht++;
        }
    }
    fclose(settings);

    Cell grid[widht][height];
}
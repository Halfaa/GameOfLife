#include <settings.h>
#include <grid.h>


int getFileSettings(Cell grid[MAX_HEIGHT][MAX_WIDTH]){
    FILE *settings;
    int height,widht=0;
    char *patern;
    settings= fopen("settings_grid.txt","rt");
    if(settings == NULL){
        printf("Problème avec l'ouverture du fichier");
        return EXIT_FAILURE;
    }
    if(widht == 0 && height == 0){
        getWidhtHeight(&height,&widht,settings);
        getPatern(settings,height,widht,&patern);
    }
    fclose(settings);
    
    printf("%c",patern[0]);
    for(int i =0;i<10;i++){
        printf("%c",patern[i]);     
    }

    //fill_grid(grid,height,widht,patern);

    return 0;
}


void getWidhtHeight(int *height,int *widht,FILE *settings){
    char buffer[255];
    char delimitateur[] = "=";
    bool largeur = false;

    while(fgets(buffer,sizeof buffer,settings) != NULL){
        char *field = strtok(buffer,delimitateur);
        while(field != NULL){
            if(strcmp(field,"Largeur")==0){
                largeur =true;
            }
            if(atoi(field) != 0 && largeur==true){
                *widht=(int)atoi(field);
                largeur=false;
            }
            if(atoi(field) != 0 && largeur==false){
                *height=(int)atoi(field);
                break;
            }
            field = strtok(NULL, delimitateur);
        }
        if(*height && *widht){
            break;
        }
    }
}

void getPatern(FILE *settings,int height,int widht,char *patern){
    char buffer[255];

    *patern=malloc((widht * height + 1) * sizeof(char));


    while(fgets(buffer,sizeof(buffer),settings) != NULL){
            printf("%s",buffer);
            strncat(patern,buffer,widht);
        }
}
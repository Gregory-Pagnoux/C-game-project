#include "map.h"

char winWord[10][62] = {{'#',' ',' ',' ',' ',' ','#',' ',' ','#','#','#',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ',' ','#','#','#','#'},
                        {'#','#',' ',' ',' ','#','#',' ','#','#','#','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#','#',' ',' ','#','#','#','#',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ','#','#',' ','#','#','#','#',' '},
                        {' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ','#',' ','#','#',' ',' ',' '},
                        {' ','#','#','#','#','#',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ','#','#',' ','#','#',' ',' ',' '},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#',' ',' ','#','#','#','#','#',' ',' ','#','#','#','#',' '},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#','#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','#','#',' ',' '},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ','#','#','#','#','#','#','#',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' '},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ',' '},
                        {' ',' ','#','#','#',' ',' ',' ','#','#','#','#','#',' ','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#','#',' ','#','#','#','#',' ','#','#','#','#','#','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#','#'},
                        {' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ','#','#','#','#',' ',' ',' ','#','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#','#','#',' '}};

char overWord[10][45] = {{'#',' ',' ',' ',' ',' ','#',' ',' ','#','#','#',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','#','#','#','#',' ','#','#','#','#',' ','#','#',' ',' '},
                        {'#','#',' ',' ',' ','#','#',' ','#','#','#','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#','#','#',' ','#','#','#','#',' ','#','#','#','#',' '},
                        {' ','#','#',' ','#','#',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ','#','#',' ','#','#'},
                        {' ','#','#','#','#','#',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ','#','#',' ',' ','#'},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#','#','#',' ','#','#',' ',' ','#'},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#','#',' ',' ','#','#',' ',' ','#'},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ',' ','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ','#','#',' ',' ','#'},
                        {' ',' ','#','#','#',' ',' ',' ','#','#',' ','#','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#','#',' ',' ','#','#',' ',' ',' ','#','#',' ','#','#'},
                        {' ',' ','#','#','#',' ',' ',' ','#','#','#','#','#',' ','#','#','#','#','#',' ',' ',' ',' ',' ','#','#','#','#',' ',' ','#','#','#','#',' ','#','#','#','#','#','#','#','#','#',' '},
                        {' ',' ',' ','#',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#','#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ','#','#','#','#','#','#',' ','#','#','#',' ',' ','#','#',' ',' '}};

void printWin() {
    for (int i=0; i < 10; i++){
        for (int j=0; j < 62; j++){
            printf("%c", winWord[i][j]);
        }
        printf("\n");
    }
    return;
}

void printOver() {
    for (int i=0; i < 10; i++){
        for (int j=0; j < 45; j++){
            printf("%c", overWord[i][j]);
        }
        printf("\n");
    }
    return;
}

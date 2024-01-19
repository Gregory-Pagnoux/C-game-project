#include "inventory.h"

//move the player on the next position
void playerPos(int x, int y){
    house[x][y] = '.';
    return;
}

int xKey;
int yKey;
void keyPos(){
    xKey = rand() % 13;
    yKey = rand() % 15;
    if (house[xKey][yKey] != 'C'){
        keyPos();
    }
    return;
}

item_t *item = NULL;

// colision with walls, door and and chests
int colision(int x, int y){
    int validation = 0;
    if(house[x][y]==' '){
        validation++;
    } else if(house[x][y]=='C') {
        if (x == xKey && y ==yKey){
            printf("\n\nYou found the key !\n");
            house[xKey][yKey] = ' ';
            addItem(item, "Key", 1, 1);
        } else {
            printf("\n\nThere is no Key here.\n");
        }
    } else if (house[x][y]=='/'){
        if (item != NULL){
            validation = 2;
        } else {
            printf("\n\nYou need a key to open this door.\n");
        }
    } else {
        printf("\n\nYou can't go there.\n");
    }
    return validation;
}

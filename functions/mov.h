#include "inventory.h"

//move the player on the next position
void playerPos(int x, int y){
    house[x][y] = '.';
    return;
}

int randomVal(int i){
    int r = rand() % i;
    return r;
}

int monstAttack; // variable for the attack of the monster
int attack; // variable for the attack of the player

int playerAttack(monstHP){
    attack = randomVal(8);
    monstHP = monstHP - attack;
    return monstHP;
}

int monsterAttack(int HP){
    monstAttack = randomVal(7);
    HP = HP - monstAttack;
    return HP;
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
int HP = 20; // HP of the player

// colision with walls, door and and chests
int colision(int x, int y){
    int validation = 0;
    if(house[x][y]==' '){
        validation++;
    } else if(house[x][y]=='S'){
        printf("\n\nYou found a spider !\n");
        int monstHP = randomVal(10);
        while (monstHP > 0 && HP > 0){
            printf("\n\nMonster HP: %d\n", monstHP);
            printf("Your HP: %d\n", HP);
            monstHP = playerAttack(monstHP);
            printf("\nYou attacked the spider !\n");
            HP = monsterAttack(HP);
            printf("The spider attacked you !\n");
            if (monstHP <= 0){
                printf("\n\nYou killed the spider !\n");
                house[x][y] = ' ';
            } else if (HP <= 0){
                system("clear");
                printOver();
                exit(0);
            }
        }
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
            printf("\n\nYou opened the door !\n");
            printWin();
            exit(0);
        } else {
            printf("\n\nYou need a key to open this door.\n");
        }
    } else {
        printf("\n\nYou can't go there.\n");
    }
    return validation;
}

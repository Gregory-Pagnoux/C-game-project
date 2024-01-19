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
    printf("monster lost %d HP\n", attack);
    return monstHP;
}

int monsterAttack(int HP){
    monstAttack = randomVal(7);
    HP = HP - monstAttack;
    printf("You lost %d HP\n", monstAttack);
    return HP;
}

item_t *item = NULL; // item pointer
int xKey;
int yKey;
void keyPos(){
    xKey = rand() % 13;
    yKey = rand() % 15;
    if (house[xKey][yKey] != 'C'){
        keyPos();
    } else {
        item = (item_t*)malloc(sizeof(item_t));
        strcpy(item->name, "Key");
        item->quantity = 1;
        item->solidity = 1;
    }
    return;
}

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
            printf("\nYou attacked the spider !\n");
            monstHP = playerAttack(monstHP);
            if (monstHP <= 0){
                printf("\n\nYou killed the spider !\n");
                house[x][y] = ' ';
            } else {
                printf("The spider attacked you !\n");
                HP = monsterAttack(HP);
                if (HP <= 0){
                    printOver();
                    exit(0);
                }
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
        if (item != NULL && strcmp(item->name, "Key") == 0){
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

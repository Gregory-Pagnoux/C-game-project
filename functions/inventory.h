#include "win_gameOver.h"

//structure of inventory
typedef struct item
{
    char name[30];
    int quantity;
    int solidity;
}item_t;

// function to add item to inventory
void addItem(item_t *item, char name[30], int quantity, int solidity){
    item = (item_t*)malloc(sizeof(item_t));
    strcpy(item->name, name);
    item->quantity = quantity;
    item->solidity = solidity;
    return;
}

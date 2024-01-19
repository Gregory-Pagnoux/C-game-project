#include <string.h>

//structure of inventory
typedef struct inventory
{
    char name[30];
    int quantity;
    int solidity;
}inventory_t;

// function to add item to inventory
void addItem(inventory_t *inventory, int *size, char *name, int quantity, int solidity)
{
    strcpy(inventory[*size].name, name);
    inventory[*size].quantity = quantity;
    inventory[*size].solidity = solidity;
    *size += 1;
}

// function to remove item from inventory
void removeItem(inventory_t *inventory, int *size, char *name)
{
    int i;
    for(i = 0; i < *size; i++)
    {
        if(strcmp(inventory[i].name, name) == 0)
        {
            inventory[i] = inventory[*size - 1];
            *size -= 1;
            break;
        }
    }
}

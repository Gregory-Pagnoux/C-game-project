#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../functions/map.h"
#include "../functions/inventory.h"
#include "../functions/mov.h"
#include "../functions/win.h"

int main()
{
    char choice; // variable for the decision of the player
    char name[50]; // variable for the name of the player
    int win = 0; // variable for the win condition
    int x = 11; // variable for the position x of the player
    int y = 7;  // variable for the position y of the player

    keyPos(); // random position of the key

    printf("\nWelcome my friend !\n");
    printf("I hope you're well.\n");
    printf("Welcome in Escape House.");
    printf("\n\nWhat's your name ?\n\n");
    scanf("%c", name);

    printf("\nYour are a child in a haunted house.\nYou have to escape with a key, but you need to find the key in different chests.\n");

    while(win != 1){

        playerPos(x,y);
        printHouse();

        printf("\n\nYou can :\n");
        printf("1. go to\n");
        printf("2. back off\n");
        printf("3. go to the left\n");
        printf("4. go to the right\n");
        printf("(tap your number choice)\n\n");
        scanf("%s", &choice);

        system("clear");

        switch (choice){
            case '1': // move forward
                house[x][y] = ' '; // delete the previous position of the player on the map
                if (colision(x-1,y) == 1){
                    x--;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
            case '2': // move backward
                house[x][y] = ' ';
                if (colision(x+1,y) == 1){
                    x++;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
            case '3': // move left
                house[x][y] = ' ';
                if (colision(x,y-1) == 1){
                    y--;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
            case '4': // move right
                house[x][y] = ' ';
                if (colision(x,y+1) == 1){
                    y++;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
        }
    }
}

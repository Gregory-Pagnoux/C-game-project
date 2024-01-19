#include "../functions/mov.h"

int main()
{
    char choice; // variable for the decision of the player
    char name[50]; // variable for the name of the player
    int x = 11; // variable for the position x of the player
    int y = 7;  // variable for the position y of the player
    int win = 0; // variable for the win condition
    int z;

    keyPos(); // random position of the key

    system("clear");

    printf("\nWelcome my friend !\n");
    printf("I hope you're well.\n");
    printf("Welcome in \033[1;31mEscape House\033[1;0m.");
    printf("\n\nWhat's your name ?\n\n");
    scanf("%c", name);

    printf("\nYour are a child in a haunted house.\nYou have to escape with a key, but you need to find the key in different chests.\n");

    while(win != 1){

        playerPos(x,y);
        printHouse();

        printf("\n\nYou can :\n");
        printf("\033[1;32m1\033[1;0m. go \033[1;32mforward\033[1;0m\n");
        printf("\033[1;34m2\033[1;0m. \033[1;34mback off\033[1;0m\n");
        printf("\033[1;35m3\033[1;0m. go to the \033[1;35mleft\033[1;0m\n");
        printf("\033[1;36m4\033[1;0m. go to the \033[1;36mright\033[1;0m\n");
        printf("(tap your number choice)\n\n");
        scanf("%s", &choice);

        system("clear");

        switch (choice){
            case '1': // move forward
                house[x][y] = ' '; // delete the previous position of the player on the map
                z = colision(x-1,y); // check if the next position is a wall or a chest
                if (z == 1){
                    x--;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
            case '2': // move backward
                house[x][y] = ' ';
                z = colision(x+1,y);
                if (z == 1){
                    x++;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
            case '3': // move left
                house[x][y] = ' ';
                z = colision(x,y-1);
                if (z == 1){
                    y--;
                    playerPos(x,y);
                    break;
                } else {
                    playerPos(x,y);
                    break;
                }
            case '4': // move right
                house[x][y] = ' ';
                z = colision(x,y+1);
                if (z == 1){
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

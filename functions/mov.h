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

// colision with walls, door and and chests
int colision(int x, int y){
    int validation = 0;
    if(house[x][y]==' '){
        validation++;
    } else if(house[x][y]=='C') {
        if (house[x][y]==house[xKey][yKey]){
            printf("\n\nYou found the key !\n");
            house[xKey][yKey] = ' ';
            addItem(1, 1, 'key', 1, 1);
        } else {
            printf("\n\nthere is no Key here\n");
            house[xKey][yKey] = ' ';
        }
    } //else if (house[x][y]=='/'){
        //if (winCondition(x, y) == 1){
            //win = 1;
            //validation++;
            //removeItem(1, 1, 'key');
        //} else {
            //printf("\n\nYou need a key to open this door\n");
        //}
    //}
    return validation;
}

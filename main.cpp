#include <bits/stdc++.h>
using namespace std;

// spaces is a char array to keep track of all markers.
void drawBoard(char *spaces){
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] <<"  |  " << spaces[1] <<"  |  " << spaces[2] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] <<"  |  " << spaces[4] <<"  |  " << spaces[5] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] <<"  |  " << spaces[7] <<"  |  " << spaces[8] <<"  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void playerMove(char *spaces, char player){
    int position;
    do{
        cout << "enter a position (1,8): ";
        cin >> position;
        position--;
        
        if(spaces[position] == ' '){
            spaces[position] = player;
            break;
        }
    }while(!position > 0 || !position < 8);
}

void compMove(char *spaces,char computer){
    int position;
    // seeding random number 
    srand(time(0));
    
    while(true){
        position = rand() % 9;
        if(spaces[position] == ' '){
            spaces[position] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces,char player, char computer){
    // checking winning conditions
    if(spaces[0]!= ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[3]!= ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[6]!= ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[0]!= ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[1]!= ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[2]!= ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[0]!= ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else if(spaces[2]!= ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "YOU WON\n" : cout << "YOU LOSE\n";
    }else{
        return false;
    }
    return true;
}

bool checkTie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT'S A TIE" << endl;
    return true;
}

int main() {
    
    // character array to keep track of all the positions
    char spaces[9] = {' ',' ',' ',' ',' ',' ', ' ', ' ',' '};
    // player symbol 
    char player = 'x';
    // computer symbol 
    char computer = 'o';
    bool running = true;
    // drawing empty board initially 
    drawBoard(spaces);
    
    while(running){
        playerMove(spaces,player);
        drawBoard(spaces);
        if(checkWinner(spaces,player,computer)){
            running = false;
            break;
        }else if(checkTie(spaces)){
            running = false;
            break;
        }
        
        compMove(spaces,computer);
        drawBoard(spaces);
        if(checkWinner(spaces,player,computer)){
            running = false;
            break;
        }else if(checkTie(spaces)){
            running = false;
            break;
        }
        
    }
    
    cout << "THANKS FOR PLAYING" << endl;

}

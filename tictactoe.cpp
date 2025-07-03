#include <iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char markerP1, markerP2;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard(){
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
    cout<<"---|---|---"<<endl;
}

bool placeMarker(int slot){
    int row = (slot-1)/3;
    int col = (slot-1)%3;

    if(board[row][col]!='X' && board[row][col]!='O'){
        board[row][col] = currentMarker;
        return true;
    }
     return false;
}

 bool winner(){
        for(int i=0; i<3; i++){
            if(board[i][0]== board[i][1]==board[i][2]){
                return true;
            }
        }

        for(int i=0; i<3; i++){
            if(board[0][i]== board[1][i]==board[2][i]){
                return true;
            }
        }

        if(board[0][0]== board[1][1] && board[1][1]== board[2][2]){
            return true;
        }

        if(board[0][2]== board[1][1] && board[1][1]== board[2][0]){
            return true;
        }

        return false;
    }

void swapPlayerandMarker() {
    if (currentPlayer == 1) {
        currentMarker = markerP2;
        currentPlayer = 2;
    } else {
        currentMarker = markerP1;
        currentPlayer = 1;
    }
}

void game(){
    cout<<"Player 1 choose your marker: X or O"<<endl;
    cin>>markerP1;

    markerP2 = (markerP1 == 'X') ? 'O' : 'X';

    currentPlayer = 1;
    currentMarker = markerP1;

    drawBoard();

    int playerWon;

    for(int i=0; i<9; i++){
        cout<<"Player-"<<currentPlayer<<"'s turn. Enter the Slot:"<<endl;
        int slot;
        cin>>slot;

        if(slot<1 || slot>9){
            cout<<"Invalid slot, Please try again"<<endl;
            i--;
            continue;
        }

        if(!placeMarker(slot)){
            cout<<"Slot is occupied, Please try again:"<<endl;
            i--;
            continue;
        }

        drawBoard();
        
        if (winner()) {
            cout << "Player " << currentPlayer << " wins!"<<endl;
            return; 
        }

        swapPlayerandMarker();
    }
     cout<<"It's a tie"<<endl;
}
int main(){
    game();
    return 0;
}









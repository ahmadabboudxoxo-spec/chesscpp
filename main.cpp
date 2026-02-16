#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to set the console text color using ANSI escape
// 34	Blue, 31	Red, 37	White
void SetColor(int textColor){
    cout << "\033[" << textColor << "m";
}

// Function to reset the console color
void ResetColor() { cout << "\033[0m"; }

struct piece{
    string name = "none";
    string color = "n";
};
piece square[8][8];


void start(piece square[8][8]){
    //board setup
    //blacks ... reds
    square[0][0].name = "rook";
    square[0][0].color = "b";

    square[1][0].name = "knight";
    square[1][0].color = "b";

    square[4][4].name = "bishop";
    square[4][4].color = "b";

    square[3][0].name = "king";
    square[3][0].color = "b";

    square[4][0].name = "queen";
    square[4][0].color = "b";

    square[7][0].name = "rook";
    square[7][0].color = "b";

    square[6][0].name = "knight";
    square[6][0].color = "b";

    square[5][0].name = "bishop";
    square[5][0].color = "b";

    for (int i=0;i<=7;i++){
        square[i][1].name = "pawn";
        square[i][1].color = "b";
    }

    //whites ... blues
    square[0][7].name = "rook";
    square[0][7].color = "w";

    square[1][7].name = "knight";
    square[1][7].color = "w";

    square[2][7].name = "bishop";
    square[2][7].color = "w";

    square[3][7].name = "king";
    square[3][7].color = "w";

    square[4][7].name = "queen";
    square[4][7].color = "w";

    square[7][7].name = "rook";
    square[7][7].color = "w";

    square[6][7].name = "knight";
    square[6][7].color = "w";

    square[5][7].name = "bishop";
    square[5][7].color = "w";

    for (int i=0;i<=7;i++){
        square[i][6].name = "pawn";
        square[i][6].color = "w";
    }
}

void refresh(piece square[8][8]){
    for (int y=0;y<=7;y++){
        for (int x=0;x<=7;x++){
            if (square[x][y].name == "rook"){
                if (square[x][y].color == "w"){
                    SetColor(34);
                }
                else{
                    SetColor(31);
                }
                cout<<"r ";
            }
            else if (square[x][y].name == "knight"){
                if (square[x][y].color == "w"){
                    SetColor(34);
                }
                else {
                    SetColor(31);
                }
                cout<<"n ";
            }
            else if (square[x][y].name == "bishop"){
                if (square[x][y].color == "w"){
                    SetColor(34);
                }
                else {
                    SetColor(31);
                }
                cout<<"b ";
            }
            else if (square[x][y].name == "queen"){
                if (square[x][y].color == "w"){
                    SetColor(34);
                }
                else {
                    SetColor(31);
                }
                cout<<"q ";
            }
            else if (square[x][y].name == "king"){
                if (square[x][y].color == "w"){
                    SetColor(34);
                }
                else {
                    SetColor(31);
                }
                cout<<"h ";
            }
            else if (square[x][y].name == "pawn"){
                if (square[x][y].color == "w"){
                    SetColor(34);
                }
                else {
                    SetColor(31);
                }
                cout<<"p ";
            }
            else{
                SetColor(37);
                cout<<"* ";
            }
        }
        cout<<endl;
    }

}

int up(int pos, piece square[8][8]){
    int x = floor(pos / 10); //x
    int y = pos - (x * 10); //y
    string c = square[x][y].color; //color
    for (int i=y-1;i>=0;i--){
        if (square[x][i].color != "n"){
            if (square[x][i].color == c){
                return i+1;

           }
            else{
                return i;
            }
        }
    }
    return 0;
}

int down(int pos, piece square[8][8]){
    int x = floor(pos / 10); //x
    int y = pos - (x * 10); //y
    string c = square[x][y].color; //color
    for (int i=y+1;i<=7;i++){
        if (square[x][i].color != "n"){
            if (square[x][i].color == c){
                return i-1;

           }
            else{
                return i;
            }
        }
    }
    return 7;
}

int left(int pos, piece square[8][8]){
    int x = floor(pos / 10); //x
    int y = pos - (x * 10); //y
    string c = square[x][y].color; //color
    for (int i=x-1;i>=0;i--){
        if (square[i][y].color != "n"){
            if (square[i][y].color == c){
                return i+1;

           }
            else{
                return i;
            }
        }
    }
    return 0;
}

int right(int pos, piece square[8][8]){
    int x = floor(pos / 10); //x
    int y = pos - (x * 10); //y
    string c = square[x][y].color; //color
    for (int i=x+1;i<=7;i++){
        if (square[i][y].color != "n"){
            if (square[i][y].color == c){
                return i-1;

           }
            else{
                return i;
            }
        }
    }
    return 7;
}

string knightmove(int pos, int pos2, piece square[8][8]){
    //pos1
    int x = floor(pos / 10); //x
    int y = pos - (x * 10); //y
    string c = square[x][y].color; //color
    //pos2
    int x2 = floor(pos2 / 10); //x
    int y2 = pos2 - (x2 * 10); //y
    if (x2>=0 && x2<=7 && y2>=0 && y2<=7){
        //distance
        int dx = x - x2;
        int dy = y - y2;
        if (dx == 2){
            if (dy == -1 || dy == 1){
                if (square[x2][y2].color != c){
                    string r = square[x2][y2].color;
                    return r;
                }
                else{
                    string r = "x";
                    return r;
                }
            }
        }
        else if (dx == 1){
            if (dy == -2 || dy == 2){
                if (square[x2][y2].color != c){
                    string r = square[x2][y2].color;
                    return r;
                }
                else{
                    string r = "x";
                    return r;
                }
            }
        }
        else if (dx == -1){
            if (dy == -2 || dy == 2){
                if (square[x2][y2].color != c){
                    string r = square[x2][y2].color;
                    return r;
                }
                else{
                    string r = "x";
                    return r;
                }
            }
        }
        else if (dx == -2){
            if (dy == -1 || dy == 1){
                if (square[x2][y2].color != c){
                    string r = square[x2][y2].color;
                    return r;
                }
                else{
                    string r = "x";
                    return r;
                }
            }
        }
        else {
            string r = "x";
            return r;
        }
    }
    else{
        string r = "x";
        return r;
    }
}

int rook(int pos, int pos2, piece square[8][8]){
    //pos1
    int x = floor(pos / 10); //x
    int y = pos - (x * 10); //y
    string c = square[x][y].color; //color
    //checking existing rook
    if (square[x][y].name == "rook"){
        //pos2
        int x2 = floor(pos2 / 10); //x
        int y2 = pos2 - (x2 * 10); //y
        cout << x << " " << y << " " << x2 << " " << y2;
        //1. moving left - right 2.moving up-down 3.wrong input
        if (x != x2 && y == y2){
            int xmax = right(pos, square);
            int xmin = left(pos, square);

            if (x2 >= xmin && x2 <= xmax){
                square[x2][y2].name = "rook";
                square[x2][y2].color = c;
                square[x][y].name = "none";
                square[x][y].color = "n";
                return 0;
            }
            else{return 1;}
        }
        else if (x == x2 && y != y2){
            int xmax = down(pos, square);
            int xmin = up(pos, square);
            cout << xmax;
            if (y2 >= xmin && y2 <= xmax){
                square[x2][y2].name = "rook";
                square[x2][y2].color = c;
                square[x][y].name = "none";
                square[x][y].color = "n";
                return 0;
            }
            else{return 1;}
        }
        else{return 1;}
    }
    else{return 1;}
}


int main(){
    start(square);
    refresh(square);
    int n = 44;
    int k;
    while (1==1){
        k = n;
        cin>>n;
        bishop(k, n, square);
        refresh(square);
    }
    return 0;
}

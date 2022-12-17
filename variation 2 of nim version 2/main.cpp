#include <iostream>

#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define N_COINS 12
#define HUMAN 1
#define COMPUTER 0

using namespace std;

// Declare whose turn
int whoseTurn = 0;

// Declare Row pile and coin number for each row
int rowOne = 3;
int rowTwo = 4;
int rowThree = 5;
int nCoins = N_COINS;


bool isBadPosition(int nCoins);

int findGoodMove(int nCoins, int row) {
    for (int n = 1; n <= row; n++)
        if (isBadPosition(nCoins - n))
            return n;
    return NO_GOOD_MOVE;
}

bool isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return
            findGoodMove(nCoins, MAX_MOVE) == NO_GOOD_MOVE;
}
// Check if the number of coins is enough for the player to take from each row
void isEnough(int nrow, int n){
    if (nrow == 1){
        while (n > rowOne){
            cout << "Not enough coins in this row, please pick again" << endl;
            if (whoseTurn == 0){
                cout << "Computer plays: ";
                n = findGoodMove(nCoins, rowOne);
                cout << "Computer takes " << n << " coins.\n" ;
                cout << "from row 1" << endl;
            }
            else{
                cout << "Human plays: ";
                cin >> n;
            }

        }
        rowOne -= n;
    }
    else if (nrow == 2){
        while (n > rowTwo){
            cout << "Not enough coins in this row, please pick again" << endl;
            if (whoseTurn == 0){
                cout << "Computer plays: ";
                n = findGoodMove(nCoins, rowTwo);
                cout << "Computer takes " << n << " coins.\n" ;
                cout << "from row 2" << endl;
            }
            else{
                cout << "Human plays: ";
                cin >> n;
            }

        }
        rowTwo -= n;
    }
    else if (nrow == 3){
        while (n > rowThree){
            cout << "Not enough coins in this row, please pick again" << endl;
            if (whoseTurn == 0){
                cout << "Computer plays: ";
                n = findGoodMove(rowThree, rowThree);
                cout << "Computer takes " << n << " coins.\n" ;
                cout << "from row 3" << endl;
            }
            else{
                cout << "Human plays: ";
                cin >> n;
            }

        }
        rowThree -= n;
    }
}

int randomRow(){
    if(rowOne != 0 && rowTwo != 0 && rowThree != 0){
        return rand() % 3 + 1;
    }
    else if(rowOne == 0 && rowTwo != 0 && rowThree != 0){
        return rand() % 2 + 2;
    }
    else if(rowOne != 0 && rowTwo == 0 && rowThree != 0){
        int temp = rand() % 2 + 1;
        if(temp == 2){
            return 3;
        }
        else{
            return 1;
        }
    }
    else if(rowOne != 0 && rowTwo != 0 && rowThree == 0){
        int temp = rand() % 2 + 1;
        if(temp == 2){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(rowOne == 0 && rowTwo == 0 && rowThree != 0){
        return 3;
    }
    else if(rowOne == 0 && rowTwo != 0 && rowThree == 0){
        return 2;
    }
    else if(rowOne != 0 && rowTwo == 0 && rowThree == 0){
        return 1;
    }
    else{
        return 0;
    }
}



int main() {
    int nRow;
    int nCoins = rowOne + rowTwo + rowThree, n;
    int whoseTurn = HUMAN;
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (nCoins > 1) {
        cout << "\nWe have " << nCoins << ".\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
            case HUMAN:
                n = nCoins + 10;
                while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: " << endl;
                    cout << "row 1 has " << rowOne << " coins" << endl;
                    cout << "row 2 has " << rowTwo << " coins" << endl;
                    cout << "row 3 has " << rowThree << " coins" << endl;
                    cin >> n;
                    cout << "pick Row" << endl;
                    cin >> nRow;
                    isEnough(nRow, n);
                }
                break;
            case COMPUTER:
//                n = findGoodMove(nCoins, MAX_MOVE);
//                if (!n)
//                    n = 1;
            if (findGoodMove(nCoins, MAX_MOVE) == NO_GOOD_MOVE){
                n = 1;
            }
            else {
                n = findGoodMove(nCoins, MAX_MOVE);
            }
                nRow = randomRow();
                isEnough(nRow, n);
                cout << "Computer takes " << n << " coins.\n" ;
                cout << "from row " << nRow << endl;
        }
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");
}

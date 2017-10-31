//---------------------------------------
//  Jeffrey Lamothe
//  Chess Game
//  February 2016
//---------------------------------------

#include "chess_pieces.h"
#include "Board.h"
#include "main_variables.h"
using namespace std;

void gameStarter();
void welcomeScreen();
void gameLoop();

int main() {
    gameStarter(); //accepts player names
    welcomeScreen(); //prints initial board
    gameLoop(); //executes main game 
}

void gameStarter(){
    //Game Start
    cout << "♟♞♝♜♛♚ Welcome to my 2 player chess game: FireChess! ♔♕♖♗♘♙" << endl;
    while(!nameCorrect1)
    {
        cout << "\nEnter the name of Player 1: ";
        cin >> p1;
        if (p1.length() < 9)
        {
            nameCorrect1 = true;
        }
        else
        {
            cout << "Please enter a name under 9 characters.\n";
            nameCorrect1 = false;
        }
    }
    cout << p1 << " will be the black pieces!\n";
    if (!(p1.length() == 10))
    {
        int spaces = 10 - p1.length();
        int before = spaces / 2;
        for (int k = 0; k < before; k++)
        {
            if (k == 0)
            {
                modp1 = " " + p1;
            }
            else
            {
                modp1 = " " + modp1;
            }
        }
        for (int i = modp1.length(); i < 10; i++)
        {
            modp1 += " ";
        }
    }
    while(!nameCorrect2)
    {
        cout << "\nEnter the name of Player 2: ";
        cin >> p2;
        if (p2.length() < 9)
        {
            nameCorrect2 = true;
        }
        else
        {
            cout << "Please enter a name under 9 characters.\n";
            nameCorrect2 = false;
        }
    }
    cout << p2 << " will be the white pieces!\n";
    if (!(p2.length() == 10))
    {
        int spaces = 10 - p2.length();
        int before = spaces / 2;
        for (int k = 0; k < before; k++)
        {
            if (k == 0)
            {
                modp2 = " " + p2;
            }
            else
            {
                modp2 = " " + modp2;
            }
        }
        for (int i = modp2.length(); i < 10; i++)
        {
            modp2 += " ";
        }
    }

}
void welcomeScreen(){
    cout << "\nLoading my chess game!!!" << endl;
    //Prints the board with each piece at its starting point
    cout << endl << "  =========== " << modp1 << " ==========  " << endl;
    board->printBoard();
    cout << "  =========== " << modp2 << " ==========  " << endl;
    cout << "\t";
    for(int i = 0; i<8; i ++){
        if (i==0)
            cout << i;
        else
            cout << "\t"<< i;
    }
    cout << "\n";
}
void gameLoop(){
    //The game loop
    while(!GameOver)
    {
        if (first != 0)
        {
            cout << string( 80, '\n' );
            cout << endl << "  =========== " << modp1 << " ===========  " <<endl;
            board->printBoard();
            board->CheckForCheck();
            cout << "  ========== " << modp2 << " ===========  " <<endl;
            cout << "\t";
            for(int i = 0; i<8; i ++){
                if (i==0)
                    cout << i;
                else
                    cout << "\t"<< i;
            }
            cout << "\n";
        }
        first++;
        cout << "\n";
        cout << p1 << " has captured " << board->GetPiecesCaptured2() << " pieces: ";
        for (int i = 0; i < 16; i++)
        {
            cout << p2Captured[i] << " ";
        }
        cout << endl;
        cout << "\n";
        cout << p2 << " has captured " << board->GetPiecesCaptured1() << " pieces: ";
        cout << "\n";
        for (int i = 0; i < 16; i++)
        {
            cout << p1Captured[i] << " ";
        }
        cout << endl;
        if(board->GetisCheckPlayer1())
        {
            if(board->isCheckMate(1))
            {
                cout << "Check Mate! " << p2 << " wins!" << endl;
                exit(0);
            }
            cout << p1 <<" is in check!" << endl;
        }
        else if(board->GetisCheckPlayer2())
        {
            if(board->isCheckMate(2))
            {
                cout << "Check Mate! "<< p1 << " wins!" << endl;
                exit(0);
            }
            cout << p2 <<" is in check!" << endl;
        }
        if (whichPlayersTurn == 1)
        {
            cout << "It's " << p1 << "'s turn!" << endl;
        }
        else if (whichPlayersTurn == 2)
        {
            cout << "It's " << p2 << "'s turn!" << endl;
        }
        cout << "Select a piece to move!\n" << endl;
        cout << "Enter the x-coordinate: ";
        cin >> x;
        cout << "Enter the y-coordinate: ";
        cin >> y;

        if(!isOutOfBounds(x,y))
        {
            if(whichPlayersTurn == board->CheckPlayer(x,y))
            {
                board->CheckPossibleMoves(x,y);
                cout << "Where would you like to move!" << endl;
                cout << "Enter the new x-coordinate: ";
                cin >> newX;
                cout << "Enter the new y-coordinate: ";
                cin >> newY;
                if(!isOutOfBounds(newX,newY))
                {
                    if(board->isCheckTempMove(x,y,newX,newY) == 0)
                    {
                        if(board->CheckSpotMove(x,y,newX,newY))
                        {
                            if(whichPlayersTurn == 1) whichPlayersTurn = 2;
                            else whichPlayersTurn = 1;
                        }
                    }
                    else if(board->isCheckTempMove(x,y,newX,newY) == 1)
                    {
                        cout << p1 << " is still in check with that move!" << endl;
                    }
                    else if(board->isCheckTempMove(x,y,newX,newY) == 2)
                    {
                        cout << p2 << " is still in check with that move!" << endl;
                    }
                }
            }
        }
    }
}

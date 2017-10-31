//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include "piece_variables.h"
#include "Move.h"

class Piece {
private:
    int xLocation;
    int yLocation;
    int player;
    string type;
    //A vector holding each pieces possible moves
    vector<Move> possibleMoves;
    //An iterator that goes through each possibleMove
    vector<Move>::iterator iter;
public:
    //Constructors
    Piece(int x, int y, int p,string t);
    Piece();

    //Getters and Setters
    void SetPlayer(int p);
    void SetLocation(int x, int y);
    void SetPiece(int x,int y,int p);
    int GetXLocation();
    int GetYLocation();
    int GetPlayer();
    string GetType();

    //Creates a new move with x and y location and adds a move object to the possibleMoves vector
    void AddMove(int x, int y);
    void AddCaptureMove(int x, int y);

    //Clears all possibleMoves
    void ClearMoves();

    //Iterates through the possibleMoves vector to see if a move with a certain x and y value is contained with the vector
    bool moveIsFound(int x, int y);

    //Prints all possibleMoves
    void PrintPossibleMoves();

    //Takes in a move and checks if that move is contained within the possibleMoves list
    bool isValidMove(Move move);
    int GetPossibleMoveSize();
    Move GetPossibleMoveAt(int i);

    //Checks if a spot is a different player
    bool isOpposingPlayer(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if the location is NULL
    bool isNull(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH straight down is NULL
    bool isNullStraightDown (int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH straight up is NULL
    bool isNullStraightUp (int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH straight right is NULL
    bool isNullStraightRight(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH straight left is NULL
    bool isNullStraightLeft(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH diagonal, up, and right is NULL
    bool isNullDiagonalUpRight(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH diagonal, down, and right is NULL
    bool isNullDiagonalDownRight(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH diagonal, up, and left is NULL
    bool isNullDiagonalUpLeft(int x, int y, Piece* board[8][8]);

    //Takes in an x and y coordinate along with the board to see if a PATH diagonal, down, and left is NULL
    bool isNullDiagonalDownLeft(int x, int y, Piece* board[8][8]);

    virtual void CalculatePossibleMoves() {};
    virtual ~Piece(){ };
};

Piece::Piece(int x, int y, int p,string t) {
    xLocation = x;
    yLocation = y;
    player = p;
    type = t;
};
Piece::Piece() {
    xLocation = 0;
    yLocation = 0;
    player = 0;
    type = "NULL";
};
void Piece::SetPlayer(int p) {
    player = p;
};
void Piece::SetLocation(int x, int y) {
    xLocation = x;
    yLocation = y;
};
void Piece::SetPiece(int x,int y,int p) {
    xLocation = x;
    yLocation = y;
    player = p;
};
int Piece::GetXLocation() {
    return xLocation;
};

int Piece::GetYLocation() {
    return yLocation;
};

int Piece::GetPlayer() {
    return player;
};

string Piece::GetType() {
    return type;
};

//Creates a new move with x and y location and adds a move object to the possibleMoves vector
void Piece::AddMove(int x, int y) {
    if(!moveIsFound(x,y))
    {
        Move m(x,y,false);
        possibleMoves.push_back(m);
    }
};

void Piece::AddCaptureMove(int x, int y) {
    if(!moveIsFound(x,y))
    {
        Move m(x,y,true);
        possibleMoves.push_back(m);
    }
};


//Clears all possibleMoves
void Piece::ClearMoves() {
    possibleMoves.clear();
};

//Iterates through the possibleMoves vector to see if a move with a certain x and y value is contained with the vector
bool Piece::moveIsFound(int x, int y) {
    for(iter = possibleMoves.begin();iter!=possibleMoves.end();iter++)
    {
        Move m = *iter;
        if(x == m.GetX() && y == m.GetY()) return true;
    }
    return false;
};

//Prints all possibleMoves
void Piece::PrintPossibleMoves() {
    for(iter = possibleMoves.begin();iter!=possibleMoves.end();iter++)
    {
        Move m = *iter;
        if(m.GetDoesCapture())
        {
            cout << "Capture: ";
        }
        cout << "(" << m.GetX() << "," << m.GetY() << ")" << " , ";
    }
};

//Takes in a move and checks if that move is contained within the possibleMoves list
bool Piece::isValidMove(Move move) {
    int x = move.GetX();
    int y = move.GetY();
    for(iter = possibleMoves.begin();iter!=possibleMoves.end();iter++) {
        Move currentMove = *iter;
        int possibleX  = currentMove.GetX();
        int possibleY = currentMove.GetY();
        if(x == possibleX && y == possibleY) return true;
    }
    return false;
};

int Piece::GetPossibleMoveSize() {
    return possibleMoves.size();
};
Move Piece::GetPossibleMoveAt(int i) {
    return possibleMoves[i];
};

//Checks if a spot is a different player
bool Piece::isOpposingPlayer(int x, int y, Piece* board[8][8])
{
    if(!isNull(x,y,board))
    {
        if(!isOutOfBounds(x,y))
        {
            if(board[y][x]->GetPlayer() != player)
            {
                return true;
            }
        }
    }
    return false;
};
//Takes in an x and y coordinate along with the board to see if the location is NULL
bool Piece::isNull(int x, int y, Piece* board[8][8]) {
    if(board[y][x] == NULL) return true;
    else return false;
};

//Takes in an x and y coordinate along with the board to see if a PATH straight down is NULL
bool Piece::isNullStraightDown (int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i = yLocation+1;i<=y;i++)
    {
        if(!isNull(x,i,board))
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(x,i,board))
                {
                    AddCaptureMove(x,i);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH straight up is NULL
bool Piece::isNullStraightUp (int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i = yLocation-1;i>=y;i--)
    {
        if(!isNull(x,i,board))
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(x,i,board))
                {
                    AddCaptureMove(x,i);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH straight right is NULL
bool Piece::isNullStraightRight(int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i=xLocation+1;i<=x;i++)
    {
        if(isNull(i,y,board) == false)
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(i,y,board))
                {
                    AddCaptureMove(i,y);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH straight left is NULL
bool Piece::isNullStraightLeft(int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i=xLocation-1;i>=x;i--)
    {
        if(isNull(i,y,board) == false)
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(i,y,board))
                {
                    AddCaptureMove(i,y);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH diagonal, up, and right is NULL
bool Piece::isNullDiagonalUpRight(int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i=xLocation+1,j=yLocation-1;i<=x;i++,j--)
    {
        if(isNull(i,j,board) == false)
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(i,j,board))
                {
                    AddCaptureMove(i,j);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH diagonal, down, and right is NULL
bool Piece::isNullDiagonalDownRight(int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i=xLocation+1,j=yLocation+1;i<=x;i++,j++)
    {
        if(isNull(i,j,board) == false)
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(i,j,board))
                {
                    AddCaptureMove(i,j);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH diagonal, up, and left is NULL
bool Piece::isNullDiagonalUpLeft(int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i=xLocation-1,j=yLocation-1;i>=x;i--,j--)
    {
        if(isNull(i,j,board) == false)
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(i,j,board))
                {
                    AddCaptureMove(i,j);
                }
            }
        }
    }
    return isNul;
};

//Takes in an x and y coordinate along with the board to see if a PATH diagonal, down, and left is NULL
bool Piece::isNullDiagonalDownLeft(int x, int y, Piece* board[8][8]) {
    bool isNul = true;
    bool foundFirstCollision = false;
    for(int i=xLocation-1,j=yLocation+1;i>=x;i--,j++)
    {
        if(isNull(i,j,board) == false)
        {
            isNul = false;
        }
        if(!isNul)
        {
            if(!foundFirstCollision)
            {
                foundFirstCollision = true;
                if(isOpposingPlayer(i,j,board))
                {
                    AddCaptureMove(i,j);
                }
            }
        }
    }
    return isNul;
};


#endif //CHESS_PIECE_H

//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "piece_variables.h"
#include "Piece.h"
class King: public Piece {
public:
    //Constructor for the King
    King(int x,int y, int p, string t)
            : Piece(x,y,p,t) {
    }
    //Calculates all possible moves for the King
    void CalculatePossibleMoves(Piece* board[8][8]) {
        int x = GetXLocation();
        int y = GetYLocation();

        //Up right diagonal
        if(isNull(x+1,y-1,board) && x+1<8 && y-1>-1)
        {
            AddMove(x+1,y-1);
        }
        else if(isOpposingPlayer(x+1,y-1,board) && !isOutOfBounds(x+1,y-1))
        {
            AddCaptureMove(x+1,y-1);
        }

        //Down right diagonal
        if(isNull(x+1,y+1,board) && x+1<8 && y+1<8)
        {
            AddMove(x+1,y+1);
        }
        else if(isOpposingPlayer(x+1,y+1,board) && !isOutOfBounds(x+1,y+1))
        {
            AddCaptureMove(x+1,y+1);
        }

        //Down left diagonal
        if(isNull(x-1,y+1,board) && x-1>-1 && y+1<8)
        {
            AddMove(x-1,y+1);
        }
        else if(isOpposingPlayer(x-1,y+1,board) && !isOutOfBounds(x-1,y+1))
        {
            AddCaptureMove(x-1,y+1);
        }
        //Up left diagonal
        if(isNull(x-1,y-1,board) && x-1>-1 && y-1>-1)
        {
            AddMove(x-1,y-1);
        }
        else if(isOpposingPlayer(x-1,y-1,board) && !isOutOfBounds(x-1,y-1))
        {
            AddCaptureMove(x-1,y-1);
        }
        //Up
        if(isNull(x,y-1,board) && y-1>-1)
        {
            AddMove(x,y-1);
        }
        else if(isOpposingPlayer(x,y-1,board) && !isOutOfBounds(x,y-1))
        {
            AddCaptureMove(x,y-1);
        }
        //Right
        if(isNull(x+1,y,board) && x+1<8)
        {
            AddMove(x+1,y);
        }
        else if(isOpposingPlayer(x+1,y,board) && !isOutOfBounds(x+1,y))
        {
            AddCaptureMove(x+1,y);
        }
        //Down
        if(isNull(x,y+1,board) && y+1<8)
        {
            AddMove(x,y+1);
        }
        else if(isOpposingPlayer(x,y+1,board) && !isOutOfBounds(x,y+1))
        {
            AddCaptureMove(x,y+1);
        }
        //Left
        if(isNull(x-1,y,board) && x-1>-1)
        {
            AddMove(x-1,y);
        }
        else if(isOpposingPlayer(x-1,y,board) && !isOutOfBounds(x-1,y))
        {
            AddCaptureMove(x-1,y);
        }
    }
};
#endif //CHESS_KING_H

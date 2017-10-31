//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "piece_variables.h"
#include "Piece.h"
class Knight: public Piece {
public:
    //Constructor for the Knight
    Knight(int x,int y, int p, string t)
            : Piece(x,y,p,t) {
    }
    //Calculates all possible moves for the knight
    void CalculatePossibleMoves(Piece* board[8][8]) {
        int x = GetXLocation();
        int y = GetYLocation();
        int p = GetPlayer();
        //2 up 1 right
        if(isNull(x+1,y-2,board) && !isOutOfBounds(x+1,y-2))
        {
            AddMove(x+1,y-2);
        }
        else if(isOpposingPlayer(x+1,y-2,board) && !isOutOfBounds(x+1,y-2))
        {
            AddCaptureMove(x+1,y-2);
        }

        //1 up 2 right
        if(isNull(x+2,y-1,board) && !isOutOfBounds(x+2,y-1))
        {
            AddMove(x+2,y-1);
        }
        else if(isOpposingPlayer(x+2,y-1,board) && !isOutOfBounds(x+2,y-1))
        {
            AddCaptureMove(x+2,y-1);
        }

        //2 down 1 right
        if(isNull(x+1,y+2,board) && x+1<8 && y+2<8)
        {
            AddMove(x+1,y+2);
        }
        else if(isOpposingPlayer(x+1,y+2,board) && x+1<8 && y+2<8)
        {
            AddCaptureMove(x+1,y+2);
        }
        //1 down 2 right
        if(isNull(x+2,y+1,board) && x+2<8 && y+1<8)
        {
            AddMove(x+2,y+1);
        }
        else if(isOpposingPlayer(x+2,y+1,board) && x+2<8 && y+1<8)
        {
            AddCaptureMove(x+2,y+1);
        }
        //2 down 1 left
        if(isNull(x-1,y+2,board) && x-1>-1 && y+2<8)
        {
            AddMove(x-1,y+2);
        }
        else if(isOpposingPlayer(x-1,y+2,board) && x-1>-1 && y+2<8)
        {
            AddCaptureMove(x-1,y+2);
        }
        //1 down 2 left
        if(isNull(x-2,y+1,board) && x-2>-1 && y+1<8)
        {
            AddMove(x-2,y+1);
        }
        else if(isOpposingPlayer(x-2,y+1,board) && x-2>-1 && y+1<8)
        {
            AddCaptureMove(x-2,y+1);
        }
        //2 up 1 left
        if(isNull(x-1,y-2,board) && x-1>-1 && y-2>-1)
        {
            AddMove(x-1,y-2);
        }
        else if(isOpposingPlayer(x-1,y-2,board) && x-1>-1 && y-2>-1)
        {
            AddCaptureMove(x-1,y-2);
        }
        //1 up 2 left
        if(isNull(x-2,y-1,board) && x-2>-1 && y-1>-1)
        {
            AddMove(x-2,y-1);
        }
        else if(isOpposingPlayer(x-2,y-1,board) && x-2>-1 && y-1>-1)
        {
            AddCaptureMove(x-2,y-1);
        }
    }
};

#endif //CHESS_KNIGHT_H

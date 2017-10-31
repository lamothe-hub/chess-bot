//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "piece_variables.h"
#include "Piece.h"


class Pawn: public Piece {
private:

public:
    Pawn(int x,int y, int p,string t)
            : Piece(x,y,p,t) {
    }

    Pawn()
            : Piece() {
    }

    //Calculates all possible moves for the pawn piece
    void CalculatePossibleMoves(Piece* board[8][8]) {
        int x = GetXLocation();
        int y = GetYLocation();
        int p  = GetPlayer();
        //If player 1
        if(p == 1)
        {
            //If pawn's first move
            if(isFirstMove())
            {
                //Check y+1 and y+2 to see if piece is present
                for(int i=y+1;i<y+3;i++)
                {
                    //If the spot is NULL add move
                    if(isNull(x,i,board))
                    {
                        AddMove(x,i);
                    }
                }
            }
            else
            {
                //If the spot is NULL add move
                if(isNull(x,y+1,board))
                {
                    AddMove(x,y+1);
                }
            }

            if(isOpposingPlayer(x+1,y+1,board) && !isOutOfBounds(x+1,y+1))
            {
                AddCaptureMove(x+1,y+1);
            }

            if(isOpposingPlayer(x-1,y+1,board) && !isOutOfBounds(x-1,y+1))
            {
                AddCaptureMove(x-1,y+1);
            }
        }

        if(p == 2)
        {
            if(isFirstMove())
            {
                for(int i=y-1;i>y-3;i--)
                {
                    if(isNull(x,i,board))
                    {
                        AddMove(x,i);
                    }
                }

            }
            else
            {
                if(isNull(x,y-1,board))
                {
                    AddMove(x,y-1);
                }
            }

            if(isOpposingPlayer(x+1,y-1,board) && !isOutOfBounds(x+1,y-1))
            {
                AddCaptureMove(x+1,y-1);
            }
            if(isOpposingPlayer(x-1,y-1,board) && !isOutOfBounds(x-1,y-1))
            {
                AddCaptureMove(x-1,y-1);
            }
        }
    }

    //Check if the pawn is still on it's initial spot
    bool isFirstMove() {
        int y = GetYLocation();
        int p  = GetPlayer();

        if(p == 1)
        {
            if(y == 1) return true;
            else return false;
        }
        if(p == 2)
        {
            if(y == 6) return true;
            else return false;
        }
        return false;
    }
};

#endif //CHESS_PAWN_H

//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "piece_variables.h"
#include "Piece.h"

class Rook: public Piece {
public:
    //Constructor for Rook
    Rook(int x,int y, int p,string t)
            : Piece(x,y,p,t) {
    }
    //Calculates all possible moves for the rook piece
    void CalculatePossibleMoves(Piece* board[8][8]) {
        int x = GetXLocation();
        int y = GetYLocation();

        //Find all straight down moves
        for(int i=y+1;i<8;i++)
        {
            if(isNullStraightDown(x,i,board))
            {
                AddMove(x,i);
            }
        }

        //Find all straight up moves
        for(int i=y-1;i>-1;i--)
        {
            if(isNullStraightUp(x,i,board))
            {
                AddMove(x,i);
            }
        }

        //Find all straight right moves
        for(int i=x+1;i<8;i++)
        {
            if(isNullStraightRight(i,y,board))
            {
                AddMove(i,y);
            }
        }

        //Find all straight left moves
        for(int i=x-1;i>-1;i--)
        {
            if(isNullStraightLeft(i,y,board))
            {
                AddMove(i,y);
            }
        }
    }
};
#endif //CHESS_ROOK_H

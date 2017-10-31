//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "piece_variables.h"
#include "Piece.h"
class Bishop: public Piece {
public:
    //Constructor for the Bishop
    Bishop(int x,int y, int p,string t)
            : Piece(x,y,p,t) {
    }
    //Calculates all possible moves for the Bishop
    void CalculatePossibleMoves(Piece* board[8][8]) {
        int x = GetXLocation();
        int y = GetYLocation();

        //Find all diagonal down right moves
        for(int i=x+1,j=y+1;i<8 && j<8;i++,j++)
        {
            if(isNullDiagonalDownRight(i,j,board))
            {
                AddMove(i,j);
            }
        }

        //Find all diagonal up right moves
        for(int i=x+1,j=y-1;i<8 && j>-1;i++,j--)
        {
            if(isNullDiagonalUpRight(i,j,board))
            {
                AddMove(i,j);
            }
        }

        //Find All diagonal up left moves
        for(int i=x-1,j=y-1;i>-1 && j>-1;i--,j--)
        {
            if(isNullDiagonalUpLeft(i,j,board))
            {
                AddMove(i,j);
            }
        }

        //Find all diagonal down left moves
        for(int i=x-1,j=y+1;i>-1 && j<8;i--,j++)
        {
            if(isNullDiagonalDownLeft(i,j,board))
            {
                AddMove(i,j);
            }
        }
    }
};

#endif //CHESS_BISHOP_H

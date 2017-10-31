//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "piece_variables.h"

class Move {
private:
    int newX;
    int newY;
    bool doesCapture;
public:
    //Constructor
    Move(int x, int y, bool dc) {
        newX = x;
        newY = y;
        doesCapture = dc;
    }

    //Default Constructor
    Move() {
        newX = NULL;
        newY = NULL;
        doesCapture = NULL;
    }

    //Sets the x and y coordinates of the move
    void SetLocation(int x, int y) {
        newX = x;
        newY = y;
    }

    //Sets the doesCapture boolean
    void SetDoesCapture(bool dc) {
        doesCapture = dc;
    }

    int GetX() {
        return newX;
    }

    int GetY() {
        return newY;
    }

    bool GetDoesCapture () {
        return doesCapture;
    }
};

#endif //CHESS_MOVE_H

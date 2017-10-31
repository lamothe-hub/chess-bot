//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_GLOBALS_H
#define CHESS_GLOBALS_H

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

string p1Captured [16];
string p2Captured [16];
int indexP1 = 0;
int indexP2 = 0;

bool isOutOfBounds(int x, int y)
{
    if(x<0||x>7||y<0||y>7) return true;
    return false;
}


#endif //CHESS_GLOBALS_H

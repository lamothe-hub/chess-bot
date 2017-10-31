//
// Created by Jeffrey Lamothe on 10/30/17.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "chess_pieces.h"
class Board {
private:
    bool isCheckPlayer1;
    bool isCheckPlayer2;
    bool isCheckMatePlayer1;
    bool isCheckMatePlayer2;
    int kingX1;
    int kingY1;
    int kingX2;
    int kingY2;
    int piecesCaptured1;
    int piecesCaptured2;

public:
    Piece* board[8][8];
    //Board constructor that assigns each piece to the correct starting spot on the board
    Board();

    bool GetisCheckPlayer1();
    bool GetisCheckPlayer2();
    int GetKingX1 ();
    int GetKingY1 ();
    int GetKingX2 ();
    int GetKingY2 ();
    int GetPiecesCaptured1();
    int GetPiecesCaptured2();

    //Prints the x and y coordinates for each piece on the board
    void printBoard();

    //Takes an x and y location and a newx and newy location and moves that piece to its new location
    bool CheckSpotMove(int x, int y, int newX, int newY);

    //Takes an x and y location and prints out that pieces possible move list
    void CheckPossibleMoves(int x, int y);

    //Called at the beginning of each turn and calculates all moves then checks if any of the moves would capture either king
    void CheckForCheck();

    bool isCheckMate(int playerInCheck);

    int CheckPlayer(int x, int y);

    //Not used in the code ignore for now
    void CheckAllPiecesPossibleMoves ();

    int isCheckTempMove(int x, int y, int newX, int newY);
    //Moves a piece to its new location
    void MovePiece(int x, int y , int newX, int newY);

    //Checks the board for each king piece and keeps track of where the kings are at all times.
    void FindKings();
};

Board::Board() {
    isCheckPlayer1 = false;
    isCheckPlayer2 = false;
    isCheckMatePlayer1 = false;
    isCheckMatePlayer2 = false;
    kingX1 = 3;
    kingY1 = 0;
    kingX2 = 3;
    kingY2 = 7;
    piecesCaptured1 = 0;
    piecesCaptured2 = 0;
    board[0][0] = new Rook(0,0,1,"♜");
    board[0][1] = new Knight(1,0,1,"♞");
    board[0][2] = new Bishop(2,0,1,"♝");
    board[0][3] = new King(3,0,1,"♚");
    board[0][4] = new Queen(4,0,1,"♛");
    board[0][5] = new Bishop(5,0,1,"♝");
    board[0][6] = new Knight(6,0,1,"♞");
    board[0][7] = new Rook(7,0,1,"♜");
    for(int i=0;i<8;i++) board[1][i] = new Pawn(i,1,1,"♟");
    for(int i=2;i<6;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j] = NULL;
        }
    }
    for(int i=0;i<8;i++)
    {
        board[6][i] = new Pawn(i,6,2,"♙");
    }
    board[7][0] = new Rook(0,7,2,"♖");
    board[7][1] = new Knight(1,7,2,"♘");
    board[7][2] = new Bishop(2,7,2,"♗");
    board[7][3] = new King(3,7,2,"♔");
    board[7][4] = new Queen(4,7,2,"♕");
    board[7][5] = new Bishop(5,7,2,"♗");
    board[7][6] = new Knight(6,7,2,"♘");
    board[7][7] = new Rook(7,7,2,"♖");
}

bool Board::GetisCheckPlayer1() {
    return isCheckPlayer1;
}
bool Board::GetisCheckPlayer2() {
    return isCheckPlayer2;
}
int Board::GetKingX1 () {
    return kingX1;
}
int Board::GetKingY1 () {
    return kingY1;
}
int Board::GetKingX2 () {
    return kingX2;
}
int Board::GetKingY2 () {
    return kingY2;
}
int Board::GetPiecesCaptured1() {
    return piecesCaptured1;
}
int Board::GetPiecesCaptured2() {
    return piecesCaptured2;
}

//Prints the x and y coordinates for each piece on the board
void Board::printBoard(){
    cout << "  ================================== " <<endl;
    for(int i = 0; i <8; i++){
        cout << i;
        for(int j = 0; j<8; j++){
            if(board[i][j] != NULL ){
                cout << "\t" <<  board[i][j]-> GetType();
            }else{
                cout << "\t";
            }
        }
        cout << endl;
        cout << "  ==================================  ";
        cout << endl;
    }
}

//Takes an x and y location and a newx and newy location and moves that piece to its new location
bool Board::CheckSpotMove(int x, int y, int newX, int newY) {
    Move newMove(newX,newY,false);
    if(Pawn* p = dynamic_cast<Pawn*>(board[y][x]))
    {
        p->ClearMoves();
        p->CalculatePossibleMoves(board);
        if(p->isValidMove(newMove))
        {
            MovePiece(x,y,newX,newY);
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (Rook* r = dynamic_cast<Rook*>(board[y][x]))
    {
        r->ClearMoves();
        r->CalculatePossibleMoves(board);
        if(r->isValidMove(newMove))
        {
            MovePiece(x,y,newX,newY);
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(King* k = dynamic_cast<King*>(board[y][x]))
    {
        k->ClearMoves();
        k->CalculatePossibleMoves(board);
        if(k->isValidMove(newMove))
        {
            MovePiece(x,y,newX,newY);
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(Queen* q = dynamic_cast<Queen*>(board[y][x]))
    {
        q->ClearMoves();
        q->CalculatePossibleMoves(board);
        if(q->isValidMove(newMove))
        {
            MovePiece(x,y,newX,newY);
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(Knight* kn = dynamic_cast<Knight*>(board[y][x]))
    {
        kn->ClearMoves();
        kn->CalculatePossibleMoves(board);
        if(kn->isValidMove(newMove))
        {
            MovePiece(x,y,newX,newY);
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(Bishop* b = dynamic_cast<Bishop*>(board[y][x]))
    {
        b->ClearMoves();
        b->CalculatePossibleMoves(board);
        if(b->isValidMove(newMove))
        {
            MovePiece(x,y,newX,newY);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

//Takes an x and y location and prints out that pieces possible move list
void Board::CheckPossibleMoves(int x, int y) {
    if(Pawn* p = dynamic_cast<Pawn*>(board[y][x]))
    {
//					p->ClearMoves();
//					p->CalculatePossibleMoves(board);
        cout << "Possible Moves: ";
        p->PrintPossibleMoves();
        cout << endl;
    }
    else if (Rook* r = dynamic_cast<Rook*>(board[y][x]))
    {
        cout << "Possible Moves: ";
        r->PrintPossibleMoves();
        cout << endl;
    }
    else if(King* k = dynamic_cast<King*>(board[y][x]))
    {
        cout << "Possible Moves: ";
        k->PrintPossibleMoves();
        cout << endl;
    }
    else if(Queen* q = dynamic_cast<Queen*>(board[y][x]))
    {
        cout << "Possible Moves: ";
        q->PrintPossibleMoves();
        cout << endl;
    }
    else if(Knight* kn = dynamic_cast<Knight*>(board[y][x]))
    {
        cout << "Possible Moves: ";
        kn->PrintPossibleMoves();
        cout << endl;
    }
    else if(Bishop* b = dynamic_cast<Bishop*>(board[y][x]))
    {
        cout << "Possible Moves: ";
        b->PrintPossibleMoves();
        cout << endl;
    }
    else
    {
        cout << "There is no piece at this spot!" << endl;
    }
}

//Called at the beginning of each turn and calculates all moves then checks if any of the moves would capture either king
void Board::CheckForCheck() {
    isCheckPlayer1 = false;
    isCheckPlayer2 = false;
    FindKings();
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(Pawn* p = dynamic_cast<Pawn*>(board[i][j]))
            {
                p->ClearMoves();
                p->CalculatePossibleMoves(board);
                if(p->moveIsFound(kingX1,kingY1))
                {
                    isCheckPlayer1 = true;
                }
                if(p->moveIsFound(kingX2,kingY2))
                {
                    isCheckPlayer2 = true;
                }
            }
            else if (Rook* r = dynamic_cast<Rook*>(board[i][j]))
            {
                r->ClearMoves();
                r->CalculatePossibleMoves(board);
                if(r->moveIsFound(kingX1,kingY1))
                {
                    isCheckPlayer1 = true;
                }
                if(r->moveIsFound(kingX2,kingY2))
                {
                    isCheckPlayer2 = true;
                }
            }
            else if(King* k = dynamic_cast<King*>(board[i][j]))
            {
                k->ClearMoves();
                k->CalculatePossibleMoves(board);
                if(k->moveIsFound(kingX1,kingY1))
                {
                    isCheckPlayer1 = true;
                }
                if(k->moveIsFound(kingX2,kingY2))
                {
                    isCheckPlayer2 = true;
                }
            }
            else if(Queen* q = dynamic_cast<Queen*>(board[i][j]))
            {
                q->ClearMoves();
                q->CalculatePossibleMoves(board);
                if(q->moveIsFound(kingX1,kingY1))
                {
                    isCheckPlayer1 = true;
                }
                if(q->moveIsFound(kingX2,kingY2))
                {
                    isCheckPlayer2 = true;
                }
            }
            else if(Knight* kn = dynamic_cast<Knight*>(board[i][j]))
            {
                kn->ClearMoves();
                kn->CalculatePossibleMoves(board);
                if(kn->moveIsFound(kingX1,kingY1))
                {
                    isCheckPlayer1 = true;
                }
                if(kn->moveIsFound(kingX2,kingY2))
                {
                    isCheckPlayer2 = true;
                }
            }
            else if(Bishop* b = dynamic_cast<Bishop*>(board[i][j]))
            {
                b->ClearMoves();
                b->CalculatePossibleMoves(board);
                if(b->moveIsFound(kingX1,kingY1))
                {
                    isCheckPlayer1 = true;
                }
                if(b->moveIsFound(kingX2,kingY2))
                {
                    isCheckPlayer2 = true;
                }
            }
        }
    }
}

bool Board::isCheckMate(int playerInCheck) {
    Move tempPossibleMove;
    Piece* tempMoved;
    Piece* tempReplaced;
    int tempPossibleX;
    int tempPossibleY;
    bool foundMoveToStopCheck = false;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            tempMoved = board[j][i];
            if(tempMoved!=NULL && tempMoved->GetPlayer() == playerInCheck)
            {
                for(int k=0;k<tempMoved->GetPossibleMoveSize();k++)
                {
                    tempPossibleMove = tempMoved->GetPossibleMoveAt(k);
                    tempPossibleX = tempPossibleMove.GetX();
                    tempPossibleY = tempPossibleMove.GetY();

                    //Save the piece that is about to get replaced and then move the tempMoved
                    tempReplaced = board[tempPossibleY][tempPossibleX];
                    board[tempPossibleY][tempPossibleX] = tempMoved;
                    board[j][i] = NULL;
                    tempMoved->SetLocation(tempPossibleY,tempPossibleX);

                    CheckForCheck();
                    if(!GetisCheckPlayer1() && !GetisCheckPlayer2())
                    {
                        foundMoveToStopCheck = true;
                    }
                    board[j][i] = tempMoved;
                    board[tempPossibleY][tempPossibleX] = tempReplaced;
                    tempMoved->SetLocation(i,j);
                    CheckAllPiecesPossibleMoves();
                }
            }

        }
    }
    if(foundMoveToStopCheck) return false;
    else return true;
}

int Board::CheckPlayer(int x, int y) {
    if(Pawn* p = dynamic_cast<Pawn*>(board[y][x]))
    {
        return p->GetPlayer();
    }
    else if (Rook* r = dynamic_cast<Rook*>(board[y][x]))
    {
        return r->GetPlayer();
    }
    else if(King* k = dynamic_cast<King*>(board[y][x]))
    {
        return k->GetPlayer();
    }
    else if(Queen* q = dynamic_cast<Queen*>(board[y][x]))
    {
        return q->GetPlayer();
    }
    else if(Knight* kn = dynamic_cast<Knight*>(board[y][x]))
    {
        return kn->GetPlayer();
    }
    else if(Bishop* b = dynamic_cast<Bishop*>(board[y][x]))
    {
        return b->GetPlayer();
    }

    return 0;
}

//Not used in the code ignore for now
void Board::CheckAllPiecesPossibleMoves () {
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(Pawn* p = dynamic_cast<Pawn*>(board[i][j]))
            {
                p->ClearMoves();
                p->CalculatePossibleMoves(board);
            }
            else if (Rook* r = dynamic_cast<Rook*>(board[i][j]))
            {
                r->ClearMoves();
                r->CalculatePossibleMoves(board);
            }
            else if(King* k = dynamic_cast<King*>(board[i][j]))
            {
                k->ClearMoves();
                k->CalculatePossibleMoves(board);
            }
            else if(Queen* q = dynamic_cast<Queen*>(board[i][j]))
            {
                q->ClearMoves();
                q->CalculatePossibleMoves(board);
            }
            else if(Knight* kn = dynamic_cast<Knight*>(board[i][j]))
            {
                kn->ClearMoves();
                kn->CalculatePossibleMoves(board);
            }
            else if(Bishop* b = dynamic_cast<Bishop*>(board[i][j]))
            {
                b->ClearMoves();
                b->CalculatePossibleMoves(board);
            }
            else
            {
                cout << "There is no piece at this spot!" << endl;
            }
        }
    }
}

int Board::isCheckTempMove(int x, int y, int newX, int newY) {
    int player = 0;
    bool isOriginalCheck = true;
    FindKings();
    CheckForCheck();

    //If this is the original check then let the move happen
    if(GetisCheckPlayer1() || GetisCheckPlayer2())
    {
        isOriginalCheck = false;
    }

    //Temporarily move the piece
    Piece* tempMoved = board[y][x];
    Piece* tempReplaced = board[newY][newX];
    board[newY][newX] = tempMoved;
    board[y][x] = NULL;
    tempMoved->SetLocation(newX,newY);

    //Check the temporary board for check's
    CheckForCheck();

    //Move the piece back to its original spot
    board[y][x] = tempMoved;
    board[newY][newX] = tempReplaced;
    tempMoved->SetLocation(x,y);

    //If the player is in check and
    if(GetisCheckPlayer1() && isOriginalCheck == false)
    {
        cout << "Player 1 would still be in check!" << endl;
        return 1;
    }
    if(GetisCheckPlayer2() && isOriginalCheck == false)
    {
        cout << "Player 2 would still be in check!" << endl;
        return 2;
    }
    return 0;
}

//Moves a piece to its new location
void Board::MovePiece(int x, int y , int newX, int newY) {
    Piece* piece = board[y][x];
    piece->SetLocation(newX,newY);
    if(board[newY][newX] != NULL)
    {
        if(board[newY][newX]->GetPlayer() == 1)
        {
            piecesCaptured1++;
            p1Captured[indexP1] = board[newY][newX]->GetType();
            indexP1++;
        }
        else if(board[newY][newX]->GetPlayer() == 2)
        {
            piecesCaptured2++;
            p2Captured[indexP2] = board[newY][newX]->GetType();
            indexP2++;
        }
    }
    board[newY][newX] = piece;
    board[y][x] = NULL;
}

//Checks the board for each king piece and keeps track of where the kings are at all times.
void Board::FindKings() {
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(!board[i][j]->isNull(j,i,board))
            {
                if(board[i][j]->GetType() == "♚")
                {
                    kingX1 = j;
                    kingY1 = i;
                }
                else if(board[i][j]->GetType() == "♔")
                {
                    kingX2 = j;
                    kingY2 = i;
                }
            }
        }
    }
}

#endif //CHESS_BOARD_H

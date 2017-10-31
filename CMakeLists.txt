cmake_minimum_required(VERSION 3.6)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp piece_variables.h Move.h Piece.h Pawn.h Rook.h King.h Queen.h Knight.h Bishop.h Board.h chess_pieces.h main_variables.h)
add_executable(Chess ${SOURCE_FILES})
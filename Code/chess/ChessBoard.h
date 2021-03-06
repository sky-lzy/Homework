#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessType.h"

class ChessBoard
{
private:
    int board[16][16];

public:
    ChessBoard();                                    //构造函数
    ~ChessBoard();                                   //析构函数
    void show();                                     //显示棋盘
    void SetChess(ChessType c, int row, int column); //黑白双方落子
    bool ValidPlace(int row, int column);            //判断落子是否合法
    bool Win(ChessType c, int row, int column);      //判断胜利条件
};

#endif
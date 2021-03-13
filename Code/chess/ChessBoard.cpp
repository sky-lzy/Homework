#include <iostream>
#include "ChessBoard.h"
using namespace std;

ChessBoard::ChessBoard() : board{0} //初始化棋盘
{
    cout << "游戏开始，请黑方先落子" << endl;
    show();
}

ChessBoard::~ChessBoard()
{
    cout << "游戏结束，再见！" << endl;
}

void ChessBoard::show()
{
    int i, j;
    for (i = 1; i <= 15; i++)
    {
        for (j = 1; j <= 15; j++)
        {
            if (board[i][j] == 0)
                cout << "+ ";
            else if (board[i][j] == 1)
                cout << "● ";
            else if (board[i][j] == -1)
                cout << "○ ";
        }
        cout << endl;
    }
}

void ChessBoard::SetChess(ChessType c, int row, int column)
{
    if (c = Black)
        board[row][column] = 1;
    else
        board[row][column] = -1;
    show();
}

bool ChessBoard::ValidPlace(int row, int column)
{
    if (row >= 1 && row <= 15 && column >= 1 && column <= 15) //不超范围
        if (board[row][column] == 0)                          //落子于空位处
            return true;
        else
        {
            cout << "此位置不可以落子" << endl;
            return false;
        }
    else
    {
        cout << "超出棋盘范围" << endl;
        return false;
    }
}

bool ChessBoard::Win(ChessType c, int row, int column)
{
    int i, j, k;
    bool flag = false;
    for (i = -1; i <= 1 && !flag; i++) //遍历九个方向
    {
        if (row + 5 * i < 1 || row + 5 * i > 15) //超范围舍去
            break;
        for (j = -1; j <= 1 && !flag; j++)
        {
            if (column + 5 * j < 1 || column + 5 * j > 15)
                break;
            for (k = 1; k <= 5; k++) //连续五子计数
                if (board[row + k][column + k] != (int)c)
                    break;
            if (k = 5) //判断胜利条件
                flag = true;
        }
    }
    return flag;
}
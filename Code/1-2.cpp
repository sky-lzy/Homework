#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum ChessType
{
    Black = 1,
    White
};

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
} chessBoard;

ChessBoard::ChessBoard() : board{0} {}

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
            cout << board[i][j];
        cout << endl;
    }
}

void ChessBoard::SetChess(ChessType c, int row, int column)
{
    if (c = Black)
        board[row][column] = 1;
    else
        board[row][column] = -1;
}

bool ChessBoard::ValidPlace(int row, int column)
{
    if (row >= 1 && row <= 15 && column >= 1 && column <= 15) //不超范围
        if (board[row][column] == 0)                          //落子于空位处
            return true;
        else
            ;
    else
        return false;
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

class Player
{
private:
    string name;
    ChessType chessType;

public:
    Player(string s, ChessType c);      //构造函数
    ~Player();                          //析构函数
    bool setChess(int row, int column); //玩家落子，并返回是否合法
};

Player::Player(string s, ChessType c) : name(s), chessType(c) {}

Player::~Player() {}

bool Player::setChess(int row, int column)
{
    if (chessBoard.ValidPlace(row, column))
    {
        chessBoard.SetChess(chessType, row, column);
        return true;
    }
    else
        return false;
}

int main()
{
    cout << "开始游戏！" << endl;
    chessBoard.show();
    string name1, name2;
    cout << "请输入黑方姓名：" << endl;
    cin >> name1;
    cout << "请输入白方姓名：" << endl;
    cin >> name2;
    Player A(name1, Black), B(name2, White);
    bool flag = false, set = true;
    ChessType y;
    int row, column;
    Player *pointer;
    while (!flag)
    {
        if (set)
            y = Black, pointer = &A;
        else
            y = White, pointer = &B;
        cout << y << "：" << endl;
        cin >> row >> column;
        if (!pointer->setChess(row, column))
        {
            cout << "Error!" << endl;
            continue;
        }
        chessBoard.show();
        if (chessBoard.Win(y, row, column))
            flag = true;
        set = !set;
    }
    if (set)
        cout << "白方";
    else
        cout << "黑方";
    cout << "获胜！" << endl;
    return 0;
}
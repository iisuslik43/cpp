#pragma once

class Board
{
private:
    int** field_;
    int size_;
public:
    Board();
    void make_move(int x, int y, int sign);
    bool canMove(int x, int y, int sign);
    int isWin(int x, int y, int sign);
    int** getField();
};

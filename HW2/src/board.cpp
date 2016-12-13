#include <cstdio>
#include <stack>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stdlib.h>
#include "board.h"
using namespace std;


Board::Board()
    {
        size_=0;
        field_ = new int* [10];
        for(int i = 0; i < 10; i++)
        {
            field_[i] = new int [10];
            for(int j = 0; j < 10; j++)
            {
                field_[i][j] = 0;
            }
        }
    }
void Board::make_move(int x, int y, int sign)
    {
        field_ [x][y] = sign;
        size_++;
    }
bool Board::canMove(int x, int y, int sign)
    {
        if(y > 9 || x > 9 || x < 0 || y < 0 || field_[x][y]) return false;
        else return true;
    }
int Board::isWin(int x, int y, int sign)
    {
        int izi = 1;
        bool f1 = true;
        bool f2 = true;
        for(int i = 1; i <= 5; i++){
            if(f1 && x+i < 10 && field_[x+i][y] == sign)izi++;
            else f1 = false;
            if(f2 && x-i >= 0 && field_[x-i][y] == sign)izi++;
            else f2 = false;
            if(izi >= 5)return sign;
        }
        izi = 1;
        f1 = true;
        f2 = true;
        for(int i = 1; i <= 5; i++){
            if(f1 && y+i < 10 && field_[x][y+i] == sign)izi++;
            else f1 = false;
            if(f2 && y-i >= 0 && field_[x][y-i] == sign)izi++;
            else f2 = false;
            if(izi >= 5)return sign;
        }
        izi = 1;
        f1 = true;
        f2 = true;
        for(int i = 1; i <= 5; i++){
            if(f1 && x+i < 10 && y+i < 10 && field_[x+i][y+i] == sign)izi++;
            else f1 = false;
            if(f2 && x-i >= 0 && y-i >= 0 && field_[x-i][y-i] == sign)izi++;
            else f2 = false;
            if(izi >= 5)return sign;
        }
        izi = 1;
        f1 = true;
        f2 = true;
        for(int i = 1; i <= 5; i++){
            if(f1 && x+i < 10 && y-i >= 0 && field_[x+i][y-i] == sign)izi++;
            else f1 = false;
            if(f2 && x-i >= 0 && y+i < 10 && field_[x-i][y+i] == sign)izi++;
            else f2 = false;
            if(izi >= 5)return sign;
        }
        //cout<<endl<<izi<<endl;
        if(size_!=100)return 0;
        else return -1;
    }
int** Board::getField()
    {
        return field_;
    }

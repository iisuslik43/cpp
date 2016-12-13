#include <cstdio>
#include <stack>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stdlib.h>
#include "view.h"
#include "board.h"
using namespace std;


View::View(Board *m)
    {
        b_ = m;
        end_ = false;
        turn = 1;
    }
void View::showBoard()
    {
        int **field = b_ -> getField();
        cout<<endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                int t = field[i][j];
                if(!t)
                    cout << "." << " ";
                else if(t == 1)
                    cout << "O" << " ";
                else
                    cout << "X" << " ";
            }
            cout << endl;
        }
    }
void View::doGameCycle()
    {
        int x, y, sign;
        sign = turn;
        if(turn==1)cout <<"O move: ";
        else cout<<"X move: ";
        cin >> x >> y;
        if(x == -1 && y == -1){
            end_ = true;
            return;
        }
        if(b_ -> canMove(x, y, sign))
        {
            b_ -> make_move(x, y, sign);
            int res = b_ -> isWin(x, y, sign);
            if(res == 0) //nobody wins
            {
                showBoard();
                turn = 3 - turn;
                return;
            }
            if(res == 1) //O wins
            {
                showBoard();
                cout << "O wins!";
                end_ = true;
                return;
            }
            if(res == 2) //X wins
            {
                showBoard();
                cout << "X wins!";
                end_ = true;
                return;
            }
            if(res == -1) //draw
            {
                showBoard();
                cout << "Draw.";
                end_ = true;
                return;
            }
            else cout<< "WTF";
        }
        else
        {
            cout << "Bad move!" << endl;
            return;
        }
        return;

    }
bool View::isEnd()
    {
        return end_;
    }

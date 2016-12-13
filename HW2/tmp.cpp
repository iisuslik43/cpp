#include <cstdio>
#include <stack>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stdlib.h>


using namespace std;

class Board
{
private:
    int** field_;
    int size_;
public:
    Board()
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
    void make_move(int x, int y, int sign)
    {
        field_ [x][y] = sign;
        size_++;
    }
    bool canMove(int x, int y, int sign)
    {
        if(y > 9 || x > 9 || x < 0 || y < 0 || field_[x][y]) return false;
        else return true;
    }
    int isWin(int x, int y, int sign)
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
    int** getField()
    {
        return field_;
    }
};

class View
{
private:
    Board* b_;
    bool end_;
    int turn;
public:
    View(Board *m)
    {
        b_ = m;
        end_ = false;
        turn = 1;
    }
    void showBoard()
    {
        int **field = b_ -> getField();
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
    void doGameCycle()
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
    bool isEnd()
    {
        return end_;
    }
};


int main()
{
    Board* b = new Board;
    View v = View(b);
    while(!v.isEnd())
    {
        v.doGameCycle();
    }
}

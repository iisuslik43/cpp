#include <cstdio>
#include <stack>
#include <iostream>
#include <cassert>
#include <cstring>
#include <stdlib.h>
#include "board.h"
#include "view.h"
using namespace std;

int main()
{
    Board* b = new Board;
    View v = View(b);
    v.showBoard();
    while(!v.isEnd())
    {
        v.doGameCycle();
    }
}

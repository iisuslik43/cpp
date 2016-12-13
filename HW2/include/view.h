#include "board.h"


class View
{
private:
    Board* b_;
    bool end_;
    int turn;
public:
    View(Board *m);
    void showBoard();
    void doGameCycle();
    bool isEnd();
};

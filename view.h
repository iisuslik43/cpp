//
// Created by iisus on 23.08.2017.
//

#ifndef KUR_VIEW_H
#define KUR_VIEW_H
#include "struct.h"

static const int ADD = 1;
static const int SAVE = 2;
static const int LOAD = 3;
static const int PRINT = 4;
static const int GET = 5;
static const int SORT = 6;
static const int FINISH = 7;

void print_gun(gun* g);
void print_list(gun* head);
void print_less(gun* head, int cost);
int ask();
int ask_less_what();
int ask_sort_kind();
gun* get_gun();

#endif //KUR_VIEW_H

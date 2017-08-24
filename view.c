//
// Created by iisus on 23.08.2017.
//

#include "view.h"

void print_gun(gun* g){
    printf("%s %d %d %d\n", g->type, g->ammo, g->caliber, g->price);
}

void print_list(gun* head){
    while(head){
        print_gun(head);
        head = head->next;
    }
}

gun* get_gun(){
    gun* new = malloc(sizeof(gun));
    new->next = new->prev = NULL;
    printf("Write type:\n");
    scanf("%s", new->type);
    printf("Write ammo:\n");
    scanf("%d", &new->ammo);
    printf("Write caliber:\n");
    scanf("%d", &new->caliber);
    printf("Write price:\n");
    scanf("%d", &new->price);
    return new;
}
void print_less(gun* head, int cost){
    while(head){
        if(head->price <= cost)
            print_gun(head);
        head = head->next;
    }
}

int ask(){
    int res = 0;
    printf("1.ADD\n2.SAVE\n3.LOAD\n4.PRINT\n5.GEt\n6.SORT\n7.EXIT\n");
    scanf("%d", &res);
    return res;
}

int ask_less_what(){
    printf("Less than what:\n");
    int res;
    scanf("%d", &res);
    return res;
}
int ask_sort_kind(){
    printf("How to sort:\n1.Type\n2.Price");
    int res;
    scanf("%d", &res);
    return res;
}
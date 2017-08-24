//
// Created by iisus on 22.08.2017.
//
#include "struct.h"

void save_gun(gun* g, FILE* file){
    for(int i = 0; i < 20; i++)
        fwrite (&(g->type[i]), sizeof(char),1, file );
    fwrite (&(g->ammo), sizeof(int),1, file );
    fwrite (&(g->caliber), sizeof(int),1, file );
    fwrite (&(g->price), sizeof(int),1, file );
}

void save_list(gun* head){
    FILE *file = fopen("for_guns","w");
    if(file == NULL){
        printf("Can`t find file for_guns");
        clear(head);
        exit(0);
    }
    while(head){
        save_gun(head, file);
        head = head->next;
    }
    fclose(file);
}

void load_gun(gun* g, FILE* file){
    for(int i = 0; i < 20; i++)
        fread (&(g->type[i]), sizeof(char),1, file );
    fread (&(g->ammo), sizeof(int),1, file );
    fread (&(g->caliber), sizeof(int),1, file );
    fread (&(g->price), sizeof(int),1, file );
    g->prev = g->next = NULL;
}

int get_size(FILE* file){
    fseek(file,0,SEEK_END);

    int size =  ftell(file);
    fseek(file,0,SEEK_SET);
    return size;
}

gun* load_list(gun* head){
    FILE *file = fopen("for_guns","r");
    if(file == NULL){
        printf("Can`t find file for_guns");
        clear(head);
        exit(0);
    }
    int count = get_size(file) / 32;
    int first = 1;
    clear(head);
    head = NULL;
    gun* g = NULL;
    gun* prev = NULL;
    for(int i = 0; i < count; i++){
        prev = g;
        g = malloc(sizeof(gun));
        load_gun(g, file);
        if(first){
            head = g;
            first = 0;
        }
        if(prev){
            prev->next = g;
            g->prev = prev;
        }
    }
    fclose(file);
    return head;
}

gun* clear(gun* head){
    while(head){
        gun* temp = head;
        head = head->next;
        free(temp);
    }
    return NULL;
}
gun* add(gun* head, gun* new){
    if(!head){
        head = new;
        return head;
    }
    gun* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    return  head;
}



void delete(gun* del){
    if(del->prev)
        del->prev->next = del->next;
    if(del->next)
        del->next->prev = del->prev;
}

void insert(gun* what, gun* before_what){
    what->next = before_what;
    if(before_what->prev){
        before_what->prev->next = what;
    }
    what->prev = before_what->prev;
    before_what->prev = what;
}

int comp(gun* a, gun* b, int type_or_price){
    if(type_or_price == BY_TYPE){
        return -strcmp(a->type, b->type);
    }
    else{
        if(a->price < b-> price)
            return 1;
        if(a->price == b->price)
            return 0;
        else
            return -1;
    }
}

gun* sort(gun* head, int type_or_price){
    gun* now_head = head;
    int first_min = 1;
    while(now_head->next){

        gun* temp = now_head;
        gun* min = now_head;
        while(temp){
            if(comp(temp, min, type_or_price) == 1){
                min = temp;
            }
            temp = temp->next;
        }
        if(first_min){
            head = min;
            first_min = 0;
        }
        if(min == now_head) {
            now_head = now_head->next;
            continue;
        }

        delete(min);
        insert(min, now_head);
    }
    return head;
}



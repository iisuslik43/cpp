
#include "view.h"

int main() {
    gun* head = NULL;
    int finish = 0;
    while(!finish){
        int res = ask();
        if(res == ADD){
            gun* g = get_gun();
            head = add(head, g);
        }
        else if(res == SAVE){
            save_list(head);
        }
        else if(res == LOAD){
            head = load_list(head);
        }
        else if(res == PRINT){
            print_list(head);
        }
        else if(res == SORT){
            head = sort(head, ask_sort_kind());
        }
        else if(res == GET){
            print_less(head, ask_less_what());
        }
        else if(res == FINISH){
            finish = 1;
        }
    }

    clear(head);
    return 0;
}
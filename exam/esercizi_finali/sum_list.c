#include <stdio.h>

typedef struct List {
    int value;
    struct List *next;
} List;

int sum_list(List *ptr){
    if(ptr == NULL) return 0;

    return ptr->value + sum_list(ptr->next);
}

int count_list(List *ptr){
    if(ptr == NULL) return 0;

    return 1 + count_list(ptr->next);
}

int max_list(List *ptr){
    if(ptr == NULL) return 0;

    int max = max_list(ptr->next);

    if(ptr->value < max){
        return max;
    } else {
        return ptr->value;
    }
}

int is_sorted_list(List *ptr){
    if(ptr == NULL) return 1;
    if(ptr->next == NULL) return 1;
    List *nextElem = ptr->next;

    if(ptr->value <  nextElem->value){
        return is_sorted_list(ptr->next);
    } else {
        return 0;
    }
}

int count_even(List *ptr){
    if(ptr == NULL) return 0;

    if(ptr->value % 2 == 0){
        return 1 + count_even(ptr->next);
    } else {
        return count_even(ptr->next);
    }
}

int main(void){

}
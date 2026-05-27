#include <stdio.h>

struct Person {
    char name[20];
    int age;
};

void modifyAge(struct Person *p, int age){
    p->age = age;
}

int main() {
    struct Person Jack = {
        "Jack", 
        20
    };
    struct Person AnnaBelle = {
        "Annabelle",
        30,
    };

    struct Person structAr[2] = {Jack, AnnaBelle};

    int arSize = sizeof(structAr) / sizeof(structAr[0]);

    for(int i=0; i<arSize; i++){
        printf("Hi this is %s, and I'm %d years old!\n", structAr[i].name, structAr[i].age);
    }

    printf("%d\n", Jack.age);

    modifyAge(&Jack, 25);

    printf("%d\n", Jack.age);
    return 0;
}
#include "liststatik.h"
#include <stdio.h>


int main (){
    ListStatik arr;
    CreateListStatik(&arr);

    int z;
    scanf("%d",&z);

    while (z != -1){
        if (z == 1){
            int berat, indeks;
            scanf("%d %d", &berat, &indeks);
            if (isFull(arr) || !isIdxValid(arr, indeks)){
                printf("Aw, gabisa ngelakuin aksi itu\n");
                printList(arr);
                printf("\n");
            } else {
                insertAt(&arr, berat, indeks);
                printList(arr);
                printf("\n");
            }
        } else if (z == 0){
            int indeks;
            scanf("%d", &indeks);

            if (isEmpty(arr) || !isIdxValid(arr, indeks)){
                printf("Aw, gabisa ngelakuin aksi itu\n");
                printList(arr);
                printf("\n");
            } else {
                int x;
                deleteAt(&arr, &x, indeks);
                printList(arr);
                printf("\n");
            }
        } else {
            printf("Aw, gabisa ngelakuin aksi itu\n");
            printList(arr);
            printf("\n");
        }
        scanf("%d", &z);
    }
    return 0;
}
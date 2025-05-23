#include <stdio.h>
#include "queue.h"
#define IDX_UNDEF -1
#define CAPACITY 100


void CreateQueue(Queue *q){
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    if (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF){
        return true;
    }
    return false;
}

boolean isFull(Queue q){
    if (((IDX_TAIL(q) + 1) % CAPACITY) == IDX_HEAD(q)) return true;
    return false;
}

int length(Queue q){
    if (isEmpty(q)) return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    else
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
}


void enqueue (Queue *q, ElType val){
    if (isFull(*q)) return;
    else {
        if (isEmpty(*q)){
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = 0;
        } else {
            q->idxTail = (q->idxTail + 1) % CAPACITY;
        }
        q->buffer[q->idxTail] = val;
    }
}

void dequeue (Queue *q, ElType *val){
    if (isEmpty(*q)) return;
    else {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q)){
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        } else {
            q->idxHead = (q->idxHead + 1) % CAPACITY;
        }
    }
}

void displayQueue (Queue q){
    if (isEmpty(q)) {
        printf("[]\n");
    } else {
        printf("[");
        int i = IDX_HEAD(q);
        while (true){
            if (i == IDX_TAIL(q)){
                printf("%d", q.buffer[i]);
                break;
            }
            printf("%d,", q.buffer[i]);
            i = (i + 1) % CAPACITY;
        }
        printf("]\n");
    }
}
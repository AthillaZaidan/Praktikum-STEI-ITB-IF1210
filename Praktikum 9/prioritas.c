/* File : prioritas.c */
#include "queue.h"

void prioritizeValue(Queue *q, int x){
    Queue qtemp, qtemp2;
    ElType dummy;
    int len = length(*q);
    CreateQueue(&qtemp); CreateQueue(&qtemp2);

    for (int i=0; i<len; i++){
        if (q->buffer[i] == x){
            enqueue(&qtemp, q->buffer[i]);
            dequeue(q, &dummy);
        }
        else {
            enqueue(&qtemp2, q->buffer[i]);
            dequeue(q, &dummy);
        }
    }

    int len1 = length(qtemp);
    for (int i=0; i<len1; i++){
        enqueue(q, HEAD(qtemp));
        dequeue(&qtemp, &dummy);
    }
    int len2 = length(qtemp2);
    for (int i=0; i<len2; i++){
        enqueue(q, HEAD(qtemp2));
        dequeue(&qtemp2, &dummy);
    }
}

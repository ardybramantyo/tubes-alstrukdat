#include "Queue.h"
#include "ArrayDin.h"
#include "Barang.h"

#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue* q) {
    MakeEmptyArrayDin(&(q->arr));
}

void enqueue(Queue* q, const char* nama_barang) {
    ArrayDinInsertEnd(&(q->arr), createBarang(nama_barang, -1));
}

char* dequeue(Queue* q) {
    char* a = (q->arr).arr[0].name;
    ArrayDinDeleteBeginning(&(q->arr));

    return a;
}

char* front(Queue q) {
    return q.arr.arr[0].name;
}






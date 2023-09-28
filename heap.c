#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void swap(heapElem* a, heapElem* b) {
    heapElem temp = *a;
    *a = *b;
    *b = temp;
}

void* heap_top(Heap* pq) {
    if (pq->size == 0) {
        return NULL;
    }
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (heap == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el montículo.\n");
        exit(1);
    }
    
    heap->capac = 3;
    heap->size = 0;
    heap->heapArray = (heapElem*)malloc(heap->capac * sizeof(heapElem));
    if (heap->heapArray == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el arreglo del montículo.\n");
        exit(1);
    }
    
    return heap;
}

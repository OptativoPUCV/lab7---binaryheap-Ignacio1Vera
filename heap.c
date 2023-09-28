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



void heap_push(Heap* pq, void* data, int p) 
{
    if (pq->size == pq->capac) 
    {
        pq->capac = pq->capac * 2 + 1;
        pq->heapArray = (heapElem*)realloc(pq->heapArray, pq->capac * sizeof(heapElem));
        if (pq->heapArray == NULL) 
        {
            fprintf(stderr, "Error: No se pudo asignar memoria para el arreglo del montículo.\n");
            exit(1);
        }
    }
    heapElem newItem;
    newItem.data = data;
    newItem.priority = p;
    int i = pq->size;
    pq->size++;
    pq->heapArray[i] = newItem;
    while (i > 0 && pq->heapArray[i].priority > pq->heapArray[(i - 1) / 2].priority) 
    {
        swap(&pq->heapArray[i], &pq->heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void heap_pop(Heap* pq) 
{
    if (pq->size == 0) 
        return;

    pq->size--;
    pq->heapArray[0] = pq->heapArray[pq->size];

    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int largest = i;

        if (leftChild < pq->size && pq->heapArray[leftChild].priority > pq->heapArray[largest].priority) 
            largest = leftChild;
        if (rightChild < pq->size && pq->heapArray[rightChild].priority > pq->heapArray[largest].priority) 
            largest = rightChild;

        if (largest != i) 
        {
            swap(&pq->heapArray[i], &pq->heapArray[largest]);
            i = largest;
        } 
        else 
            break;
    }
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

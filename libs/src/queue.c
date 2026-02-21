#include "queue.h"
#include "vector.h"

void Queue(queue* q, size_t type_size, int cap){
    Vector(&q->v, type_size, cap, NULL);
    q->enqueue = enqueue;
    q->dequeue = dequeue;
    q->isEmpty = isEmpty;
    q->clear = clear;
}

void enqueue(queue* q, void* value){
    q->v.push_back(&q->v, value);
}

void* dequeue(queue* q){
    if(q->v.isEmpty(&q->v)){
        return NULL;
    }

    return q->v.pop(&q->v, 0);
}

bool isEmpty(queue* q){
    return q->v.isEmpty(&q->v);
}

void clear(queue* q){
    q->v.clear(&q->v);
}
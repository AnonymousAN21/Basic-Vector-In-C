#include "vector.h"
#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
    vector v;
    void(*enqueue)(struct queue*, void*);
    void*(*dequeue)(struct queue*);
    bool(*isEmpty)(struct queue*);
    void(*clear)(struct queue*);
} queue;

/**
 * @brief Initialize the Queue
 * 
 */
void Queue(queue* q, size_t type_size, int cap);
void enqueue(queue* q, void* value);
void* dequeue(queue* q);
bool isEmpty(queue* q);
void clear(queue* q);
#endif
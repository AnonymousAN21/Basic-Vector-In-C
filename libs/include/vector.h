/*
 * MIT License
 * Copyright (c) 2026 Andrew Tangel
 * See LICENSE file in the project root for full license information.
 */
#include <stdlib.h>
#include <stdbool.h>
#ifndef VECTOR_H
#define VECTOR_H
typedef struct vector
{
    void* data;
    size_t elem_size;
    int size;
    int capacity;

    void(*push_back)(struct vector*, void*);
    void*(*pop)(struct vector*, int);
    bool(*isEmpty)(struct vector*);
    bool(*isSort)(struct vector*, int (*compare)(const void*, const void*));
    int(*length)(struct vector*);
    void(*clear)(struct vector*);
    void* (*get)(struct vector*, int);
} vector;

void Vector(vector *v, size_t type_size, int cap, void* defaultvalue);
#endif
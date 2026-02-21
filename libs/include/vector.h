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

    /**
    * @brief add new element in the back of an vector and auto reallocate new memory size
    * @param v Pointer to Vector
    * @param value Generic value to store
    */
    void(*push_back)(struct vector*, void*);
    /**
     * @brief insert new element into Vector with specific index
     * 
     * @param v Pointer to Vector
     * @param value Generic value to store
     * @param index Index of the element to insert
     */
    void(*insert)(struct vector*, void*, int);
    /**
     * @brief pop element from specific index
     * 
     * @param v Pointer to Vector
     * @param index Index of the element to pop
     */
    void*(*pop)(struct vector*, int);
    /**
     * @brief to check if Vector is Empty
     * 
     * @param v Pointer to Vector
     * @return Boolean True | False
     */
    bool(*isEmpty)(struct vector*);
    /**
     * @brief to check if Vector is Sorted
     * 
     * @param v Pointer to Vector
     * @param compare comparator function
     * @return Boolean True | False
     */
    bool(*isSort)(struct vector*, int (*compare)(const void*, const void*));
    /**
     * @brief to measure the length of the Vector
     * 
     * @param v Pointer to Vector
     * @return Integer length of the vector
     */
    int(*length)(struct vector*);
    /**
     * @brief to free the memory after usage of the vector IMPORTANT!
     * if not it will cause memory leak
     * @param v Pointer to Vector
     */
    void(*clear)(struct vector*);
    /**
     * @brief to get specific value in specific index
     * 
     * @param v Pointer to Vector
     * @param index Index of the value
     * @return Value of the index
     */
    void* (*get)(struct vector*, int);
} vector;

/**
 * @brief Initialize the Vector
 * 
 * @param v Pointer to Vector
 * @param type_size sizeof(datatype)
 * @param cap Capacity of the Vector
 * @param defaultvalue Default value of the vector
 */
void Vector(vector *v, size_t type_size, int cap, void* defaultvalue);
#endif
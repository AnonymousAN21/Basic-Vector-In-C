/*
 * MIT License
 * Copyright (c) 2026 Andrew Tangel
 * See LICENSE file in the project root for full license information.
 */

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void vector_push_back(vector* v, void* value);
void* vector_pop(vector* v, int index);
bool vector_isEmpty(vector* v);
bool vector_isSort(vector* v, int (*compare)(const void*, const void*));
int vector_length(vector* v);
void* vector_get(vector* v, int index);
void vector_clear(vector* v);

void Vector(vector *v, size_t type_size, int cap, void* defaultvalue)
{
    v->capacity = (cap > 0) ? cap : 2;
    v->elem_size = type_size;
    v->data = malloc(v->capacity * type_size);

    if(defaultvalue != NULL) {
        v->size = v->capacity;
        for(int i = 0; i < v->capacity; i++){
            char* target = (char*)v->data + (i * v->elem_size);
            memcpy(target, defaultvalue, v->elem_size);
        }
    }else{
        v->size = 0;
    }

    v->push_back = vector_push_back;
    v->pop = vector_pop;
    v->isEmpty = vector_isEmpty;
    v->isSort = vector_isSort;
    v->length = vector_length;
    v->get = vector_get;
    v->clear = vector_clear;
}

int resize(vector* v){
    int _temp = v->capacity * 2;
    void* temp = realloc(v->data, _temp * v->elem_size);
    if(!temp) return -1;
    v->capacity = _temp;
    v->data = temp;
    return 1;
}

int resize_shrink(vector* v){
    int _temp = v->capacity / 2;
    if(_temp < 2) _temp = 2;
    void* temp = realloc(v->data, _temp * v->elem_size);
    if(!temp) return -1;
    v->capacity = _temp;
    v->data = temp;
    return 1;
}

void vector_push_back(vector* v, void* value){
    if(v->size == v->capacity){
        if (resize(v) == -1) {
            printf("Crash Failed to allocate more memory");
            return;
        }
    }

    char* dest = (char*)v->data + (v->size * v->elem_size);
    memcpy(dest, value, v->elem_size);

    v->size++;
}

void* vector_pop(vector* v, int index){
    if(index < 0 || index >= v->size){
        printf("Index Out of bound!");
        return NULL;
    }

    void* current_val = malloc(v->elem_size);
    if(current_val == NULL) return NULL;

    char* data_ptr = (char*)v->data;
    char* target = data_ptr + (index * v->elem_size);

    memcpy(current_val, target, v->elem_size);

    char* next = target + v->elem_size;
    size_t move_bytes = (v->size - index - 1) * v->elem_size;

    if(move_bytes > 0){
        memmove(target, next, move_bytes);
    }

    v->size--;

    if(v->size > 0 && v->size <= v->capacity / 4){
        resize_shrink(v);
    }

    return current_val;
}

bool vector_isEmpty(vector* v){
    return v->size == 0;
}

    
bool vector_isSort(vector* v, int (*compare)(const void*, const void*)){
    if (v->size < 2) return true;

    char* data_ptr = (char*)v->data;
    for(int i = 0; i < v->size - 1; i++){
        void* current = data_ptr + (i * v->elem_size);
        void* next = data_ptr + ((i + 1) * v->elem_size);

        if(compare(current, next) > 0){
            return false;
        }
    }
    return true;
}

int vector_length(vector* v){
    return v->size;
}

void* vector_get(vector* v, int index){
    if(index < 0 || index >= v->size) {
        printf("Index Out of bound!");
        return NULL;
    }

    return (char*)v->data + (index * v->elem_size);
}

void vector_clear(vector* v){
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}
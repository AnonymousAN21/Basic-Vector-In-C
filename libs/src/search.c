/*
 * MIT License
 * Copyright (c) 2026 Andrew Tangel
 * See LICENSE file in the project root for full license information.
 */
#include <stdio.h>
#include "../include/vector.h"
#include "search.h"

int linearSearch(vector* arr, int target){
    for(int i = 0; i < arr->length(arr) - 1; i++){
        int val = *(int*) arr->get(arr, i);
        if( val == target){
            printf("%d", val);
            return i;
        }
    }
    return -1;
}

int binarySearch(vector* arr, int target){
    int left = 0, right = arr->length(arr) - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        int current_val = *(int*) arr->get(arr, mid);
        if(current_val == target)return mid;
        else if(current_val < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
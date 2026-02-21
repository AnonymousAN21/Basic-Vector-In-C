#include "search.h"
#include "vector.h"
#include <stdio.h>
#include <time.h>

int compareInt(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

int main(){
    printf("Hello World!");
}
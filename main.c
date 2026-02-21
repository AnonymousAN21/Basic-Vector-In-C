#include "search.h"
#include "vector.h"
#include "queue.h"
#include <stdio.h>
#include <time.h>
#define N 5

void BFS(int graph[N][N], int start){
    queue q;
    Queue(&q, sizeof(int), N);

    bool visited[N] = {false};

    q.enqueue(&q, &start);
    visited[start] = true;

    while(!q.isEmpty(&q)){

        int current = *(int*)q.dequeue(&q);

        printf("%d ", current);

        for(int i = 0; i < N; i++){
            if(graph[current][i] == 1 && !visited[i]){
                visited[i] = true;
                q.enqueue(&q, &i);
            }
        }
    }

    q.clear(&q);
}
int compareInt(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if(x > y) return 1;
    if(x < y) return -1;
    return 0;
}

int main(){

    int graph[5][5] = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,0},
        {1,1,0,0,1},
        {0,1,0,1,0}
    };

    BFS(graph, 0);

    return 0;
}
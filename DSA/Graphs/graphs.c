#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 1000

typedef enum {FALSE, TRUE} Boolean;
typedef int Matrix[MAX][MAX];

int *Djikstra(Matrix M, int Start);

int main()
{
    Matrix myMatrix = {
        {INF, 10, INF, 30, 100},
        {INF, INF, 50, INF, INF},
        {20, INF, INF, INF, 10},
        {INF, INF, 20, INF, 60},
        {INF, INF, INF, INF, INF}
    };

    int *catcher = Djikstra(myMatrix, 0);

    int x;
    for (x = 0; x < MAX; ++x) {
        printf("[%d]", catcher[x]);
    }
    return 0;
}

int *Djikstra(Matrix M, int Start) {
    int *minArr = (int *)malloc(sizeof(int)*MAX);

    Boolean Visited[MAX] = {FALSE};
    Visited[Start] = TRUE;

    int x;
    for (x = (Start + 1) % MAX; x != Start; x = (x + 1) % MAX) {
        *(minArr + x) = M[Start][x];
    }

    int count, i, w, path = Start, trav = Start, min = 0;
    for (count = 0; count < MAX; ++count) {
        for (w = (path + 1) % MAX, trav = w; w != path; w = (w + 1) % MAX) {
            if (Visited[w] == FALSE) {
                trav = M[path][trav] >= M[path][w] ? w : trav;
            }
        }
        Visited[trav] = TRUE;
        min += M[path][trav];
        path = trav;

        //step 7
        for (i = 0; i < MAX; ++i) {
            minArr[i] = minArr[i] > (minArr[path] + M[path][i]) ? minArr[path] + M[path][i] : minArr[i];
        }
    }
    //end
    return minArr;
}

//
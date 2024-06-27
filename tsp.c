#include <stdio.h>

#define N 4
#define INF 99999

int tsp_g[N][N] = {
    {0, 15, 10, 20},
    {6, 0, 18, 12},
    {7, 14, 0, 28},
    {8, 24, 32, 0}
};

int visited[N] = {0};
int cost = 0;

void travelling_salesman(int start) {
    int i, j, k, min, next_city;

    visited[start] = 1;
    printf("Path: %d -> ", start + 1);

    j = start;
    for (i = 1; i < N; i++) {
        min = INF;

        for (k = 0; k < N; k++) {
            if (!visited[k] && tsp_g[j][k] && tsp_g[j][k] < min) {
                min = tsp_g[j][k];
                next_city = k;
            }
        }

        visited[next_city] = 1;
        printf("%d -> ", next_city + 1);
        cost += min;
        j = next_city;
    }

    cost += tsp_g[j][start];
    printf("%d\n", start + 1);
}

int main() {
    int start = 0;
    travelling_salesman(start);
    printf("Minimum cost: %d\n", cost);
    return 0;
}
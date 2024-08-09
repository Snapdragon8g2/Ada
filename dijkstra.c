#include <stdio.h>
#include <limits.h>

int cost[10][10], n, dist[10];

int minm(int m, int n) {
    return (m < n) ? m : n;
}

void dijkstra(int source) {
    int s[10] = {0};
    int min, w = 0;
    for (int i = 0; i < n; i++) {
        dist[i] = cost[source][i];
    }
    dist[source] = 0;
    s[source] = 1;
    for (int i = 0; i < n - 1; i++) {
        min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if ((s[j] == 0) && (min > dist[j])) {
                min = dist[j];
                w = j;
            }
        }
        s[w] = 1;
        for (int v = 0; v < n; v++) {
            if (s[v] == 0 && cost[w][v] != INT_MAX)
                dist[v] = minm(dist[v], dist[w] + cost[w][v]);
        }
    }
}

int main() {
    int source, i, j;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INT_MAX;
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("The shortest distances are:\n");
    for (int i = 0; i < n; i++) {
        printf("Cost from %d to %d is %d\n", source, i, dist[i]);
    }
    return 0;
}
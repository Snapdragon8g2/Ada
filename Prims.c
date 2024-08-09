#include <stdio.h>

int main() {
    int n, cost[10][10], visited[10] = {0}, min, mincost = 0, ne = 1;
    int a, b, u, v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are:\n");
    visited[1] = 1;

    while (ne < n) {
        min = 999;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min && (visited[i] != 0 || visited[j] != 0)) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("Edge %d(%d,%d) cost= %d\n", ne++, a, b, min);
            visited[b] = 1;
            mincost += min;
        }

        cost[b][a] = cost[a][b] = 999;
    }

    printf("The total cost of the MCST is = %d\n", mincost);

    return 0;
}
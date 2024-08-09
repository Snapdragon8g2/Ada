#include<stdio.h>

void wrshl(int n, int a[20][20]);

void main()
{
    int i, j, k, n, a[20][20];

    printf("Enter the no of vertices\n");
    scanf("%d", &n);

    printf("Enter the AM\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The transitive closure for the graph is\n");
    wrshl(n, a);
}

void wrshl(int n, int a[20][20])
{
    int i, j, k, m1[20][20], m2[20][20];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m1[i][j] = a[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                m2[i][j] = (m1[i][j] || (m1[i][k] && m1[k][j]));
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                m1[i][j] = m2[i][j];
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", m2[i][j]);
        }
        printf("\n");
    }
}
// done once
#include <stdio.h>

int allocation[5][3] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2},
};

int max[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {4, 2, 2},
    {5, 3, 3},
};
int visited[5] = {0};
int need[5][3];
int available[3] = {3, 3, 2};
int safeSequence[5]={0};
int count = 0;

void calculateNeed()
{
    for (int i = 0; i < 5; i++)    // i is the processes(P1,P2,P3) 
    {
        for (int j = 0; j < 3; j++)  // j is the resources(A,B,C)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int isSafe(int process)
{
    for (int j = 0; j < 3; j++)     // checking all 3 resources of P.
    {
        if (need[process][j] > available[j])
        {
            return 0;
        }
    }
    return 1;      // available is more than need..
}

void bankers()
{
    calculateNeed();
    while (count < 5)
    {
        int found = 0;
        for (int i = 0; i < 5; i++)       // i is the processes
        {
            if (visited[i] == 0 && isSafe(i) == 1)  // i no. of processes is being checked.
            {
                for (int j = 0; j < 3; j++)
                {
                    available[j] = available[j]+ allocation[i][j];
                }
                safeSequence[count++] = i;
                visited[i] = 1;
                found = 1;
                break;
            }
        }
        if (found==0)
        {
            printf("No safe sequence");
            return;
        }
    }

    //output
    printf("\nSafe sequence present: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
}

int main()
{
    bankers();
}






// #include <stdio.h>
// #include<stdlib.h>
// int main()
// {
//     int n, m;
//     printf("Enter the number of processes : ");
//     scanf("%d", &n);
//     printf("Enter the number of resources : ");
//     scanf("%d", &m);
//     int alloc[n][m], max[n][m], avail[m];
//     printf("Enter the details for processes\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nProcess P%d\nEnter allocated resources: ", i);
//         for (int j = 0; j < m; j++)
//         scanf("%d", &alloc[i][j]);
//         printf("Enter maximum requirements : ");
//         for (int j = 0; j < m; j++)
//         scanf("%d", &max[i][j]);
//     }
//     printf("\nEnter available resources : ");
//     for (int j = 0; j < m; j++)
//     scanf("%d", &avail[j]);
//     int v[n], ans[n], ind = 0;
//     for (int i = 0; i < n; i++)
//     v[i] = 0;
//     int need[n][m];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         need[i][j] = max[i][j] - alloc[i][j];
//     }
//     for (int k = 0; k < n; k++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (v[i] == 0)
//             {
//                 int flag = 0;
//                 for (int j = 0; j < m; j++)
//                 {
//                     if (need[i][j] > avail[j])
//                     {
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (flag == 0)
//                 {
//                     ans[ind++] = i;
//                     for (int j = 0; j < m; j++)
//                     avail[j] += alloc[i][j];
//                     v[i] = 1;
//                 }
//             }
//         }
//     }
//     int flag = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (v[i] == 0)
//         {
//             flag = 0;
//             printf("\nit will go in deadlock \n");
//             break;
//         }
//     }
//     if (flag == 1)
//     {
//         printf("\nFollowing is SAFE Sequence \n");
//         for (int i = 0; i < n; i++)
//         printf(" P%d ->", ans[i]);
//     }
// }

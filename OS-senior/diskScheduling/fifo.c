#include <stdio.h>
#include <stdlib.h>
void main()
{
    int st = 0, n, i, data[100];
    printf("Enter no. of tracks:- ");
    scanf("%d", &n);
    printf("enter head: ");
    scanf("%d", &data[0]);
    for (i = 1; i <= n; i++)
    {
        printf("Enter track %d: ", i);
        scanf("%d", &data[i]);
        st = st + abs(data[i] - data[i - 1]);
    }
    printf("seek time is: %d", st);
}


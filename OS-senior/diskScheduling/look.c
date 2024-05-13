//LOOK (same as scan but does not go till the end.) direction required.
#include <stdio.h>
void main()
{
    int st = 0, n, i, head, max = -1, least = 9999;
    int data[100];
    printf("Enter no. of tracks ");
    scanf("%d", &n);
    printf("enter head ");
    scanf("%d", &head);
    for (i = 0; i < n; i++)
    {
        printf("Enter track: %d ", i + 1);
        scanf("%d", &data[i]);
        if (data[i] > max)
            max = data[i];
        if (data[i] < least)
            least = data[i];
    }
    st = max - head + max - least;   //derived from the sum itself.
    printf("seek time is %d", st);
}

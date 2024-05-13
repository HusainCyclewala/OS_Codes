// CLOOK (go till the largest disk, then till least without disking, then do remaining 
// disks ) Direction REQD.
#include <stdio.h>
void main()
{
    int highestBeforeHead = -1, st = 0, n, i, head, max = -1, least = 9999;
    int data[100];
    printf("Enter no. of tracks ");
    scanf("%d", &n);
    printf("enter head ");
    scanf("%d", &head);
    for (i = 0; i < n; i++)
    {
        printf("Enter track%d ", i + 1);
        scanf("%d", &data[i]);
        if (data[i] < head)
        {
            if (data[i] > highestBeforeHead)
                highestBeforeHead = data[i];
        }
        if (data[i] > max)
            max = data[i];
        if (data[i] < least)
            least = data[i];
    }
    st = max - head + max - least + highestBeforeHead - least;
    printf("seek time is %d", st);
}

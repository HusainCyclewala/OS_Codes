// CSCAN(elevate into first direction then into the opposite extreme w/o doing 
// any disks, then do the remaaining disks) Direction REQD.
#include <stdio.h>
void main()
{
    int hl, ll, highestBeforeHead = -1, st = 0, n, i, head;
    int data[200];
    printf("Enter lower and higher limit ");
    scanf("%d %d", &ll, &hl);
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
    }
    st = hl - head + hl - ll + highestBeforeHead - ll;
    printf("seek time is %d", st);
}

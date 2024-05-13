// SCAN(ELEVATOR), move to the complete end of given direction.
#include <stdio.h>
void main()
{
    int hl, ll, least = 9999, st = 0, n, i, head;
    int data[200];
    printf("Enter lower and higher limit ");
    scanf("%d %d", &ll, &hl);
    printf("Enter no. of tracks ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter track %d ", i + 1);
        scanf("%d", &data[i]);
        if (data[i] < least)
            least = data[i];
    }
    printf("enter head ");
    scanf("%d", &head);
    st = hl - head + hl - least; // derived from the actual sum(199-50)+(199-16)=332
    printf("seek time is %d", st);
}

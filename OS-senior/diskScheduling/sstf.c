// SHORTEST SEEK TIME FIRST.(closest to current head first)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int head;
    int data[100], v[100], prev[100], diff;
    //ct=counter,mindInd= holds index of tarck with the samllest diff.
    //curr= current position of head.
    int hl, ll, n, i, least, ct = 0, st = 0, curr, minInd;
    printf("Enter lower and higher limit: ");
    scanf("%d %d", &ll, &hl);
    printf("Enter no. of tracks: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter track %d :", i + 1);
        scanf("%d", &data[i]);
    }
    printf("enter head ");
    scanf("%d", &head);
    for (i = 0; i < n; i++){
        v[i] = 0;
    }
    //algorithm start
    // Inside the loop, it finds the track with the smallest difference from the current head position(closest to head) that has not been visited yet.
    
    curr = head;
    while (ct < n)   //while counter is less than n.
    {
        int least = 9999;
        for (i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                diff = abs(curr - data[i]);  //head minus the value.
                if (diff < least)
                {
                    least = diff; //update least
                    minInd = i;   //update min index
                }
            }
        }  //for loop end.
        st =st + least;
        curr = data[minInd];  //Updates the current head position and calculates the seek time.
        v[minInd] = 1;
        ct++;
    }

    printf("Seek time is %d ", st);
}


// curr= head;
// while (counter < n)
// {
//     int least = 9999;
//     for(i=0; i<n; i++)
//     {
//         if(v[i]==0)
//         {
//             diff = abs(curr - data[i]);
//             if(diff<least)
//             {
//                 least = diff;
//                 minInd = i;
//             }
//         }
//     }

//     seekT= seekT + least;
//     curr = data[minInd];
//     v[minInd] = 1;
//     counter++;
// }
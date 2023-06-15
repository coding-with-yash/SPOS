#include<stdio.h>

int main()
{
    int i, j, n, ref_str[50], frame[10], no, k, avail, fcount = 0;

    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &n);

    printf("\n ENTER THE PAGE NUMBER:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &ref_str[i]);

    printf("\n ENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        frame[i] = -1;

    j = 0;

    printf("\nRef String\tPage Frames\tHit/Fault\n");
    
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", ref_str[i]);
        avail = 0;

        for (k = 0; k < no; k++)
        {
            if (frame[k] == ref_str[i])
            {
                avail = 1;

                for (k = 0; k < no; k++)
                    printf("%d\t", frame[k]);

                printf("H");
            }
        }

        if (avail == 0)
        {
            frame[j] = ref_str[i];
            j = (j + 1) % no;
            fcount++;

            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);

            printf("F");
        }

        printf("\n");
    }

    printf("Page Fault Is %d", fcount);

    return 0;
}








ENTER THE NUMBER OF PAGES: 20

ENTER THE PAGE NUMBER : 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

 ENTER THE NUMBER OF FRAMES :3

 ref string      page frames            Hit/Fault
7               7       -1      -1      F
0               7       0       -1      F
1               7       0       1       F
2               2       0       1       F
0               2       0       1       H
3               2       3       1       F
0               2       3       0       F
4               4       3       0       F
2               4       2       0       F
3               4       2       3       F
0               0       2       3       F
3               0       2       3       H
2               0       2       3       H
1               0       1       3       F
2               0       1       2       F
0               0       1       2       H
1               0       1       2       H
7               7       1       2       F
0               7       0       2       F
1               7       0       1       F
Page Fault Is 15

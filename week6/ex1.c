#include <stdio.h>

double avg_TAT, avg_WT = 0;

int main()
{
    int mem;
    scanf("%d", &mem);

    int all_proc[mem][5];

    int BT = 0;
    int AT = 1;
    int CT = 2;
    int WT = 3;
    int TAT = 4;

    for (int i = 0; i < mem; i++)
    {
        scanf("%d", &all_proc[i][AT]);
        scanf("%d", &all_proc[i][BT]);
    }

    int time = 0;

    for (int i = 0; i < mem; i++)
    {
        if (time < all_proc[i][AT])
            time = all_proc[i][AT];
        all_proc[i][WT] = time - all_proc[i][AT];
        time = time + all_proc[i][BT];
        all_proc[i][CT] = time;
        all_proc[i][TAT] = all_proc[i][WT] + all_proc[i][BT];

        printf("Process %d: CT %d, WT %d, TAT %d\n", i + 1, all_proc[i][CT], all_proc[i][WT], all_proc[i][TAT]);
    }

    for (int i = 0; i < mem; i++)
    {
        avg_WT = avg_WT + all_proc[i][WT];
        avg_TAT = avg_TAT + all_proc[i][TAT];
    }

    avg_TAT = avg_TAT / mem;
    avg_WT = avg_WT / mem;

    printf("general time = %d\n", time);
    printf("average turn around time = %lf\n", avg_TAT);
    printf("average waiting time = %lf", avg_WT);

    return 0;
}

/*
3
1 3
2 4
3 5
Process 1: CT 4, WT 0, TAT 3
Process 2: CT 8, WT 2, TAT 6
Process 3: CT 13, WT 5, TAT 10
general time = 13
average turn around time = 6.333333
average waiting time = 2.333333
*/
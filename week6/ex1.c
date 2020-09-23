#include <stdio.h>
#define count 5

struct Process
{
    int BT, AT, CT, WT, TAT;
};

struct Process all_proc[count];

double avg_TAT, avg_WT = 0;

int main() {

    printf("Input format: for every of %d processes write 2 numbers - arrival time and burst time\n", count);

    for (int i = 1; i <= count; i++)
    {
        scanf("%d", &all_proc[i].AT);
        scanf("%d", &all_proc[i].BT);
    }

    int time = 0;

    for (int i = 1; i <= count; i++)
    {
        if (time < all_proc[i].AT)
            time = all_proc[i].AT;
        all_proc[i].WT = time - all_proc[i].AT;
        time = time + all_proc[i].BT;
        all_proc[i].CT = time;
        all_proc[i].TAT = all_proc[i].WT + all_proc[i].BT;

        printf("Process %d: CT %d, WT %d, TAT %d\n", i, all_proc[i].CT, all_proc[i].WT, all_proc[i].TAT);
    }

    for (int i = 1; i <= count; i++)
    {
        avg_WT = avg_WT + all_proc[i].WT;
        avg_TAT = avg_TAT + all_proc[i].TAT;
    }

    avg_TAT = avg_TAT / count;
    avg_WT = avg_WT / count;

    printf("general time = %d\n", time);
    printf("average turn around time = %lf\n", avg_TAT);
    printf("average waiting time = %lf", avg_WT);

    return 0;
}

/*
Input format: for every of 5 processes write 2 numbers - arrival time and burst time
1 2
2 4
3 2
4 1
5 1
Process 1: CT 3, WT 0, TAT 2
Process 2: CT 7, WT 1, TAT 5
Process 3: CT 9, WT 4, TAT 6
Process 4: CT 10, WT 5, TAT 6
Process 5: CT 11, WT 5, TAT 6
general time = 11
average turn around time = 5.000000
average waiting time = 3.000000
*/
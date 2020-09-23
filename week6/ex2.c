#include <stdio.h>
#define count 3

struct Process
{
    int place, AT, BT, CT, TAT, WT;
};

void Sort(int first, int last, struct Process* a)
{
    struct Process temp;
    for (int i = first + 1; i < last + 1; i++) {
        for (int j = first + 1; j < last + 1; j++) {
            if (a[j].BT < a[j - 1].BT)
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

struct Process all_proc[count];
struct Process all_proc_cur[count];

double avg_TAT, avg_WT = 0;

int main()
{

    int time, num = 0;
    int AT_last = -1;

    printf("Input format: for every of %d processes write 2 numbers - arrival time and burst time\n", count);

    for (int i = 1; i <= count; i++)
    {
        all_proc[i].place = i;
        scanf("%d", &all_proc[i].AT);
        scanf("%d", &all_proc[i].BT);
    }

    for (int i = 1; i <= count; i++)
    {
        if (all_proc[i].AT != AT_last && all_proc[i].AT <= time)
        {
            num = i;
            AT_last = all_proc[i].AT;

            while (all_proc[num].AT <= AT_last && num != count)
            {num++;}
            num--;
        }

        else if(all_proc[i].AT > time)
        {
            time = all_proc[i].AT;
            i--;
            continue;
        }

        Sort(i, num, all_proc);

        all_proc[i].WT = time - all_proc[i].AT;
        time = time + all_proc[i].BT;
        all_proc[i].CT = time;
        all_proc[i].TAT = all_proc[i].WT + all_proc[i].BT;

        printf("Process %d: CT %d, WT %d, TAT %d\n", i, all_proc[i].CT, all_proc[i].WT, all_proc[i].TAT);
    }

    for (int i = 1; i <= count; i++)
    {
        avg_TAT = avg_TAT + all_proc[i].TAT;
        avg_WT = avg_WT + all_proc[i].WT;
    }

    avg_TAT = avg_TAT / count;
    avg_WT = avg_WT / count;

    printf("general time = %d\n", time);
    printf("average turn around time = %lf\n", avg_TAT);
    printf("average waiting time = %lf", avg_WT);

    return 0;
}

/*
Input format: for every of 3 processes write 2 numbers - arrival time and burst time
1 3
2 6
3 1
Process 1: CT 4, WT 0, TAT 3
Process 2: CT 10, WT 2, TAT 8
Process 3: CT 11, WT 7, TAT 8
general time = 11
average turn around time = 6.333333
average waiting time = 3.000000
 */
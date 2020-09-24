#include <stdio.h>

void Sort(int first, int last, int a[][6])
{
    int temp;
    for (int i = first + 1; i < last + 1; i++)
    {
        for (int j = first + 1; j < last + 1; j++)
        {
            if (a[j][0] < a[j - 1][0])
            {
                for(int ind = 0; ind < 6; ind++)
                {
                    temp = a[j][ind];
                    a[j][ind] = a[j - 1][ind];
                    a[j - 1][ind] = temp;
                }
            }
        }
    }
}

double avg_TAT, avg_WT = 0;

int main()
{
    int mem;
    scanf("%d", &mem);

    int all_proc[mem][6];

    int BT = 0;
    int AT = 1;
    int CT = 2;
    int WT = 3;
    int TAT = 4;
    int place = 5;

    int time, num = 0;
    int AT_last = -1;


    for (int i = 0; i < mem; i++)
    {
        all_proc[i][place] = i;
        scanf("%d", &all_proc[i][AT]);
        scanf("%d", &all_proc[i][BT]);
    }

    for (int i = 0; i < mem; i++)
    {
        if (all_proc[i][AT] != AT_last && all_proc[i][AT] <= time)
        {
            num = i;
            AT_last = all_proc[i][AT];

            while (all_proc[num][AT] <= AT_last && num != mem)
            {num++;}
            num--;
        }

        else if(all_proc[i][AT] > time)
        {
            time = all_proc[i][AT];
            i--;
            continue;
        }

        Sort(i, num, all_proc);

        all_proc[i][WT] = time - all_proc[i][AT];
        time = time + all_proc[i][BT];
        all_proc[i][CT] = time;
        all_proc[i][TAT] = all_proc[i][WT] + all_proc[i][BT];

        printf("Process %d: CT %d, WT %d, TAT %d\n", i, all_proc[i][CT], all_proc[i][WT], all_proc[i][TAT]);
    }

    for (int i = 0; i < mem; i++)
    {
        avg_TAT = avg_TAT + all_proc[i][TAT];
        avg_WT = avg_WT + all_proc[i][WT];
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
1 1
2 3
1 2
Process 0: CT 2, WT 0, TAT 1
Process 1: CT 4, WT 1, TAT 3
Process 2: CT 7, WT 2, TAT 5
general time = 7
average turn around time = 3.000000
average waiting time = 1.000000
 */
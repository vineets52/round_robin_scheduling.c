#include<stdio.h>
 
int main()
{
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, arrival[10], burst[10], temp[10];
    float avg_wait_time, avg_turnaround_time;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &limit);
    x = limit;

    for(i = 0; i < limit; i++)
    {
        printf("Enter Details of Process[%d]\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Burst Time: ");
        scanf("%d", &burst[i]);
        temp[i] = burst[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
            x--;
            printf("Process[%d]\t%d\t%d\t%d\n", i + 1, burst[i], total - arrival[i], total - arrival[i] - burst[i]);
            wait_time = wait_time + total - arrival[i] - burst[i];
            turnaround_time = turnaround_time + total - arrival[i];
            counter = 0;
        }
        if(i == limit - 1)
        {
            i = 0;
        }
        else if(arrival[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_wait_time = (float)wait_time / limit;
    avg_turnaround_time = (float)turnaround_time / limit;

    printf("\nAverage Waiting Time: %f", avg_wait_time);
    printf("\nAverage Turnaround Time: %f\n", avg_turnaround_time);

    return 0;
}

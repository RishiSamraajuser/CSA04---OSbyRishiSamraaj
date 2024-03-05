#include <stdio.h>

struct priority_scheduling
{
    char process_name;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int priority;
};

int main()
{
    int num_of_process;
    int total = 0;
    struct priority_scheduling temp_process;

    // Correcting the variable name to ASCII_num
    int ASCII_num = 65;

    int pos;
    float avg_wt;
    float avg_tat;

    printf("Enter the total no. of processes: ");
    scanf("%d", &num_of_process);

    struct priority_scheduling process[num_of_process];

    printf("\nPlease enter the burst time and priority of each process: ");
    for (int i = 0; i < num_of_process; i++)
    {
        process[i].process_name = (char)ASCII_num;
        printf("\nEnter the details of the process %c \n", process[i].process_name);
        printf("Enter the burst time: "); // Correcting the prompt
        scanf("%d", &process[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &process[i].priority);
        ASCII_num++;
    }

    // Correcting the loop condition and swapping logic
    for (int i = 0; i < num_of_process; i++)
    {
        pos = i;
        for (int j = i + 1; j < num_of_process; j++)
        {
            if (process[j].priority > process[pos].priority)
            {
                pos = j;
            }
        }
        temp_process = process[i];
        process[i] = process[pos];
        process[pos] = temp_process;
    }

    // Correcting the loop condition and calculation of waiting time
    process[0].waiting_time = 0;
    for (int i = 1; i < num_of_process; i++)
    {
        process[i].waiting_time = 0;
        for (int j = 0; j < i; j++)
        {
            process[i].waiting_time += process[j].burst_time;
        }
        total += process[i].waiting_time;
    }

    avg_wt = (float)total / (float)num_of_process;
    total = 0;

    printf("\n\n Process_name \t Burst time \t Waiting time \t TurnAround Time \n");
    printf("----------------------------------------------------------------\n");

    // Correcting the variable name in the loop
    for (int i = 0; i < num_of_process; i++)
    {
        process[i].turn_around_time = process[i].burst_time + process[i].waiting_time;
        total += process[i].turn_around_time;
        printf("\t %c \t\t %d \t\t %d \t\t %d", process[i].process_name, process[i].burst_time, process[i].waiting_time, process[i].turn_around_time);
        printf("\n-----------------------------------------------------------\n");
    }

    avg_tat = (float)total / (float)num_of_process;
    printf("\n\n Avg. Waiting Time is:- %f", avg_wt);
    printf("\n Avg. TurnAround Time is:- %f", avg_tat);

    return 0;
}

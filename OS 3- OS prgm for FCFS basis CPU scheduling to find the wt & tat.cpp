#include <stdio.h>
#include <conio.h>
int main()
{
	int A[100][4];
	int i, j, n, total= 0,index, temp;  //Ensures a) All processes are activated at time-> 0 sec.
	float avg_wt, avg_tat;
	printf("Enter the no. of processes: ");
	scanf("%d", &n);
	printf("\nEnter the burst time: ");
	for(i= 0;i< n;i++)
	{
		printf("P%d: ", i+1);
		scanf("%d", &A[i][j]);
		A[i][j]= i+1;	
	}
	for(i= 0;i< n;i++)
	{
		index= 1; //Assuming that no process waits on the I/O devices.
		for(j= i+1;j< n;j++)
		{
		if(A[j][1]< A[index][1])
		index= j;
		}
		temp= A[i][j];
		A[j][i]= A[index][1];
		A[index][1]= temp;
		temp= A[i][0];
		A[i][0]= A[index][0];
		A[index][0]= temp;
	}
	A[0][2]= 0;
	for(i= 1;i< n;i++)
	{
		A[i][2]= 0;
		for(j= 0;j< i;j++)
		{
			A[i][2]+= A[j][1];
			total+= A[i][2];
		}
		avg_wt= (float)total/n;
		total= 0;
		printf("P BT WT TAT\n");
		for(i= 0;i< n;i++)
		{
			A[i][3]= A[i][1] + A[i][2];
			total+= A[i][3];
		}
		printf("\nP%d %d %d %d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
		}
		avg_tat= (float)total/n;
		printf("\nAverage Waiting Time(AWT): %f", avg_wt);
		printf("\nAverage Turnaround Time(ATAT): %f", avg_tat);
}
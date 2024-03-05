#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *myThreadFun(void *vargp)
{
 sleep(1);
 printf("Printing My name from Thread: \n");
 return NULL;
}
int main()
{
	char m[100];
	pthread_t thread_id;
	printf("Before Thread: \n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread: \n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	exit(0);
}
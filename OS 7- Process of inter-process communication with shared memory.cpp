#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main() {
  int i;
  void *shared_memory;
  char buff[100];
  int shmid;

  // Create a shared memory segment
  shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
  if (shmid == -1) {
    printf("shmget failed\n");
    exit(1);
  }

  // Attach the shared memory segment to the process
  shared_memory = shmat(shmid, NULL, 0);
  if (shared_memory == (void *)-1) {
    printf("shmat failed\n");
    exit(1);
  }

  // Write some data to the shared memory segment
  strcpy(buff, "Hello, world!");
  memcpy(shared_memory, buff, strlen(buff));

  // Detach the shared memory segment from the process
  shmdt(shared_memory);

  // Destroy the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
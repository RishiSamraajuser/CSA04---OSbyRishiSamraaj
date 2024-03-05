#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 6

pthread_mutex_t chopstick[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];
sem_t mutex;

void *philosopher(void *arg) {
    int id = *((int *)arg);
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Think
        printf("Philosopher %d is thinking\n", id);
        sleep(rand() % 3);

        // Pick up chopsticks
        sem_wait(&mutex);
        pthread_mutex_lock(&chopstick[left]);
        pthread_mutex_lock(&chopstick[right]);
        sem_post(&mutex);

        // Eat
        printf("Philosopher %d is eating\n", id);
        sleep(rand() % 3);

        // Put down chopsticks
        pthread_mutex_unlock(&chopstick[left]);
        pthread_mutex_unlock(&chopstick[right]);
    }
}

int main() {
    int i;
    int philo_id[NUM_PHILOSOPHERS];

    // Initialize semaphores and mutex
    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    // Create philosopher threads
    for (i = 1; i < NUM_PHILOSOPHERS; i++) {
        philo_id[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philo_id[i]);
    }

    // Join philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Cleanup
    sem_destroy(&mutex);
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}

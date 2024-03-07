#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

sem_t mutex, empty, full;
int buffer[BUFFER_SIZE];
int in = 0, out = 0, item= 5;

void *producer(void *arg) {
    while (1) {
        // Produce item
        // ...

        sem_wait(&empty);    // Wait if the buffer is full
        sem_wait(&mutex);    // Enter critical section

        // Add item to buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);    // Exit critical section
        sem_post(&full);     // Signal that buffer is not empty
    }
}

void *consumer(void *arg) {
    while (1) {
        sem_wait(&full);     // Wait if the buffer is empty
        sem_wait(&mutex);    // Enter critical section

        // Remove item from buffer
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);    // Exit critical section
        sem_post(&empty);    // Signal that buffer is not full

        // Consume item
        // ...
    }
}

int main() {
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for threads to finish (note: this is an infinite loop, so threads won't finish)
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

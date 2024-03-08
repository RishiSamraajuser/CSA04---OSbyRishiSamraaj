#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int shared_variable = 0;

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);

    // Critical Section: Accessing shared_variable
    pthread_mutex_lock(&mutex);
    printf("Thread %d enters critical section.\n", thread_id);
    shared_variable++;
    printf("Thread %d modifies shared_variable to %d.\n", thread_id, shared_variable);
    printf("Thread %d leaves critical section.\n", thread_id);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

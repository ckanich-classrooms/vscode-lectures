// bounded buffer adapted from
// https://www.csl.mtu.edu/cs4411.ck/www/NOTES/threads/buffer-2.html
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define SIZE 10
static int buffer[SIZE];
static int first_empty_slot;
static int last_filled_slot;
static int count;

static pthread_mutex_t peek;

static pthread_cond_t not_full;
static pthread_cond_t not_empty;

int consume(void)
{
    int value;

    pthread_mutex_lock(&peek);
    while (count == 0)
        pthread_cond_wait(&not_empty, &peek);
    value = buffer[last_filled_slot];
    last_filled_slot = (last_filled_slot + 1) % SIZE;
    count--;
    pthread_cond_signal(&not_full);
    pthread_mutex_unlock(&peek);
    return value;
}

int produce(int value)
{
    pthread_mutex_lock(&peek);
    while (count == SIZE)
        pthread_cond_wait(&not_full, &peek);
    buffer[first_empty_slot] = value;
    first_empty_slot = (first_empty_slot + 1) % SIZE;
    count++;
    pthread_cond_signal(&not_empty);
    pthread_mutex_unlock(&peek);
    return value;
}

int main()
{
    first_empty_slot = last_filled_slot = count = 0;

    pthread_mutex_init(&peek, NULL);

    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    // produce and consume in your bounded buffer!
}
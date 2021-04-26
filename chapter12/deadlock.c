#include <pthread.h>
#include <stdio.h>

pthread_mutex_t x, y;

void *jack(void *dontcare)
{
    while (1)
    {
        pthread_mutex_lock(&x);
        pthread_mutex_lock(&y);
        printf("jack!\n");
        pthread_mutex_unlock(&x);
        pthread_mutex_unlock(&y);
    }
    return NULL;
}

void *jill(void *dontcare)
{
    while (1)
    {
        pthread_mutex_lock(&y);
        pthread_mutex_lock(&x);
        printf("jill!\n");
        pthread_mutex_unlock(&x);
        pthread_mutex_unlock(&y);
    }
    return NULL;
}
int main()
{
    pthread_t jack_t, jill_t;
    pthread_mutex_init(&x, NULL);
    pthread_mutex_init(&y, NULL);
    pthread_create(&jack_t, NULL, jack, NULL);
    pthread_create(&jill_t, NULL, jill, NULL);
    pthread_join(jack_t,NULL);
    pthread_join(jill_t,NULL);
    return 0;
}
    
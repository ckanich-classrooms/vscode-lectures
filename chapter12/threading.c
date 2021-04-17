#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *withdraw_cash(void *amount);
void *deposit_cash(void *amount);
int my_balance = 100;

int get_balance()
{
    // pretend this is a database call that takes a bit of time
    usleep(250000); // 250ms
    return my_balance;
}

void set_balance(int new_balance)
{
    // pretend this is a database call that takes a bit of time
    usleep(250000); // 250ms
    my_balance = new_balance;
    return;
}

int main()
{
    pthread_t thread1, thread2;
    int withdraw_amount = 10;
    int deposit_amount = 10;
    int create_result;

    /* Create independent threads each of which will execute function */
    create_result = pthread_create(&thread1, NULL, withdraw_cash, &withdraw_amount);
    if (create_result != 0)
    {
        printf("pthread_create failed: %s\n", strerror(create_result));
        return 0;
    }

    create_result = pthread_create(&thread2, NULL, deposit_cash, &deposit_amount);
    if (create_result != 0)
    {
        printf("pthread_create failed: %s\n", strerror(create_result));
        return 0;
    }

    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("my balance is now %d\n", my_balance);

    return 0;
}

void *deposit_cash(void *amount)
{
    int balance = get_balance();
    printf("%lu: I am about to add %d to the balance of %d\n", pthread_self(), *(int *)amount, balance);
    balance += *(int *)amount;
    set_balance(balance);
    printf("%lu: just stored my new balance of %d\n", pthread_self(), balance);
    return NULL;
}

void *withdraw_cash(void *amount)
{
    int balance = get_balance();
    printf("%lu: I am about to subtract %d to the balance of %d\n", pthread_self(), *(int *)amount, balance);
    balance -= *(int *)amount;
    set_balance(balance);
    printf("%lu: just stored my new balance of %d\n", pthread_self(), balance);
    return NULL;
}

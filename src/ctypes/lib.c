#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

atomic_int atomic_counter;
int non_atomic_counter;

int mythreads(void *thr_data)
{
    int c = *(int *)thr_data;
    for(int n = 0; n<c; ++n) {
        ++non_atomic_counter;
        ++atomic_counter;
    }
    return 0;
}

int start_thread(int* counter) {
    thrd_t thr[10];
    for(int n=0; n<10; ++n) {
        thrd_create(&thr[n], mythreads, (void *)counter);
    }
    for(int n=0; n<10; ++n) {
        thrd_join(thr[n], NULL);
    }
    printf("atomic_counter %d\n", atomic_counter);
    printf("counter %d\n", non_atomic_counter);

    *counter = 5;

    return 0;
}
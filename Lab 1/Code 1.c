#include <omp.h>
#include <stdio.h>
//printing the thread ID
int main() 
{
    #pragma omp parallel
    {
        printf("Thread id is %d\n", omp_get_thread_num());
    }
} 

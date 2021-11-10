#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    MPI_Init(&argc, &argv);

    int gsize;
    int root = 0, myrank, *rbuf;
    int data[10];
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == root)
    {
        MPI_Comm_size(MPI_COMM_WORLD, &gsize);
        rbuf = (int *)malloc(gsize * 1 * sizeof(int));
        // MPI_Gather(&sendarray, 100, MPI_INT, rbuf, 100, MPI_INT, root, MPI_COMM_WORLD);
        // printf("Final buffer size : %d\n", gsize * 1);
        // printf("Final Buffer Array Value :  ");
        // for (int i = 0; i < gsize * 1; i++)
        // {
        //     printf(" %d ", rbuf[i]);
        // }
        // printf("\n");
        printf("I am the master");
    }
    else
    {
        int random = rand() % 100 + 1;
        printf("%d\n", random);
        MPI_Gather(&data, 1, MPI_INT, NULL, random, MPI_INT, root, MPI_COMM_WORLD);
        printf("I am the slave");
    }
    MPI_Finalize();
    return (0);
}
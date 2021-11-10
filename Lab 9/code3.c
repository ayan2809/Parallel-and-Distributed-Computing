#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{

    MPI_Init(&argc, &argv);
    int rank;
    int wsize;
    int N = 10, H = 5;
    int num, k, i;
    int locarr[25];
    int bigList[300];
    srand(time(NULL));

    if (argc > 1)
    {
        N = atoi(argv[1]);
        H = atoi(argv[2]);
    }

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &wsize);

    if (rank == 0)
    {
        MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&H, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(&H, 1, MPI_INT, 0, MPI_COMM_WORLD);
        for (i = 0; i < N; i++)
        {
            locarr[i] = (((rand() % H) + 1) / rank);
            printf("RANK: %d  ---  NUM: %d\n", rank, locarr[i]);
        }
    }

    MPI_Gather(&locarr, N, MPI_INT, bigList, N, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("BigList: ");
        for (k = N; k < wsize * N; k++)
        {
            printf(" %d", bigList[k]);
        }
        printf("\n");
    }

    MPI_Finalize();

    return 0;
}
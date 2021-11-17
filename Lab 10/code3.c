#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    int rank;
    int c0, c1, c2, c3, m = 5;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        MPI_Recv(&c0, 1, MPI_INT, 1, 3, MPI_COMM_WORLD, &status);
        MPI_Recv(&c1, 1, MPI_INT, 2, 3, MPI_COMM_WORLD, &status);
        MPI_Recv(&c2, 1, MPI_INT, 3, 3, MPI_COMM_WORLD, &status);
        MPI_Recv(&c3, 1, MPI_INT, 4, 3, MPI_COMM_WORLD, &status);

        int i = 1;
        int numbers[4] = {c0, c1, c2, c3};
        int ans = numbers[0];
        for (i; i < 4; i++)
        {
            ans += numbers[i];
        }
        ans /= 4;
        printf("The final Average number is: %d\n", ans);
    }
    if (rank == 1)
    {
        int a1[5] = {1, 2, 3, 4, 5};
        c0 = a1[0];
        for (int i = 1; i < m; i++)
        {
            c0 += a1[i];
        }

        c0 /= 5;
        printf("Rank %d Sum Average: %d\n", rank, c0);

        MPI_Send(&c0, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);
    }
    if (rank == 2)
    {

        int a2[5] = {6, 7, 8, 9, 10};
        c1 = a2[0];
        for (int i = 1; i < m; i++)
        {
            c1 += a2[i];
        }
        c1 /= 5;
        printf("Rank %d Sum Average: %d\n", rank, c1);
        MPI_Send(&c1, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);
    }
    if (rank == 3)
    {

        int a3[5] = {11, 12, 13, 14, 15};
        c2 = a3[0];
        for (int i = 1; i < m; i++)
        {
            c2 += a3[i];
        }
        c2 /= 5;
        printf("Rank %d Sum Average: %d\n", rank, c2);
        MPI_Send(&c2, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);
    }
    if (rank == 4)
    {

        int a4[5] = {16, 17, 18, 19, 20};
        c3 = a4[0];
        for (int i = 1; i < m; i++)
        {
            c3 += a4[i];
        }
        c3 /= 5;

        printf("Rank %d Sum Average: %d\n", rank, c3);
        MPI_Send(&c3, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}
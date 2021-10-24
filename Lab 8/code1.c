#include<stdio.h>
#include<mpi.h>
#include<time.h>
int main(void)
{
  int p, id, data;
  double time;
  clock_t t;
  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  if(id == 0)
  time = MPI_Wtime();
  MPI_Bcast(&data , 1, MPI_INT, 0, MPI_COMM_WORLD);
  if(id == 0)
  {
    time = MPI_Wtime() - time;
    printf("\nTime taken for a simple broadcast %f \n", time);
  }
  MPI_Finalize();
}

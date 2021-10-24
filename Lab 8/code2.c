#include<stdio.h>
#include<mpi.h>

int main(void)
{
  int p, id, data = 2;
  double time;
  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  if(id == 0)
  {
    time = MPI_Wtime();
    for(int i = 0; i<p; i++)
    {
      data = data + (i)*2;
      MPI_Send(&data, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
  }
  else 
  {
    MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  if(id == 0)
  {
    time = MPI_Wtime()-time;
    printf("\nTime taken for blocked implementationon %f\n", time);
  }
  printf("The value of data in %d th process is %d\n", id+1, data);
  MPI_Finalize();
}

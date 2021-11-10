#include <stdio.h>
#include <mpi.h>

int main(void)
{
  int p, id, left, right;
  int buffer[10], buffer2[10];
  MPI_Request request, request2;
  MPI_Status status;
  double time;
  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &p);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  right = (id + 1) % p;
  left = id - 1;
  if (left < 0)
    left = p - 1;
  MPI_Irecv(buffer, 10, MPI_INT, left, 123, MPI_COMM_WORLD, &request);
  MPI_Isend(buffer2, 10, MPI_INT, right, 123, MPI_COMM_WORLD, &request2);
  MPI_Wait(&request, &status);
  MPI_Wait(&request2, &status);


  MPI_Finalize();
  return 0;
}

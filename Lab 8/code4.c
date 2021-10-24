#include<stdio.h>
#include<mpi.h>

void my_bcast(void *data, int count, MPI_Datatype datatype, int root, MPI_Comm communicator)
{
  int world_rank;
  MPI_Comm_rank(communicator, &world_rank);
  int world_size;
  MPI_Comm_size(communicator, &world_size);
  
  if(world_rank == root)
  {
    for(int i = 0; i< world_size; i++)
    {
      if(i != world_rank)
      {
        MPI_Send(data, count, datatype, i, 0, communicator);
      }
    }
  }
  else 
  {
    MPI_Recv(data, count, datatype, root, 0, communicator, MPI_STATUS_IGNORE);
  }
}

int main(void)
{
  int p, id, data = 5;
  double total_my_bcast_time, total_mpi_bcast_time;
  int n=5;
  double avg_bcast = 0, avg_mpi =0;
  MPI_Init(NULL,NULL);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  for( int i = 0; i< n; i++)
  {
    MPI_Barrier(MPI_COMM_WORLD);
    total_my_bcast_time = MPI_Wtime();
    my_bcast(&data, 1 ,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    total_my_bcast_time= MPI_Wtime() - total_my_bcast_time;
    
    MPI_Barrier(MPI_COMM_WORLD);
    total_mpi_bcast_time = MPI_Wtime();
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    total_mpi_bcast_time = MPI_Wtime() - total_mpi_bcast_time;
    if (id == 0){
      printf("Total time for the %dth iteration of my_bcast function is %f\n", i, total_my_bcast_time);
      printf("Total time for the %dth iteration of inbuilt function is %f\n", i, total_mpi_bcast_time);
      avg_bcast = avg_bcast + total_my_bcast_time;
      avg_mpi = avg_mpi + total_mpi_bcast_time;
    }
  }
  if(id == 0)
  {
    avg_bcast = avg_bcast/n;
    avg_mpi = avg_mpi/n;
    printf("Average time for the my_bcast function is %f\n", avg_bcast);
    printf("Average time for the inbuilt function is %f\n", avg_mpi);
  }
  MPI_Finalize();
}

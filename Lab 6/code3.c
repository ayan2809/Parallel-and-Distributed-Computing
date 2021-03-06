#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) 
{
    // Initializing the MPI environment
    MPI_Init(NULL, NULL);

    // Getting the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Getting the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Getting the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Printing my name only for the the odd ranked processors
    if(world_rank%2!=0)
        printf("Hello world Ayan Sadhukhan from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalizing the MPI environment.
    MPI_Finalize();
}
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <mpi.h>
#include <unistd.h>

int main(int argc, char** argv) {

	int my_rank; 
	int size; 
	int source; 
	int dest; 
	int tag = 50; 
	char message[100]; 
    int y=56;
	MPI_Status status; 
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size); 

	dest = rand() % ((size-1)+1);

	if (my_rank == 0) 
    {
        int x=50;
		MPI_Send(&x, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
        
	} 
	
	if (my_rank == dest) source = 0;
	if (my_rank != dest) source = my_rank-1;
	
        MPI_Recv(&y, 1, MPI_INT,source, tag, MPI_COMM_WORLD, &status);
        printf("Rank %d => Variable Obtained :<< %d >>\n",my_rank,  y);
        sleep (3);
        y=45;
        MPI_Send(&y, 1, MPI_INT, (my_rank+1)%size, tag, MPI_COMM_WORLD);
 	
	MPI_Finalize();

return 0;
} 
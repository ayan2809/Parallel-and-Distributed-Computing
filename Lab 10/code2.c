#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv)
{
   int rank;
   int a0, a1, a2, a3, b0, b1, b2, b3, c0, c1, c2, c3,m=5;
   a0 = 0;
   a1 = 0;
   a2 = 0;
   a3 = 0;
   b0 = 0;
   b1 = 0;
   b2 = 0;
   b3 = 0;
   MPI_Status status;
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   
   if(rank == 0)
   {
      a0 = 11;
      b0 = 51;
      
      MPI_Send(&a0, 1, MPI_INT, 2, 1, MPI_COMM_WORLD);
      MPI_Send(&b0, 1, MPI_INT, 1, 2, MPI_COMM_WORLD);
      MPI_Recv(&a1, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
      MPI_Recv(&b2, 1, MPI_INT, 2, 2, MPI_COMM_WORLD, &status);
      printf("process %d a = %d, b = %d, c = %d\n", rank, a1, b2, c0 = a1+b2);
      
      MPI_Send(&c0, 1, MPI_INT, 4, 3, MPI_COMM_WORLD);
   }
   if(rank == 1)
   {
      a1 = 21;
      b1 = 63;
      
      MPI_Send(&a1, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
      MPI_Send(&b2, 1, MPI_INT, 3, 2, MPI_COMM_WORLD);
      MPI_Recv(&a3, 1, MPI_INT, 3, 1, MPI_COMM_WORLD, &status);
      MPI_Recv(&b0, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
      printf("process %d a = %d, b = %d, c = %d\n", rank, a3, b0, c1 = a3+b0);
      
      MPI_Send(&c1, 1, MPI_INT, 4, 3, MPI_COMM_WORLD);
   }
   if(rank == 2)
   {
      a2 = 31;
      b2 = 7;
      
      MPI_Send(&a2, 1, MPI_INT, 3, 1, MPI_COMM_WORLD);
      MPI_Send(&b2, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
      MPI_Recv(&a0, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
      MPI_Recv(&b3, 1, MPI_INT, 3, 2, MPI_COMM_WORLD, &status);
      printf("process %d a = %d, b = %d, c = %d\n", rank, a0, b3, c2 = a0+b3);
      
      MPI_Send(&c2, 1, MPI_INT, 4, 3, MPI_COMM_WORLD);
   }
   if(rank == 3)
   {
      a3 = 45;
      b3 = 8;
      
      MPI_Send(&a3, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
      MPI_Send(&b3, 1, MPI_INT, 2, 2, MPI_COMM_WORLD);
      MPI_Recv(&a2, 1, MPI_INT, 2, 1, MPI_COMM_WORLD, &status);
      MPI_Recv(&b1, 1, MPI_INT, 1, 2, MPI_COMM_WORLD, &status);
      printf("process %d a = %d, b = %d, c = %d\n", rank, a2, b1, c3 = a2+b1);
      
      MPI_Send(&c3, 1, MPI_INT, 4, 3, MPI_COMM_WORLD);      
   }
   if (rank == 4){
         MPI_Recv(&c0, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, &status);
         MPI_Recv(&c1, 1, MPI_INT, 1, 3, MPI_COMM_WORLD, &status);
         MPI_Recv(&c2, 1, MPI_INT, 2, 3, MPI_COMM_WORLD, &status);
         MPI_Recv(&c3, 1, MPI_INT, 3, 3, MPI_COMM_WORLD, &status);
         
         int i=1;
         int numbers[4] = {c0, c1, c2 ,c3};
         int min = numbers[0];
         for (i; i<4; i++){
             if (min > numbers[i]) {
                min = numbers[i];        
             }  
         }
         printf("Minimum number is: %d\n", min);
   }
   
   MPI_Finalize();
   
   return 0;
}
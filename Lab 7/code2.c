#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include<mpi.h>
void generate_tt(int);
void check_ckt(int, int);
int a[65536];
int b[65536];
int c[65536];
int lower=1;
int upper=3;
double ans[65536];
int main()
{
    int i, n=3;
    int id;
    int p;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    int m=16;
    generate_tt(m);
    for(i=id;i<m;i+=p)
    {
        check_ckt(id,i);
    }
    MPI_Finalize();
    return 0;
    
}
void generate_tt(int m)
{
    for(int i=0;i<m;i++)
    {
        a[i]=rand()%5;
        b[i]=rand()%7;
        c[i]=(rand() % (upper - lower + 1)) + lower;
        ans[i]=(a[i]+b[i])/c[i];
    }
}
void check_ckt (int id, int i)
{
    printf("%d th core with %lf value \n",id, ans[id]);
}
#include <omp.h>  
#include<stdio.h>
#include <sched.h>
#define _GNU_SOURCE
int main () 
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int b[10]={0,1,2,3,4,5,6,7,8,9};
    int c[10];
    int d[10];
    
    int i;
     
	   #pragma omp parallel sections
		{
            #pragma omp section
                for(i=0;i<10;i++)
                    c[i]=a[i]+b[i];
            #pragma omp section
                for(i=0;i<10;i++)
                    c[i]=a[i]*b[i];
		}
		printf("Values of c array : ");
		for (i=0; i < 10; i++) 
		{
			printf("%d ",c[i]);
		}
        
		printf("\n");
        printf("Values of d array : ");
        for (i=0; i < 10; i++) 
		{
			printf("%d ",d[i]);
			
		}
        printf("\n");
}


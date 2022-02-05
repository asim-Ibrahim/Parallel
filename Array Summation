/*--------------------------------------------
    Array Summation using MPI Scatter and Reduce
    
      <==Done By==>
     Asim Ibrahim Khalil

  ---------------------------------------------*/

#include <iostream>
#include <mpi.h>
#include <chrono>
using namespace std;
int main()
{
    long long* globalData;
    int rank, size;
    long long globalSum;
    long long localData[100000];

    double startTime, endTime;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    globalData = new long long[size * 100000];
    
    if (rank == 0) {

        
        for (int i = 0; i <size*100000; i++)
        {
            globalData[i] = i;
           
        }
        startTime = MPI_Wtime();
       
    }
    
    MPI_Scatter(globalData, 100000, MPI_LONG_LONG, localData, 100000, MPI_LONG_LONG, 0, MPI_COMM_WORLD);
    long long partialSum=0;
    for (long long x : localData) {
        partialSum += x;
        
    }
    MPI_Reduce(&partialSum, &globalSum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        endTime = MPI_Wtime();
        printf("summation of the array= %lld \ntotal Time %f", globalSum,endTime-startTime);
    }

    MPI_Finalize();
    return 0;
}

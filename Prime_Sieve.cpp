/*--------------------------------------------
    Using OpenMP to find all prime numbers in a specified boundary
    through the Sieve of Eratosthenes scheme
  ---------------------------------------------*/

#include <iostream>
#include<omp.h>
#include<chrono>

using namespace std;
using namespace std::chrono;
int main()
{
    int size;
    int numOfThreads;

    cout << "Please enter the maximum number you want to calculate to: ";
    scanf_s("%d", &size);
    cout << "\nPlease enter the number of threads you would like to use: ";
    scanf_s("%d", &numOfThreads);
    
    
    bool *primeNumbers=new bool[size]; 
    memset(primeNumbers, true, size);

    auto start = high_resolution_clock::now();
    for (int i = 2; i* i <= size; i++) 
    {
        if (primeNumbers[i]) 
        {
            #pragma omp parallel for num_threads(numOfThreads)
            for (int j = i * i; j <= size; j += i) {
                primeNumbers[j] = false;
            
            }
        }
    }

    auto end = high_resolution_clock::now();
    for (int i = 2; i < size; i++)
    {
        if (primeNumbers[i]) {
            cout << i << " , ";
        }
    }
   
    auto duration = chrono::duration_cast<microseconds>(end - start);
    printf("\ntotal proccess took %d microseconds",duration.count());
    return 0;
}

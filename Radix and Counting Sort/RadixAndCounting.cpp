#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;


    
    int MaxNum(int T[],int N)
    {
        int max = T[0];
        for (int i =0; i<N ; ++i)
        {
            if (max<T[i])
                max = T[i];
        }
        return  max;
    }

    //Counting Sort
    void CountingSort(int A [], int N,int k) //N size of the orignal array
    //k the max num in the array
    {   //array for sorted array
        int B[N];
        
        int C[10];
        
        for (int i=0; i<10;++i)
        {
            C[i]=0;
        }
      
        for (int i=0; i<N; ++i)
        {
            
            C[(A[i]/k) %10]++;
        }
        //Cummulative frequency of the array
        for (int i=1; i<10; ++i)
        {
            
            C[i] = C[i] + C[i-1];
        }
        //loop for sorting the list
        for (int i=N-1; i>=0 ; --i)
        {
            // sorting the array
            B[C[(A[i] / k) % 10] - 1] = A[i];
            C[(A[i]/k)%10]--;
        }

        //For sorting
        for (int i=0; i<N; ++i)
        {
            A[i] = B[i];
        }
    }

    //Radix sort 
    void RadixSort(int A[] , int N)
    {
        
        int max = MaxNum(A, N);
        for (int k = 1; max / k > 0; k *= 10)
            CountingSort(A, N, k);
    }

    //print array
    void PrintArray(int A[], int N)
    {
        for (int i=0; i<N; ++i)
        {
            cout<<A[i]<<" ";
        }
    }

int main()
{
    int arr[100];
    srand(time(NULL));
    for (long i = 0; i < 100; i++){
        arr[i] = (rand() % 100) + 1;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr,arr+n, greater<int>());
    clock_t startTime = clock();
    RadixSort(arr, n);
    cout << "time = " << double(clock() - startTime) / CLOCKS_PER_SEC << endl;
    PrintArray(arr,n);
    return 0;

}


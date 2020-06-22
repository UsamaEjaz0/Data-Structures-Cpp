#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// To merge sorted arrays
class sortingAlgorithms{
	public:
		void merge(int*,int,int,int);
		void mergeSort(int *,int, int);
		void selectionsort(int *,int);
		void bubblesort(int*,int);
		void insertionsort(int*,int);
};

void sortingAlgorithms:: merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
    
    
    
    
    
    
    
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; // first index of first subarray 
    j = 0; // first index of second subarray 
    k = l; // first index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
//Mergesort code 

void sortingAlgorithms::  mergeSort(int arr[], int l, int r) { 
    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}


//selection sort code

void sortingAlgorithms::selectionsort(int A[], int size){
	
	int max; //to hold maximum value after each pass;
	
	for (int i = size - 1; i > 0; i--){

		max = i;
		for (int j = 0; j < i; j++){
			if (A[j] > A[max])
				max = j;
		}
		//swaping after 1 pass
		
		swap(A[i], A[max]);

	}


}

//Insertion sort code :

void sortingAlgorithms::insertionsort(int A[], int size){
	
	for (int i = 1, j; i < size; i++) {
		int tmp = A[i];
		for (j = i; j > 0 && tmp < A[j - 1]; j--)
			A[j] = A[j - 1];
		A[j] = tmp;
	}


}

//bubblesort code:

void sortingAlgorithms::bubblesort(int A[], int size){

	for (int i = size-1; i > 1; i--){

		for (int j = 0; j < i ; j++){

			if (A[j]>A[j + 1])
			
			//swapping in every data movement
				swap(A[j], A[j + 1]);
		}
	}
	
}


int main() {
	//Making an object of class sortingAlgorithms
	sortingAlgorithms s;
	//input for array size
	int size;
	cout<<"Enter array size:";
	cin>>size;
	int A[size];
	for (int i=0;i<size;i++){
		cout<<endl<<"Enter element:";
		cin>>A[i];
	}

	s.mergeSort(A,0, size-1);
	for (int k = 0; k < size; k++){
		cout << A[k]<<" ";
	}
	



	
	
	


	return 0;
}


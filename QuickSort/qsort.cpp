#include <iostream>
using namespace std;


void swap(int* a, int *b){
	int t = *a; 
	*a = *b;
	*b = t;
}

int partition(int *A, int start, int  end){
	int bound = A[end];
	int i = start-1;
	for (int j = start; j <= end-1; j++){
		if (A[j] < bound){
			
			i++;
			swap(&A[i], &A[j]);
			
			
		}
		
			
	}
	swap(&A[i + 1] ,& A[end] );
	return i+1;
	

};

void quicksort(int *A, int start, int end){
	if (start < end){
		int q = partition(A, start, end);
		quicksort(A, start, q-1);
		quicksort(A, q +1, end);
	}
	

}



int main(){
	int A[10] = { 1, 4, 6, 75, 563, 563, 5, 4, 9, 10 };
	for (int i = 0; i < 10; i++){
		cout << A[i]<<endl;
	}
	int size = sizeof(A) / sizeof(A[0]);
	quicksort(A, 0, size-1);
	cout << endl;
	for (int i = 0; i < 10; i++){
		cout << A[i] << endl;
	}


	return 0;
}


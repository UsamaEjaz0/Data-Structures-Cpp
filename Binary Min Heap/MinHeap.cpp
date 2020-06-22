#include "iostream"

using namespace std;


class heap{
	
	int capacity; 
public:	int heap_size; int *arr;
private:int parent(int i)
{
			return i / 2;
}
		int left(int i)
		{
			return (2 * i);
		}
		int right(int i)
		{
			return ((2 * i) + 1);
		}
		void swaps(int *a, int *b)
		{
			int temp;
			temp = *a;
			*a = *b;
			*b = temp;
		}
		//merthods for deletion a value
	void decrease(int i, int new_value){
			 arr[i] = new_value;
			 while (i != 0 && arr[parent(i)] > arr[i]){
				 swaps(&arr[i], &arr[parent(i)]);
				 i = parent(i);
			 }

}

	int extractmin(){
		if (heap_size <= 0)
			return INT_MAX;
		if (heap_size == 1)
		{
			heap_size--;
			return arr[0];
		}

		
	
		int root = arr[0];
		arr[0] = arr[heap_size - 1];
		heap_size--;
		MinHeapify(0);

		return root;
	
	}//end of methods of deletion

	void heapify(int arr[], int n, int i)
	{
		int smallest = i;  
		int l = left(i);
		int r = right(i);

		 
		if (l < n && arr[l] < arr[smallest])
		{
			smallest = l;
		}

		 
		if (r < n && arr[r] < arr[smallest])
		{
			smallest = r;
		}
		
		if (smallest != i) {
			swaps(&arr[i], &arr[smallest]);

			
			heapify(arr, n, smallest);
		}
	}

public:	heap(int limit)	{
		   capacity = limit;
		   arr = new int[capacity];
}
	void top(){
			cout << "Minimum Element:" << arr[0];
	
	}
		void pop(int i){
			decrease(i, INT_MIN);
			extractmin();
		
		
		}
void MinHeapify(int i){
			int l = left(i);
			int r = right(i);
			int smallest = i;
			if (l < heap_size && arr[l] < arr[i])
				smallest = l;
			if (r < heap_size && arr[r] < arr[smallest])
				smallest = r;
			if (smallest != i)
			{
				swaps(&arr[i], &arr[smallest]);
				MinHeapify(smallest);
			}
		
		}
		void BuildHeap(int arr[],int n){
			
			int start = n;
			for (int i = start; i >= 0; i--) {
				heapify(arr,n,i);
			}
		}
		void push(int k){
			if (heap_size == capacity)
			{
				cout << " Can not insertKey";
				return;
			}

			
			heap_size++;
			int i = heap_size - 1;
			arr[i] = k;

			while (i != 0 && arr[parent(i)] > arr[i])
			{
				swaps(&arr[i], &arr[parent(i)]);
				i = parent(i);
			}
		
		
		}

		bool isEmpty()
		{
			if (heap_size == 0)
			{
				cout << "heap is empty" << endl;
				return 1;
			}
			else
			{
				cout << "heap is not empty" << endl;
				return 0;
			}
		}

		int size(){
			return heap_size;
		
		}
int height()
		{
			int height = 0;
			int node = heap_size;
			while (node != 1)
			{
				node = node / 2;
				height++;
			}
			cout << "Height of the Heap: " << height << endl;
			return height;
		}

		void print()
		{
			cout << "min heap" << endl;
			for (int i = 0; i < heap_size; i++)
			{
				cout << arr[i] << " - ";
			}
		}
};

int main()
{	
	int choice = 0, value;
	heap heap1(30);
	do
	{
		cout << "\nChoose the operation"
			<< endl;
		cout << "1. Minimum Element\n2. Pop Element\n3. Push Element\n4. Check if Empty\n5. Return Size" <<
			endl;
		cout << "6. Return Height\n7. Build Min Heap\n8. Print" << endl;
		cin >> choice;
		switch (choice) //switch case
		{
		case 1:
			heap1.top();
			break;
		case 2:
			heap1.pop(30);
			break;
		case 3:
			cout << "Enter the value you wish to insert: ";
			cin >> value;
			heap1.push(value);
			break;
		case 4:
			heap1.isEmpty();
			break;
		case 5:
			cout << "Size of the Heap: " << heap1.size() << endl;
			break;
		case 6:
			heap1.height();
			break;
case 7:
			int  arr[30];int n;int z;
			cout << "Choose the size of your heap: ";
			cin >> z;
			heap1.push(z);
			
			for (int i = 0; i <= n; i++)
			{
				cout << "Element " << i << ": ";
				cin >> heap1.arr[i];
				heap1.push(i);
			}
			heap1.BuildHeap(arr, n);
			break;
		case 8:
			heap1.print();
			break;
		default:
			cout << "Invalid operation selected!" << endl;
			break;
		}
	} while (1);
	return 0;
}



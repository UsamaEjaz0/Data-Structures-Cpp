#include<iostream>
using namespace std;
class queue { //Class queue
public:
	static int const size = 5;
	int arr[size], front, rear;   //Array based queue

public:
	queue(){  //Constructor
		front = -1;
		rear = -1;
	}

	bool isFull(){  //To check if queue is full
		if (front == 0 && rear == size - 1){
			return true;
		}
		if (front == rear + 1) {
			return true;
		}
		return false;
	}

	bool isEmpty(){   //To check if queue is empty
		if (front == -1) return true;
		else return false;
	}

	void enqueue(int element){   //To add an element
		if (isFull()){
			cout << "Queue is full";
		}
		else {
			if (front == -1) front = 0;
			rear = (rear + 1) % size;
			arr[rear] = element;
			
		}
	}

	int dequeue(){   //to remove an element
		int element;
		if (isEmpty()){
			cout << "Queue is empty" << endl;
			return(-1);
		}
		else {
			element = arr[front];
			if (front == rear){
				front = -1;
				rear = -1;
			} 
			else {
				front = (front + 1) % size;
			}
			return(element);
		}
	}

	void display()   //To display the elements of queue
	{
		
		int i;
		if (isEmpty()) {
			cout << endl << "Appointments finish" << endl;
		}
		else
		{
			
			cout << endl << "IDs of all patients : ";
			for (i = front; i != rear; i = (i + 1) % size)
				cout << " "<<arr[i];
			cout <<" "<< arr[i]<<endl;
			
		}
	}

};

class WaitingRoomSys{  //Class for waiting room management system
public:
	queue q;  //Using aggregation to make a queue
	int id = 1;




	void registerPatient(){  //Register patient (using enqueue)
		if (q.isFull()){
			cout << "Queue is full" << endl;
		}
		else{
			q.enqueue(id);
			
			cout << "ID Registered : " <<id<< endl;
			id ++;
		}
	}
	void serverPatient(){ //Serve a patient (using dequeue)
		if (q.isEmpty()){
			cout << "Queue is empty" << endl;
		}else
			cout << "ID of patient served : " << q.dequeue() << endl;
	}
	void cancelAll(){  //Cancelling all apointments
		for (int i = 0; i < q.size; i++){
			if (q.isEmpty()){
				break;
			}
			q.dequeue();
	}
	}
	void canDoctorGoHome(){  //checking if queue is empty so doctor can go home
		if (q.isEmpty()){
			cout << "Doctor can go home!";
		}
else
		cout << "Doctor cannot go home!";
	}
	void ShowAllPatient(){ //Show all patients
		q.display();
		
	}



};






int main(){ //main method
	queue p;
	WaitingRoomSys wrs;
	int choice;
	while (true){ //Menu
		cout << "Select from the following options."<<endl;
		cout << "1. Register a patient" << endl;
		cout << "2. Serve a patient" << endl;
		cout << "3. Cancel all apointments" << endl;
		cout << "4. Can doctor go home?" << endl;
		cout << "5. Show all patients"<<endl;
		cin >> choice;
		switch (choice){

			case 1:
				wrs.registerPatient();
				break;
			case 2:
				wrs.serverPatient();
				break;
			case 3:
				wrs.cancelAll();
				break;
			case 4:
				wrs.canDoctorGoHome();
				break;
			case 5:
				wrs.ShowAllPatient();
				break;



				
		
		
		};
			

	}
	return 0;
}


#include <iostream>
#include "string"
using namespace std;


//Class Node
class Node  {

	//Public Members
	public:
			int value;
			Node *next;
	
		
	//Constructor overloaded
	Node(int element, Node* input = NULL){
			value = element;
			next = input;

		}

	//Default Constructor
	Node(){
		next = 0;
	}

};

//New Class AccessNode
class AccessNode{

	//Private Members
private:
	Node* head, *tail;

	//Public Members
public:
	AccessNode(){
		head = tail = NULL;
	}
	//Functions

	void insertAtHead(int new_value);
	void insertAtLocation(int location, int new_value);
	void deleteNode(int del_value);
	void displayList();
	int countList();
		

};
	//Function to insert at head
void AccessNode::insertAtHead(int new_value){
	
	head = new Node(new_value,head);

	if (tail==NULL)
		tail = head;
}
 //Function to insert to specific location
void AccessNode::insertAtLocation(int location, int new_value){
	Node* traverse;
	traverse = head;
	if (location == 0){
		insertAtHead(new_value);
	}
	else  if (location> 0 && location<=countList()){
		for (int i = 0; i < (location-1); i++){
			traverse = traverse->next;
		}
		traverse->next=new Node(new_value, traverse->next);
	}
	//Insert at tail
	else  if (location==(countList()+1)){

		while (traverse){
			traverse = traverse->next;
		}
		traverse = new Node(new_value);
		traverse->next = NULL;
	}
	//Invalid Location
	else{
		
			cout << "There are not ";
			cout << location;
			cout << " nodes in the linkedlist" << endl;
		
	}
	




}

//To count the linklist
int AccessNode::countList(){
	int x=0;
	Node* nodeptr;
	nodeptr = head;
	while (nodeptr){
		nodeptr = nodeptr->next;
		x++;
		
	}
	return x;
}
// To Display linkList
void AccessNode::displayList(){
	Node* nodeptr;
	nodeptr = head;
	while (nodeptr){
		cout << nodeptr->value << endl;
		nodeptr = nodeptr->next;
	}
}
//To Delete a node
void AccessNode::deleteNode(int location){
	Node*traverse, *prev;
	traverse = head;
	prev = head;
	if (location == 0){
		delete head;
	}
	else  if (location> 0 && location <= countList()){
		for (int i = 0; i < (location); i++){
			prev = traverse;
			traverse = traverse->next;
		}
		prev->next = traverse->next;
		
		delete traverse;
		
	}
	else  if (location == (countList() + 1)){

		while (traverse){
			prev = traverse;
			traverse = traverse->next;
		}
		tail = prev;
		prev->next = NULL;
		tail = traverse;
		delete traverse;
	}
	else{

		cout << "There are not ";
		cout << location;
		cout << " nodes in the linkedlist" << endl;

	}


}



// Main Method

int main(){
	AccessNode a100;
	while (1)
	{
		char a = NULL; //drawing menu
		cout << " Select from one of the following\n A.Create a node or Insert at HEAD \n B.Display Linked list entries \n C.Insert at location \n D.Delete from location" << endl;
		cin >> a;
		switch (a) {
		case 'A':
			cout << "\nInsert any value to Create a node\n" << endl;
			int a1;
			cin >> a1;
			a100.insertAtHead(a1);
			break;
		case 'B':
			cout << "\nDisplay Linked list entries\n" << endl;
			a100.displayList();
			break;
		case 'C':

			cout << "\nChoose which location to enter the value\n" << endl;
			cout << "\n" << endl;
			int b1, b2;
			cin >> b1;
			cout << "\nChoose the value to be entered\n" << endl;
			cin >> b2;
			cout << "\n\n" << endl;
			a100.insertAtLocation(b1, b2);

			break;
		case 'D':
			cout << "Delete from entry location" << endl;
			int d1;
			cin >> d1;
			a100.deleteNode(d1);
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	}
	return 0;
};


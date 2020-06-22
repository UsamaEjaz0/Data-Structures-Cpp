#include <iostream>  
using namespace std;  
  
class Node {    //Node Class  
public:  
      
    //Default constructor  
      
    Node() {  
        next = 0;  
        prev = 0;  
    }  
    //Overloaded Constructor  
      
    Node(int i=0, Node * nex = 0, Node *pre = 0) {  
        info = i; next = nex; prev = pre;  
    }  
    //Data members  
    int info;  
    Node *next;  
    Node *prev;  
};  
  
    //Class to manipulate node  
  
class AccessNode{  
    //private members  
      
private:  
    Node *head, *tail;  
    //public members  
      
public:  
      
    AccessNode() { head = tail = NULL; }  
    int isEmpty() { return head == 0; }  
  
    void insertAtStart();  
    void insertLast();  
    void insertAtPos();  
    void deleteAtPos();  
    void display();  
    int countlist();  
};  
  
//Function to count list  
  
int AccessNode::countlist(){  
  
    int size = 0;  
    Node* traverse;  
    traverse = head;  
    do{  
        size++;  
          
        traverse = traverse->next;  
  
    } while (traverse != head->prev);  
      
    return size ;  
}  
//Function to insert at start  
  
void AccessNode::insertAtStart(){  
    int value; Node* temp;  
    cout<<endl<<"Enter the element to be inserted: ";  
    cin>>value;  
  
    if (head){  
        temp = head;  
        head = new Node(value, head, tail);  
        temp->prev = head;  
        tail->next = head;     
    }  
    else{  
        head = tail = new Node(value, head, tail);  
    }  
  
  
  
  
  
};  
//Function to insert at given position  
  
void AccessNode::insertAtPos(){  
        int value, pos;  
        Node* newNode;  
        Node*previous,*forward;  
        previous = NULL;  
        forward = head;  
          
        cout << endl << "Enter the postion of element: ";  
        cin >> pos;  
            //If position is zero (head)  
        if (pos <= countlist()+1){  
            if (pos == 0){  
                insertAtStart();  
            }  
            //If position is tail  
            else if (pos == countlist()){  
                insertLast();  
            }  
            else{  
  
                cout << endl << "Enter the value to be inserted:";  
                cin >> value;  
                for (int i = 0; i < pos; i++){  
                    previous = forward;  
                    forward = forward->next;  
                }  
                newNode = new Node(value, forward, previous);  
                forward->prev = newNode;  
                previous->next = newNode;  
            }  
  
        }  
        else{  
            cout << "There are not " << pos << " elements in the list!";  
        }  
  
  
    };  
    //To delete a node from given position  
      
void AccessNode::deleteAtPos(){  
    int value, pos;  
    Node* newNode, *temp;  
    Node*previous, *forward;  
    previous = NULL;  
    forward = head;  
    cout << endl << "Enter the postion of element: ";  
    cin >> pos;  
  
      
      
        if (pos <= countlist()){  
            if (pos == 0){  
            temp = head;  
            tail->next = head->next;  
            head->next->prev = tail;  
            head = head->next;  
            delete temp;  
              
        }  
            else if (pos == countlist()){  
                temp = tail;  
            head -> prev = tail->prev;  
            tail->prev->next = head;  
            tail = tail->prev;  
            delete temp;  
            }  
              
            else{  
  
                for (int i = 0; i < pos; i++){  
                      
                    previous = forward;  
                    forward = forward->next;  
                      
                      
                }  
                previous->next=forward->next;  
                forward->next->prev=previous;  
                delete forward;  
            }  
              
  
        }  
        else{  
            cout << "There are not " << pos << " elements in the list!";  
        }  
          
  
};  
    //To display the list   
  
void AccessNode::display(){  
      
    Node* traverse;  
    traverse = head;  
    //to traverse the nodes  
    do{  
          
        cout << traverse->info << endl;  
        traverse = traverse->next;  
  
    } while (traverse != head->prev);  
      
    cout << traverse->info << endl;    
      
      
  
};  
    //To insert at the tail  
  
void AccessNode::insertLast(){  
  
  
  
  
    int value;  
    cout<<endl<<"Enter the element to be inserted: ";  
    cin>>value;  
  
  
    if (tail != 0){  
        tail = new Node(value, head, tail);  
        tail->prev->next = tail;  
        head->prev = tail;  
    }  
    else{  
        head = tail = new Node(value,head,tail);  
        cout << "here";  
        head->prev = tail;  
    }  
  
  
}  
  
  
  
  
  
    //Main method  
int main(){  
    int userChoice;  
    AccessNode cdl;  
      
    //Main Menu  
      
    while (1){  
        cout << "\n-------------------------------" << endl;  
        cout << "Operations on Doubly Circular linked list" << endl;  
        cout << "\n-------------------------------" << endl;  
        cout << "1.Insert at Beginning" << endl;  
        cout << "2.Insert at Last" << endl;  
        cout << "3.Insert at Specific Position" << endl;  
        cout << "4.Delete at Specific Position" << endl;  
        cout << "5.Display List" << endl;  
        cout << "6.Exit" << endl;  
        cout << "Enter your choice : ";  
        cin >> userChoice;  
        switch (userChoice){  
        case 1:  
            cdl.insertAtStart();  
            break;  
        case 2:  
            cdl.insertLast();  
            break;  
        case 3:  
            cdl.insertAtPos();  
            break;  
        case 4:  
            cdl.deleteAtPos();  
            break;  
        case 5:  
            cdl.display();  
              
            break;  
        case 6:  
            exit(1);  
        default:  
            cout << "Wrong choice" << endl;  
        }  
    }  
    return 0;  
}  


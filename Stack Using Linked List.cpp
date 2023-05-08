include <bits/stdc++.h>
#include <ctime>
using namespace std;

// creating a linked list;
class Node {
public:
	int data;
	Node* next;
	
	
	Node(int n)
	{
		this->data = n;
		this->next = NULL;
	}
};

class Stack {
	Node* top;

public:
	Stack() { top = NULL; }

	void push(int data)
	{

		// Create new node temp and allocate memory in heap
		Node* temp = new Node(data);

		// Check if stack (heap) is full.
		// Then inserting an element would
		// lead to stack overflow
		if (!temp) {
			cout << "\nStack Overflow";
			exit(1);
		}

		// Initialize data into temp data field
		temp->data = data;

		// Put top pointer reference into temp link
		temp->next = top;

		// Make temp as top of Stack
		top = temp;
	}

	//Checking whether the stack is empty or not
	bool isEmpty()
	{
		return top==NULL;
		
	}

	//Return the top element of the stack
	int peek()
	{
		// If stack is not empty , return the top element
		if (!isEmpty())
			return top->data;
		else
			exit(1);
	}

	
	void pop()
	{
		Node* temp;

		// Check for stack is Empty
		if (isEmpty()) {
			cout << "Stack is Empty" << endl;
			exit(1);
		}
		else {

			// Assign top to temp
			temp = top;

			// Assign second node to top
			top = top->next;
             
            // Deleting elements from the head of the linked list in order to 
            //maintain the time complexity of O(n)
			

			// Release memory of top node
			// i.e delete the node
			free(temp);
		}
	}

	//Printing all the elements of the stack
	void display()
	{
		Node* temp;

		// Check for stack is Empty
		if (isEmpty()) {
			cout << "Stack is empty";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {

				// Print node data
				cout << temp->data<<" ";

				// Assign temp link to temp
				temp = temp->next;
				
			}
		}
		
	}
};

// Driven Program
int main()
{
	// Creating a stack
	Stack s;

	// Push the elements of stack
	
	clock_t start_time = clock();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
   
   clock_t end_time = clock();
    // Compute the elapsed time in microseconds
    double elapsed_time = double(end_time - start_time) ;
    cout << "Elapsed time: " << elapsed_time << " microseconds" << endl;  
    s.display();
    cout<<"\n";
  
  ////////////////////////////////////////////////////////////////////////
    clock_t start_time2 = clock();
    for(int i=0;i<5;i++){
        s.pop();
    }
    
    cout<<"\n";
    clock_t end_time2 = clock();
    // Compute the elapsed time in microseconds
    double elapsed_time2 = double(end_time2 - start_time2) ;
    cout << "Elapsed time: " << elapsed_time2 << " microseconds" << endl;  
    
    cout<<"\n";
    s.display();
    
  
///////////////////////////////////////////////////////////////////////////    
    clock_t start_time3 = clock();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    
    cout<<"\n";
     clock_t end_time3 = clock();
    // Compute the elapsed time in microseconds
    double elapsed_time3 = double(end_time3 - start_time3) ;
    cout << "Elapsed time: " << elapsed_time3 << " microseconds" << endl;
    
    cout<<"\n";
    s.display();
	
	cout << "\nTop element is " << s.peek() << endl;

	return 0;
}

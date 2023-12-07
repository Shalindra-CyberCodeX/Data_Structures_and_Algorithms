#include <iostream>
#include <ctime>

using namespace std;

const int MAX_SIZE = 11; // Maximum size of the stack

class Stack {
  private:
    int arr[MAX_SIZE];
    int top;
  public:
    Stack() {
      top = -1;
    }

    bool isEmpty() {
      return top == -1;
    }

    bool isFull() {
      return top == MAX_SIZE - 1;
    }

    void push(int value) {
      if (isFull()) {
        cout << "Stack is full" << endl;
      } else {
        top++;
        arr[top] = value;
      }
    }

    int pop() {
      if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
      } else {
        int value = arr[top];
        top--;
        return value;
      }
    }

    int peek() {
      if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
      } else {
        return arr[top];
      }
    }
    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are:";
            for (int i = top; i >= 0; i--) {
                cout << " " << arr[i];
                if (i != 0) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    
    
};

int main() {
  
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
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
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
    double elapsed_time2 = double(end_time2 - start_time2) / CLOCKS_PER_SEC * 1000000;
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
    double elapsed_time3 = double(end_time3 - start_time3) / CLOCKS_PER_SEC * 1000000;
    cout << "Elapsed time: " << elapsed_time3 << " microseconds" << endl;
    
    cout<<"\n";
    s.display();
    
	
	cout << "\nTop element is " << s.peek() << endl;

  
  
  
  return 0;
}

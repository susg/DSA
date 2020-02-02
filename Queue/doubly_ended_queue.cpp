// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;
 
// Maximum size of array or Dequeue
#define SIZE 5

class Dequeue
{
    int  *arr;
    int front, rear;  
    //fornt and rear to store the head and tail pointers

public :

    Dequeue()
    {
    	//Create the array
        arr = new int[SIZE];

        //Initialize front and rear with -1
        front = -1;
        rear = -1;
    }
 
    // Operations on Deque:
    void  push_front(int );
    void  push_back(int );
    void  pop_front();
    void  pop_back();
    int  get_front();
    int  get_back();
    bool  full();
    bool  empty();   
};
 
bool Dequeue :: full()
 {
    if((front == 0 && rear == SIZE-1)  ||
    	(front == rear + 1))
        return true;
    else
        return false;
 }

bool Dequeue :: empty()
{
    if(front == -1)
    	return true;
    else
    	return false;
}

void Dequeue :: push_front(int key)
{
    if(full())
    {
        cout << "OVERFLOW\n";
    }
    else
    {
    	//If queue is empty
    	if(front == -1)
    		front = rear = 0;

    	//If front points to the first position element 
        else if(front == 0)
            front = SIZE-1;
        
        else
        	--front;
        
        arr[front] = key;
    }
}

void Dequeue :: push_back(int key)
{//cout<<"rr= "<<front<<endl;
    if(full())
    {
   //     cout<<"rr= "<<rear<<endl;
        cout << "OVERFLOW\n";
    }
    else
    {
        //If queue is empty
    	if(front == -1)
    		front = rear = 0;

    	//If rear points to the last element
        else if(rear == SIZE-1)
            rear = 0;
        
        else
        	++rear;
        
        arr[rear] = key;
    }    
}

void Dequeue :: pop_front()
{
    if(empty())
    {
        cout << "UNDERFLOW\n";
    }
    else
    {
    	//If only one element is present
        if(front == rear)
        	front = rear = -1;

        //If front points to the last element 
        else if(front == SIZE-1)
        	front = 0;

        else
        	++front;		
    }
}

void Dequeue :: pop_back()
{
    if(empty())
    {
        cout << "UNDERFLOW\n";
    }
    else
    {
    	//If only one element is present
        if(front == rear)
        	front = rear = -1;

        //If rear points to the first position element 
        else if(rear == 0)
        	rear = SIZE-1;

        else
        	--rear;		
    }
}

int Dequeue :: get_front()
{
    if(empty())
    {	cout << "f=" <<front << endl;
        cout << "UNDERFLOW\n";
        return -1;
    }
    else
    {
        return arr[front];
    }
}

int Dequeue :: get_back()
{
    if(empty())
    {
        cout << "UNDERFLOW\n";
        return -1;
    }
    else
    {
        return arr[rear];
    }
}

int main()
{
    Dequeue dq;
    dq.push_front(5);
    dq.push_back(10);
    dq.push_back(15);
    cout << dq.get_front() << endl;
    dq.pop_front();
    cout << dq.get_front() << endl;
    dq.pop_back();
    
    cout << dq.get_back() << endl;
}
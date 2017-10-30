#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *next;
};

class Stack
{
	node *front;
	public :
	Stack()
	{
		front = NULL;
	}
	void push(int );
	void pop();
	int top();
	bool empty();
};

void Stack :: push(int d)
{
	//creating a new node
	node *temp;
	temp = new node();
	temp->data = d;

	//add the node in front of list
	if(front == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = front;
	}
	front = temp;
}
void Stack :: pop()
{
	//if empty
	if(front == NULL)
		cout << "UNDERFLOW\n";
	
	//delete the first element
	else
	{
		node *temp = front;
		front = front->next;
		delete(temp);
	}
}
int Stack :: top()
{
	return front->data;
}

bool Stack :: empty()
{
	if(front == NULL)
		return true;
	return false;
}

int main()
{
	Stack st;
	st.push(10);
	st.push(5);
	cout<<st.top();
	st.pop();
	cout<<st.top();
	st.pop();
	//cout<<st.top();
	st.pop();
	
	return 0;
}


















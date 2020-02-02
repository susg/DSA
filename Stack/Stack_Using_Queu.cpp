#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
	queue<int> Q1, Q2;
	void push(int );
	int pop();
};

int Stack :: pop()
{
	int x = Q1.front();
	Q1.pop();
	return x;
}

void Stack :: push(int x)
{
	while(!Q1.empty())
	{
		int temp = Q1.front();
		Q1.pop();
		Q2.push(temp);
	}

	Q1.push(x);
	
	while(!Q2.empty())
	{
		int temp = Q2.front();
		Q2.pop();
		Q1.push(temp);
	}
}

int main()
{
	Stack s;
	s.push(5);
	s.push(10);
	cout << s.pop() << endl;
	s.push(15);
	s.push(20);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}
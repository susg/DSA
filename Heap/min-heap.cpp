#include<iostream>
#include<limits>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

class MinHeap
{
	int *heap, capacity, curr_size;

	public :
	MinHeap(int n)
	{
		capacity = n;
		heap = new int[n+1];
		curr_size = 1;
	}
	void insert(int );
	void decrease_key(int ,int );
	void delete_key(int );	
	int return_min();
	int extract_min();
	void min_heapify(int );
	void display();
	int left(int i) { return (2*i);}
	int right(int i) { return (2*i+1);}
	int parent(int i){ return (i/2);} 
};

void MinHeap :: insert(int n)
{
	if(curr_size == capacity+1)
	{
		cout<<"\nOVERFLOW\n";
		return ;
	}

	heap[curr_size] = n;	cout<<curr_size<<endl;  //     
	curr_size++;

	if(curr_size >2) {
	
	int i = curr_size-1;
	while(i/2>0 && heap[i] < heap[parent(i)] )
	{
		swap(heap[i], heap[parent(i)]);       
		i = i/2;
	}
	}
}

int MinHeap :: return_min()
{
	if(curr_size == 1)
	{
		cout<<"\nUNDERFLOW\n";
		return INT_MAX;
	}
	return heap[1];
}

int MinHeap :: extract_min()
{
	if(curr_size == 1)
	{
		cout<<"\nUNDERFLOW\n";
		return INT_MAX;
	}
	else if(curr_size == 2)
	{
		curr_size--;
		return heap[curr_size];
	}
	int min = heap[1];
	heap[1] = heap[curr_size-1];
	curr_size--;
	min_heapify(0);
	return min;
}

void MinHeap :: decrease_key(int i, int val)
{
	heap[i] = val;
	while(i/2>0 && heap[i] < heap[parent(i)] )
	{
		swap(heap[i], heap[parent(i)]);
		i = i/2;
	}
}

void MinHeap :: delete_key(int i)
{
	decrease_key(i, INT_MIN);
	int n =extract_min();
}

void MinHeap :: min_heapify(int i)
{
	int l = left(i);
	int r = right(r);
	int smallest = i;

	if(l<curr_size && heap[l] < heap[i])
		smallest = l;
	if(r<curr_size && heap[r] < heap[smallest])
		smallest=r;

	if(smallest != i)
	{
		swap(heap[i], heap[smallest]);
		min_heapify(smallest);
	}
}

void MinHeap :: display()
{
	if(curr_size == 1)
	{
		cout<<"\nUNDERFLOW\n";
		return ;
	}
	for(int i=1; i<curr_size; i++)
		cout<<heap[i]<<" ";
	cout<<endl;	
}
int main()
{
	int n, choice,  idx ;
	MinHeap mheap(10);

	do
	{
		cout<<"\nEnter choice:\n"
			<<"1. Insert into heap\n"
			<<"2. Get minimum element\n"
			<<"3. Extract minimum element\n"
			<<"4. Delete key\n"
			<<"5. Decrease value of key\n"
			<<"6. Display elements\n"
			<<"0. Exit\n";
		cin>> choice;
		
		switch(choice)
		{
			case 1: cout<<"Enter data\n";
			cin>>n;
			mheap.insert(n);
			break;

			case 2: cout<<mheap.return_min()<<endl;
			break;

			case 3: cout<<mheap.extract_min()<<endl;
			break;

			case 4: cout<<"Enter index (1-based) of key to be deleted\n";
			cin>>idx;
			mheap.delete_key(idx);
			break;

			case 5:cout<<"Enter index (1-based) of key and new value\n";
			cin>>idx>>n;
			mheap.decrease_key(idx,n);
			break;
			case 6:mheap.display();
			break;
			case 0: break;

			default: cout<<"WRONG INPUT\n";
		}	
	}while(choice != 0);
	return 0;
}







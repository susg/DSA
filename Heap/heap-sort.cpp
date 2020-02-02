#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void heapify(int ar[], int idx, int n)
{
	int l = 2*idx + 1;
	int r = 2*idx + 2;
	int larger = idx;
	if(l < n && ar[l] > ar[idx])
		larger = l;
	if(r < n && ar[r] > ar[larger])
		larger = r;

	if(larger != idx)
	{
		swap(ar[idx], ar[larger]);
		heapify(ar, larger, n);
	}
}

void heapSort(int ar[], int n)
{
	for(int i= n/2 -1; i>=0; i--)
		heapify(ar,i,n);

	for(int i=n-1; i>=0; i--)
	{
		swap(ar[0], ar[i]);
		heapify(ar, 0, i);
	}
}

int main()
{
	int n;
	cin >> n;
	int ar[100];
	for(int i=0; i<n; i++)
		cin >> ar[i];
	heapSort(ar, n);
	for(int i=0; i<n; i++)
		cout << ar[i] << " ";
	cout << endl;
}
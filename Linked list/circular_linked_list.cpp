#include<iostream>
using namespace std;

struct  node
{
	int data;
	node *next;
};

class Circular_list
{
	node *head;
public:
	Circular_list()
	{
		head = NULL;
	}
	node* getLastNode();
	void add_front(int );
	void add_end(int );
	void delete_node(int );
	void print_list();
};

node* Circular_list :: getLastNode()
{
	if(head!=NULL)
	{
		node *trav;
		trav = head;
		do {
			
				if(trav->next == head)
					return trav;
			
				trav = trav->next;

		}while(trav != head);
		
	}
}

void Circular_list :: add_front(int d)
{
	node *temp;
	temp = new node();
	temp->data = d;
	
	if(head == NULL)
	{
		
		head = temp;
		temp->next = head;
	
	}
	else
	{
	
		temp->next = head;
		head = temp;
		node *last = getLastNode();
		last->next = temp;
		cout<<"check 4"<<endl;
	}
}  

void Circular_list :: add_end(int d)
{
	node *temp;
	temp = new node();
	temp->data = d;

	if(head == NULL)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		node *last = getLastNode();
		last->next = temp;
		temp->next = head;
	}

}

void Circular_list :: delete_node(int d)
{
	
}

void Circular_list :: print_list()
{
	if(head!= NULL)
	{
		node *trav;
		trav = head;
		do
		{
			cout<<trav->data<<endl;
			trav = trav->next;
		}while(trav != head);
	}
}

int main()
{
	Circular_list list;
	int d, choice;

	do
	{
		cout<<"\nEnter choice : \n"
			<<"1. Add in front\n"
			<<"2. Add at end\n"
			<<"3. Delete a node\n"
			<<"4. Print list\n"
			<<"0. Exit\n\n";

		cin>>choice;
		switch(choice)
		{
			case 1:  
				cout<<"Enter the data\n";
				cin>>d;
				list.add_front(d);	
				break;
			case 2:
				cout<<"Enter the data\n";
				cin>>d;
				list.add_end(d);
				break;
			case 3:
				cout<<"Enter the data to be deleted\n";
				cin>>d;
				list.delete_node(d);
				break;		
			case 4:
				list.print_list();
				break;
			case 0: cout<<"\nTerminating Program\n";
				break;	
			default : cout<<"\nWrong Input\n";	
		}

	}while( choice != 0);
	return 0;
}








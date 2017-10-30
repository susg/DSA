/**Double linked list implementation
* -Sushant Gupta
*/

#include<iostream>
using namespace std;

struct node
{
	int data;    // Data
	node *prev;  // A reference to the previous node
	node *next;  // A reference to the next node 
};

class Doubly_Linked_List
{
	node *front;  // points to first node of list
	node *end;    // points to first las of list
public:
	Doubly_Linked_List()
	{
		front = NULL;
		end = NULL;
	}
	void add_front(int );
	void add_after(node* , int );
	void add_before(node* , int );
	void add_end(int );
	void delete_node(node*);
	void forward_traverse();
	void backward_traverse();
};

void Doubly_Linked_List :: add_front(int d)
{
	// Creating new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = NULL;
	temp->next = front;

	// List is empty
	if(front == NULL)
		end = temp;
		
	else
		front->prev = temp;
		
	front = temp;
}

void Doubly_Linked_List :: add_before(node *n, int d)
{
	node *temp;
	temp = new node();
	temp->data = d;
	temp->next = n;
	temp->prev = n->prev;
	n->prev = temp;

	//if node is to be inserted before first node
	if(n->prev == NULL)
		front = temp;
}

void Doubly_Linked_List :: add_after(node *n, int d)
{
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = n;
	temp->next = n->next;
	n->next = temp;

	//if node is to be inserted after last node
	if(n->next == NULL)
		end = temp;
}

/*
void Doubly_Linked_List :: add_mid(int d, int p)
{
	if(p>1 && p<count())
	{
		p -= 2;
		node *trav, *temp;
		trav = front;
		while(p)
		{
			trav = trav->next;
			p--;
		}
		temp = new node();
		temp->data = d;
		temp->prev = trav;
		temp->next = trav->next;
		trav->next = temp;
	}
	else
		cout<<"\nIncorrect Position\n";
}
*/

void Doubly_Linked_List :: add_end(int d)
{
	// create new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = end;
	temp->next = NULL;

	// if list is empty
	if(end == NULL)
		front = temp;
	else
		end->next = temp;	
	end = temp;
}

void Doubly_Linked_List :: delete_node(node *n)
{	
	// if node to be deleted is first node of list
	if(n->prev == NULL)
	{
		front = n->next; //the next node will be front of list
		front->prev = NULL;
	}
	// if node to be deleted is last node of list
	else if(n->next == NULL)
	{
		end = n->prev;   // the previous node will be last of list
		end->next = NULL;
	}
	else
	{
		//previous node's next will point to current node's next
		n->prev->next = n->next;
		//next node's prev will point to current node's prev
		n->next->prev = n->prev;
	}
	//delete node
	delete(n);			
}

/*void Doubly_Linked_List :: delete_mid(int p)
{
	if(p>1 && p<count())
	{
		p--;
		node *trav;
		trav = front;
		while(p--)
			trav= trav->next;
		trav->prev->next = trav->next;
		trav->next->prev = trav->prev;
		delete(trav);
	}
	else
		cout<<"\nIncorrect Position\n";
}

void doubly_list :: delete_end()
{
	if(end!=NULL)
	{
		end = end->prev;
		delete(end->next);
		end->next = NULL;	
	}
	else
		cout<<"\nList is empty\n";
}*/

void Doubly_Linked_List :: forward_traverse()
{
	node *trav;
	trav = front;
	while(trav != NULL)
	{
		cout<<trav->data<<endl;
		trav = trav->next;
	}
}

void Doubly_Linked_List :: backward_traverse()
{
	node *trav;
	trav = end;
	while(trav != NULL)
	{
		cout<<trav->data<<endl;
		trav = trav->prev;
	}
}


/*int doubly_list :: count()
{
	int c = 0;
	node *trav;
	trav = front;
	while(trav != NULL)
	{
		c++;
		trav = trav->next;
	}
	return c;
}


int main()
{
	doubly_list list;
	int d, choice,p;

	do
	{
		cout<<"\nEnter choice : \n"
			<<"1. Add in front\n"
			<<"2. Add in between\n"
			<<"3. Add at end\n"
			<<"4. Delete front element\n"
			<<"5. Delete middle element\n"
			<<"6. Delete last element\n"
			<<"7. Display list\n"
			<<"8. Number of elements in list\n"
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
				cout<<"Enter the data and position\n";
				cin>>d>>p;
				list.add_mid(d, p);
				break;
			case 3:  
				cout<<"Enter the data\n";
				cin>>d;
				list.add_end(d);	
				break;	
			case 4:
				list.delete_front();
				break;
			case 5:
				cout<<"Enter the position\n";
				cin>>p;
				list.delete_mid(p);
				break;			
			case 6:
				list.delete_end();
				break;
			case 7:
				list.display();
				break;
			case 8:
				cout<<"Number of elements are : "<<list.count()<<endl;
				break;		
			case 0: cout<<"\nTerminating Program\n";
				break;	
			default : cout<<"\nWrong Input\n";	
		}

	}while( choice != 0);
	return 0;
}
*/

int main()
{
	Doubly_Linked_List dl;
	dl.add_front(10);
	dl.add_end(20);
	dl.add_front(5);
	dl.add_end(25);
	dl.forward_traverse();
	dl.backward_traverse();
	return 0;
}






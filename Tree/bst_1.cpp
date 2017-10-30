/** Binary search tree implementation
*   Default  Tree used :
*					50
*				   /   \
*				  30   70
*				 /  \  /   \ 
*				20  40  60  80
*/

#include<iostream>
using namespace std;

struct tree_node
{
	int data;
	tree_node *left, *right;
};

class BST
{
	tree_node *root;
	void insert(tree_node* , int );
	bool search(int , tree_node* );
	void inorder(tree_node* );
	void preorder(tree_node* );
	void postorder(tree_node* );

public:
	
	BST()
	{
		root = NULL;
	}
	void insert(int );
	bool search(int key);
        void inorder();
        void preorder();
        void postorder();
};


// Insert an element into the tree
void BST :: insert(tree_node *node, int d)
{
	if(d < node->data)
	{
		if(node->left != NULL)
			insert(node->left, d);
		else
		{
			node->left = new tree_node;
			node->left->data = d;
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	else if(d >= node->data)
	{
		if(node->right != NULL)
			insert(node->right, d);
		else
		{
			node->right = new tree_node;
			node->right->data = d;
			node->right->left = NULL;
			node->right->right = NULL;
		}
	}
	
}


void BST::insert(int d)
{
  if(root!=NULL)
    insert(root, d);
  else
  {
    root = new tree_node;
    root->data = d;
    root->left = NULL;
    root->right = NULL;
  }
}

bool BST::search(int d, tree_node *node)
{
	bool ans = false;

  	if(node == NULL)
 		return false;

    if(d == node->data)
      return true;
    else if(d < node->data)
      ans = search(d, node->left);
    else
      ans = search(d, node->right);
  
    return ans;
}


bool BST::search(int d)
{
 	return search(d, root);
}

void BST :: preorder(tree_node *node)
{
	if(node != NULL)
	{
		cout<<node->data<<endl;
		preorder(node->left);
		preorder(node->right);
	}
}

void BST :: preorder()
{
	preorder(root);
}

void BST :: postorder(tree_node *node)
{
	if(node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout<<node->data<<endl;
	}
}

void BST :: postorder()
{
	postorder(root);
}

void BST :: inorder(tree_node *node)
{
	if(node != NULL)
	{
		inorder(node->left);
		cout<<node->data<<endl;
		inorder(node->right);
	}
}

void BST :: inorder()
{
	inorder(root);
}


int main()
{
	int choice, d, d2;
	BST btree;
	btree.insert(50);
	btree.insert(30);
	btree.insert(70);
	btree.insert(20);
	btree.insert(40);
	btree.insert(60);
	btree.insert(80);
	do
	{
		cout<<"\n\nEnter Choice :\n"
			"1. Insert element into tree\n"
			"2. Check if element is present\n"
			"3. Inorder traversal\n"
			"4. Postorder traversal\n"
			"5. Preorder traversal\n"
			"0. Exit\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
			cout<<"\nEnter the data : ";
			cin>>d;
			btree.insert(d);
			break;
			case 2:
			cout<<"\n Enter the number to be searched : ";
			cin>>d;
			if(btree.search(d) )
				cout<<"Present\n";
			else
				cout<<"Not found\n";
			break;
			case 3:
			cout<<"Inorder traversal is : \n";
			btree.inorder();
			break;
			case 4:
			cout<<"Postorder traversal is : \n";
			btree.postorder();
			break;
			case 5:
			cout<<"Preorder traversal is : \n";
			btree.preorder();
			break;
			case 0:
			cout<<"\nProgram Terminated\n";
			break;
			default:
			cout<<"\nWrong Input\n";
		}
	}while(choice!=0);
	return 0;
}

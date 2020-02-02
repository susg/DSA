/** Binary tree implementation
*	Following tree is used :
*					1
*				   /  \
*				  2    3
*				 / \
*				4   5
*	- Sushant Gupta
*/				
              
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct tree_node
{
	int data;
	tree_node *left, *right;
};

//creating a node
tree_node *create_node(int d)
{
	tree_node *temp;
	temp = new tree_node;
	temp->data = d;
	temp->left= NULL;
	temp->right = NULL;
	return temp;
}

// Inorder traversal
void inorder(tree_node *node)
{
	if(node == NULL)
		return;
	
	inorder(node->left);           //print left of the node
	cout<<node->data<<endl;		   //visit the node
	inorder(node->right);		   //print right of the tree
}

// Pre-order traversal
void preorder(tree_node *node)
{
	if(node == NULL)
		return;
	cout<<node->data<<endl;				//visit the node
	preorder(node->left);				//print left of the node
	preorder(node->right);				//print right of the tree	
}

//Post order traversal
void postorder(tree_node *node)
{
	if(node == NULL)
		return;
	
	postorder(node->left);					//print left of the node
	postorder(node->right);					//print right of the tree
	cout<<node->data<<endl;					//print right of the tree					
}

// Number of elemnts in tree
int size(tree_node *node)
{
	// if node is null then return size as 0
	if(node == NULL)
		return 0;
	//return size of left tree + size of right tree
	else
		return (size(node->left) + size(node->right) + 1);	
}

// Height of tree
int height(tree_node *node)
{
	// if node is null then return height as 0
	if(node == NULL)
		return 0;
	//height is maximum of right or left subtree
	else	
		return 1 + max(height(node->left), height(node->right));
}

// Finding elements at same level/height
void elements_at_same_level(tree_node *root, int ht)
{
	//base case
	if(root == NULL)
		return;

	//if height is reached, print the element
	if(ht == 1)
	{
		cout<<root->data<<endl;
		return ;
	}
	//else visit left and right subtree and decrease height by 1
	elements_at_same_level(root->left,ht-1);
	elements_at_same_level(root->right,ht-1);	
}

// Level order traversal
void levelorder(tree_node *root)
{
	//print all the elements at same level
	for(int i=1; i<= height(root); i++)
		elements_at_same_level(root, i);
}

/* Example of mirror image of a tree is following :
*	                 1                    1
*				   /  \                  / \
*				  2    3                3   2
*				 / \                       / \ 
*				4   5                     5   4
*/

// Mirror of tree
void mirror(tree_node *node)
{
	//base case
	if(node == NULL)
		return;

	mirror(node-> left);			//find mirrorr of left subtree
	mirror(node->right);			//find mirror of right subtree
	
	//swap the left and right nodes of the current node
	tree_node *temp;				
	temp = node->left;
	node->left = node->right;
	node->right = temp;	
}

// Deleting a tree
void delete_tree(tree_node *node)
{
	if(node == NULL)
		return;
	delete_tree(node->left);    //delete left subtree
	delete_tree(node->right);	//delete right subtree
	cout<<"Deleting element :"<<node->data<<endl;			//delete the current node
	delete(node);
}

// Count number of leaf nodes
int count_leaf_nodes( tree_node *node)
{
	//if its a leaf node then return 1
	if(node->left == NULL && node->right ==NULL)
		return 1;

	//count leaf nodes in left and right subtrees
	return count_leaf_nodes(node->left) + count_leaf_nodes(node->right);
}

// Increment the data of node
void increment(tree_node *node, int val);

// Make the tree satisfy child sum property
/* A tree satisfying child sum property is one in which the sum of left and right datas of a node equals the data of the node */
void child_sum(tree_node *node)
{
	//if leaf node or null node then exit
	if(node == NULL || (node->left == NULL && node->right == NULL))
		return;

	child_sum(node->left);				//make left subtree satisfy child sum property
	child_sum(node->right);				//make right subtree satisfy child sum property

	int left_data=0, right_data=0, diff;

	//store left and right node's data
	if(node->left != NULL)
		left_data = node->left->data;
	if(node->right != NULL)
		right_data = node->right->data;

	diff = left_data + right_data - node->data;
	if(diff >0)
		node->data += diff;				//if node's data is smaller than it is childrem's data then increase it
	else if(diff <0)
		increment(node, -diff);			
}

void increment(tree_node *node, int val)
{
	if(node->left != NULL)
	{
		node->left->data += val;
		increment(node->left, val);
	}
	else if(node->right != NULL)
	{
		node->right->data += val;
		increment(node->right, val);
	}
}

//print the path from root to leaf
void node_to_leaf_path(tree_node *node, vector<int> v)
{
	//if node is a leaf then print the path
	if(node->left == NULL && node->right == NULL)
	{
		v.push_back(node->data);
		for(int i=0; i<v.size(); i++)
			cout<<v[i]<<" -> ";
		cout<<endl;
	}
	//else do a preorder traversal
	else
	{
		v.push_back(node->data);
		node_to_leaf_path(node->left, v);
		node_to_leaf_path(node->right, v);
	}
}

int main()
{
	/***********creating the tree***********/
	tree_node *root;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	
	vector<int> v;
	int choice;
	do {
		/**** The following functions are performed by the tree *******/

		cout<<"\nEnter the choice :\n"
			<<"1. Inorder traversal\n"
			<<"2. Preorder traversal\n"
			<<"3. Postorder traversal\n"
			<<"4. Level order traversal\n"
			<<"5. Number of elements  in tree\n"
			<<"6. Height of tree\n"
			<<"7. Mirror of tree\n"
			<<"8. Delete tree\n"
			<<"9. Make the tree satisfy child sum property\n"
			<<"10. Node to leaf path\n"
			<<"0. Exit\n";
		
		cin>>choice;

		//calling the functions as per choice
		switch(choice)
		{
			case 1:cout<<endl;
			 	inorder(root);
				break;
			case 2:cout<<endl;
				 preorder(root);
				break;
			case 3: cout<<endl;
				postorder(root);
				break;
			case 4:cout<<endl;
				levelorder(root);
				break;				
			case 5: cout<<"\nNumber of elements in tree are "<<size(root)<<endl;
				break;	
			case 6: cout<<"\n Height of tree is :"<<height(root)<<endl;
				break;
			case 7: mirror(root);
				cout<<"\nTree transformed\n";
				break;
			case 8: delete_tree(root);
				break;	
			case 9: child_sum(root);
					cout<<"\nTree changed\n";
					break;	
			case 10: 
					node_to_leaf_path(root, v);
					break;		
			case 0: cout<<"\nTerminating program\n";
				break;
			default : cout<<"\nWrong Input\n";		
		}
	}while(choice != 0);
	return 0;
}

/** Binary tree implementation
*	Following tree is used :
*					1
*				   /  \
*				  2    3
*				 / \  /  \
*				4   5 6   7
*              /       
*             8
*	- Sushant Gupta
*/				


#include<bits/stdc++.h>
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

//Post order traversal
void postorder(tree_node *node)
{
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<endl;	
}

//horizontal distance from root
/*vector<pair< int, int> > v;
void horizontal_dist(tree_node *node, int dist)
{
	if(ndoe == NULL)
		return;
	horizontal_dist(node->left, dist-1);
	horizontal_dist(node->right, dist+1);
	pair<int, int> p;
	p.first = node->data;
	p.second = dist;
	v.push_back(p);
}


void vertical_sum()
{
	
}*/

//heigth of tree
int height(tree_node *node)
{
	if(node == NULL)
		return 0;
	else	
		return 1 + max(height(node->left), height(node->right));
}

// Find the width of each level or the number of elements in a level
void get_width(tree_node *node, int count[], int level)
{
	//base case
	if(node == NULL)
		return ;

	count[level]++;    							//increment count ofnumber of nodes in that level
	get_width(node->left, count, level+1);		//find width of left subtree
	get_width(node->right, count, level+1);		//find width of right subtree
}

/* Create a tree from inorder and preorder traversal*/

//search the index
int search(int in[], int strt, int end, int data)
{
	for(int i= strt; i<= end; i++)
		if(in[i] == data)						//if data is found return the index
			return i;
}

//build the tree
tree_node *build_tree(int in[], int pre[], int strt, int end)
{
	static int preIndex = 0;  	                            //static variable to store the index of preorder traversal
	
	//base case
	if(strt > end)
		return NULL;
	
	tree_node *node = create_node(pre[preIndex++]);			//make the node as root of subtree

	if(strt == end)											//if only only node is there, return it			
		return node;

	int idx = search(in,strt,end, node->data);              //find the index of node in inorder traversal

	node->left = build_tree(in, pre, strt, idx-1);			//make this part as left subtree
	node->right = build_tree(in, pre, idx+1, end);			//make this as right subtree

	return node;
}
/****** end*****/

/**Check for subtree**
Suubtree to be checked is :
		3
	   / \
	  6  7
*/	  

//check if the tree if this node is a subtree
bool are_identical(tree_node *node1, tree_node *node2)
{
	if(node1== NULL && node2 == NULL)             //if both are null then they are identical
		return true;
	
    if(node1== NULL || node2 == NULL)			 // if one is null then not identical
    	return false;

    //check if left and right subtree are identical
	return ((node1->data == node2->data) && are_identical(node1->left, node2->left) && are_identical(node1->left, node2->left));
}

//check if subtree
bool is_subtree(tree_node *node1, tree_node *node2)
{
	if(node2 == NULL)							//null node is a subtree
		return true;

	if(node1 == NULL)							//if primary tree's node is null then it does not have sub tree
		return false;

	if(are_identical(node1, node2))				//check if they are identical with this  node as root
		return true;

	return (is_subtree(node1->left, node2) || is_subtree(node1->right, node2));					//check for left and right subtree
}
/****end***/

/**Diagonal transversal **/

//diagnol transversal of tree
void diagnol_transverse(tree_node *node, int d, map<int , vector<int> > &diagnol_elem)
{
	if(!node)
		return ;

	diagnol_elem[d].push_back(node->data);

	diagnol_transverse(node->left, d+1, diagnol_elem);
	diagnol_transverse(node->right, d, diagnol_elem);
}

//print elements diagoanlly
void print_elements( map<int , vector<int> > &diagnol_elem)
{
	for(auto it = diagnol_elem.begin(); it!= diagnol_elem.end(); it++)
	{	for(auto itr = it.second.begin(); itr != it.second.end(); itr++)
			cout<<*itr<<"\t";
		cout<<endl;
	}		
}
/**end**/
int main()
{
	/***********creating the tree***********/
	tree_node *root;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->right = create_node(7);
	root->right->left = create_node(6);
	root->left->left->left= create_node(8);
	
	/********creating second tree *******/
	tree_node *root3;
	root = create_node(3);
	root->left = create_node(6);
	root->right = create_node(7);

	int choice;
	int ht = height(root);
	int count[ht];
    tree_node *root2;
	int inorder[] = {10, 12, 20, 30, 37, 40, 45};
	int preorder[] = {30, 20, 10, 12, 40, 37, 45};
	map<int ,vector<int> > diagnol_elem;

	do
	{
		cout<<"\nEnter choice : \n"
			<<"1. Number of elements in each level\n"
			<<"2. Build tree using inorder and preorder traversal\n"
			<<"3. Check if Subtree\n"
			<<"4. Print elements diagonally\n"
			<<"0. Exit\n\n";

		cin>>choice;
		switch(choice)
		{
			case 1:  
				memset(count, 0, sizeof(count));
				get_width(root, count, 0);
				for(int i=0; i<ht; i++)
					cout<<i<<" -> "<<count[i]<<endl;
				break;
			case 2:
				root2 = build_tree(inorder, preorder, 0, 6);
				cout<<"\n Tree Created\n";
				postorder(root2);
				break;
			case 3:
				if(is_subtree(root, root3))
					cout<<"\nYes, its a subtree\n";
				else
					cout<<"\nNo, its not a subtree\n";
					break;	
			case 4:
				diagnol_transverse(root, 0, diagnol_elem);
				print_elements(diagnol_elem);
				break;			
			case 0: cout<<"\nTerminating Program\n";
				break;	
			default : cout<<"\nWrong Input\n";	
		}

	}while( choice != 0);
	return 0;
}

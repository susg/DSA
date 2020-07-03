#include <iostream>
#include <map>
using namespace std;

struct Node {
    char data;
     Node* next;
     Node* prev;
};

class DoublyLinkedList {
    Node* head;
    Node* end;

    public:
    map<char, Node*> pos;
    DoublyLinkedList() {
       head = NULL;
       end = NULL; 
       for (char c = 'a'; c <= 'z'; c++)    pos[c] = NULL;
    }

    void delete_node(Node* n);
    void add_node(char c);
    char front();
};

void DoublyLinkedList :: add_node(char c) {
    Node *temp;
    temp = new Node();
    temp->next = NULL;
    temp->data = c;
    temp->prev = end;
    pos[c] = temp;

    if (!head) {
        head = temp;
        end = temp;
    }
    else {
        end->next = temp;
        end = temp;
    }
}

void DoublyLinkedList :: delete_node(Node* n) {
   	// if node to be deleted is first node of list
	if(n->prev == NULL)
	{
		head = n->next; //the next node will be front of list
		if (head)   head->prev = NULL;
        else    end = NULL;
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
    pos[n->data]=NULL;
	delete(n);
}

char DoublyLinkedList :: front() {
    if (head)   return head->data;
    return '#';
}


int firstUniqChar(string S) {
    DoublyLinkedList dll;
    map<char, bool> vis;
    string ans;

    for (auto c : S) {
        //cout << c << endl;
        if (vis[c] && dll.pos[c]) {
            dll.delete_node(dll.pos[c]);
        }
        else {
            if (!vis[c])   dll.add_node(c);
            vis[c] = 1;
        }
        //cout << "ans: " << dll.front() << endl;
        ans.push_back(dll.front());
    }
    for (auto c : ans)  cout << c;
    cout << endl;
    return 0;
}

int main() {
    string s = "jpxvxivxkkthvpqhhhjuzhkegnzqriokhsgea";
    firstUniqChar(s);    
    return 0;
}

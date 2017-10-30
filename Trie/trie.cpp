#include <bits/stdc++.h>
#define BOOSTIO ios_base::sync_with_stdio (false), cin.tie (NULL) 
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
using namespace std;

int n;
int possible=1;
std::vector<string> ans;

struct Node {
    int state, end,type;
    Node *child[26];
};

class Trie {
    Node *root;
    void dfs_util(Node*, string);
public:
    Trie() {
        root = new Node;
        root->state = root->end = root->type=0;
        for(int i=0; i<26; i++)
            root->child[i] = NULL;
    }
    Node *create();
    void insert(string, int);
    void dfs();
};

Node* Trie::create() {
    Node *temp = new Node;
    temp->state = temp->end = temp->type = 0;
    for(int i=0; i<26; i++)
        temp->child[i] = NULL;
    return temp;
}

void Trie::insert(string str, int type) {
    Node *trav = root;
    for(auto c : str) {
        //cout << c << endl;
        int i = c - 'a';
        if(trav->child[i] == NULL) {
            trav->child[i] = create();
            trav->child[i]->state = type;
            //cout << i << " " << type << endl;
        }
        else {
            if(trav->child[i]->state != type)
                trav->child[i]->state = 3;
        }
        trav = trav->child[i];
    }
    trav->end=1;
    if(trav->type == 0)
        trav->type= type;
    else
        possible = 0;
}

void Trie::dfs_util(Node *node, string str) {
    int cnt1=0, cnt=0,cnt2=0;
    for(int i=0; i<26; i++) {
        if(node->child[i] != NULL) {
            cnt++;
            if(node->child[i]->state == 1)
                cnt1++;
            else if(node->child[i]->state == 2)
                cnt2++;
        }    
    }

    if(node ->state == 3) {
        if(node->end == 1 && node->type == 1) {
            possible = 0;
            return;
        }    
    }
    
    if(!cnt) {
        if(node->state == 3)
            possible = 0;
        else if(node->state == 1) {
            str += '\0';
            ans.pb(str);
        }
    }
    else {
        if(node->state == 1) {
            ans.pb(str);
            return;
        }
        else if(node->state == 2)
            return;
        else {
            for(int i=0; i<26; i++){
                if(node->child[i] != NULL){
                    //cout<<"innn\n";
                    str += (char)(i + 'a');
                    //cout << str << endl;
                    dfs_util(node->child[i], str);
                    str.pop_back();
                }
            }
        }
    }
}

void Trie::dfs() {
    dfs_util(root, "");
}

int main() {
	//BOOSTIO;
	cin >> n;
	
    Trie websites;

	for(int i=0; i<n; i++) {
		char c;
		string str;
		cin >> c >> str;
		if(c == '-') {
			websites.insert(str,1);
		}
		else {
			websites.insert(str, 2);
		}
	}	
    websites.dfs();
    if(!possible)
        cout << -1 << endl;
    else {
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for(auto s : ans)
            cout << s << endl;
    }
	return 0;
}
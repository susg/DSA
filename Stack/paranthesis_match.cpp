/*
Given a string with opening and closing brackets.
Find the position of the corresponding closing bracket for given position of opening bracket
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
using namespace std;

vector<int> find_matching_paranthesis(string str, vector<int>& queries) {
    map<int, int> paranthesis_pair;
    stack<int> st;
    bool is_error = 0;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (!st.empty()) {
                int open_pos = st.top();
                st.pop();
                paranthesis_pair[open_pos] = i;
            }
            else {
                is_error = 1;
                break;
            }
        }
        else if (str[i] == '(') {
            st.push(i);
        }
    }

    if (!st.empty()) {
        is_error = 1;
    }

    if (is_error) {
        return vector<int> ();
    }

    vector<int> output;
    for (auto q : queries) output.push_back(paranthesis_pair[q]);
    return output;
}

int main() {
    string str;
    cin >> str;

    int q;
    cin >> q;

    vector<int> queries(q);
    for (int i = 0; i < q; i++)  cin >> queries[i];

    auto output = find_matching_paranthesis(str, queries);
    for (int i = 0; i < output.size(); i++) cout << output[i] << endl;

    return 0;
}

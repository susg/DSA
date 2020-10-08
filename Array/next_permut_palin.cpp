/*
https://www.hackerrank.com/contests/one-last-timeagain/challenges/next-palindrome-1-1
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void display(vector<int> v) {
    for (auto n : v)    cout << n;
    cout << endl;
}

bool next_greater_permutation(vector<int>& v, int start, int end) {
    int left = -1;
    for (int i = end - 1; i >= start; i--) {
        if (v[i] < v[i + 1]) {
            left = i;
            break;
        }
    }

    if (left == -1) return 0;

    for (int i = end; i > left; i--) {
        if (v[i] > v[left]) {
            swap(v[i], v[left]);
            break;
        }
    }

    reverse(v.begin() + left + 1, v.begin() + end + 1);
    return 1;
}

vector<int> find_next_permutation_palindrome(vector<int> v) {
    int mid = v.size() / 2;
    int right_start = v.size() % 2 ? mid + 1 : mid;
    int left_end = mid - 1;

    bool is_valid = next_greater_permutation(v, 0, left_end);
    if (!is_valid) {
        v.clear();
        v.push_back(-1);
        return v;
    }
    display(v);
    while (left_end >= 0)  v[right_start++] = v[left_end--];

    return v;
}

vector<int> convert_string_to_vector(string str) {
    vector<int> v;
    for (auto s : str) {
        v.push_back(s - '0');
    }
    return v;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        display(find_next_permutation_palindrome(convert_string_to_vector(str)));
    }
    return 0;
}

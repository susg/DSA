/*
Given an array of N distinct intergers. Find the sum of the max elements of all subarrays
*/

#include <iostream>
#include <stack>
using namespace std;

void find_next_greater_on_right(int n, int ar[], int next_greater_on_right[]) {
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && ar[st.top()] < ar[i])  st.pop();
        next_greater_on_right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}

void find_next_greater_on_left(int n, int ar[], int next_greater_on_left[]) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && ar[st.top()] < ar[i])  st.pop();
        next_greater_on_left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

int sum_of_max_of_all_subarray(int n, int ar[]) {
    int next_greater_on_right[n], next_greater_on_left[n];
    find_next_greater_on_right(n, ar, next_greater_on_right);
    find_next_greater_on_left(n, ar, next_greater_on_left);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int max_in_subarrays = next_greater_on_right[i] - next_greater_on_left[i] - 1;
        ans += max_in_subarrays * ar[i];
    } 
    return ans;
}

int main() {
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    cout << sum_of_max_of_all_subarray(n, ar) << endl;
}

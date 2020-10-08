/*
https://www.hackerrank.com/contests/rtc-v31/challenges/smallest-palindrome
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool all_nines(vector<int> v) {
    for (auto n : v) {
        if (n != 9) return 0;
    }
    return 1;
} 

vector<int> special_case(vector<int> v) {
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i < v.size(); i++)  ans.push_back(0);
    ans.push_back(1);
    return ans;
}

int incr(int &val) { 
    int carry = 0;
    val++;
    if (val == 10) {
        val = 0;
        carry = 1;
    }
    return carry;
}

vector<int> find_next_smallest_palindrome(vector<int> v) {
    // if all numbers are nine handle it separately: as len of vector will increase
    if (all_nines(v))   return special_case(v);

    int mid = v.size() / 2;
    int i = mid - 1;
    int j = v.size() % 2 ? mid + 1 : mid; // ignore mid element initially in case of odd terms

    // continue till values are equal
    while (i >= 0 and v[i] == v[j]) {
        i--;
        j++;
    }

    // check if left part of mid is smaller
    bool left_smaller = 0;
    if (i < 0 or v[i] < v[j]) left_smaller = 1;
        
    // if left side is larger then just form mirror image and return
    while (i >= 0) v[j++] = v[i--];

    // else increment mid elements by 1 and carry forward the carry
    if (left_smaller) {
        int carry = 1;
        i = mid - 1;
        j = v.size() % 2 ? mid + 1 : mid;
        if (v.size() % 2) {
            carry = incr(v[mid]);
        }
        while (i >= 0) {
            if (carry)  carry = incr(v[i]);
            v[j++] = v[i--];
        }
    }

    return v;
}

vector<int> convert_string_to_vector(string str) {
    vector<int> v;
    for (auto s : str) {
        v.push_back(s - '0');
    }
    return v;
}

void display(vector<int> v) {
    for (auto n : v)    cout << n;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        display(find_next_smallest_palindrome(convert_string_to_vector(str)));        
    }
    return 0;
}

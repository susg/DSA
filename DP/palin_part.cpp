#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


void findPalindromicSubstring(string s, vector< vector<bool> >& isPalin) {
	int n = s.size();

	for (int col = 0; col < n; col++) {
		for (int i = 0, j = col; j < n; i++, j++) {
			if (i == j)
				isPalin[i][j] = 1;
			else if (i == j - 1)
				isPalin[i][j] = (s[i] == s[j]);
			else
				isPalin[i][j] = (s[i] == s[j]) & isPalin[i + 1][j - 1];
		}
	}
}


void findMinCuts(vector<int>& minCuts, vector< vector<bool> >& isPalin) {
	for (int i = 0; i < minCuts.size(); i++) {
		if (isPalin[0][i])
			minCuts[i] = 0;
		else {
			minCuts[i] = i + 1;
			for (int j = i; j > 0; j--) {
				if (isPalin[j][i])
					minCuts[i] = min(minCuts[i], 1 + minCuts[j - 1]);
			}
		}
		cout << i << " " << minCuts[i] << endl;
	}
}



int minCut(string s) {
	int n = s.size();
	
	vector< vector<bool> > isPalin(n);
	for (int i = 0; i <n; i++)	isPalin[i].resize(n, 0);
	findPalindromicSubstring(s, isPalin);
	
	vector<int> minCuts(n);
	findMinCuts(minCuts, isPalin);

	return minCuts[n - 1];
}

int main() {
	string s = "aba";
	cout << minCut(s) << endl;
}
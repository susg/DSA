#include <iostream>
#define MAXN 10
using namespace std;

int main() {
	int mat[MAXN][MAXN] = {0};

	for (int start_col = 0; start_col < MAXN; start_col++) {
		for (int j = start_col, i = 0; j < MAXN; i++, j++) {
			mat[i][j] = 1;
			
		}
	}

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;
}
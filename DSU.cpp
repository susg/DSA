/*
leetcode: Number of islands 2
*/

#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool valid(int x, int y, int n, int m) {
    return (x >= 0 && y >=0 && x < n && y < m);
}

int find(int idx, int par[]) {
    if (par[idx] != idx)
        par[idx] = find(par[idx], par);
    return par[idx];
}

void Union(int x, int y, int par[]) {
    par[y] = par[x];
}

void solve(int n, int m, vector<pair<int, int> >& pos) {
    int grid[n][m], par[n*m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
            par[i*n + j] = i*n + j;
        }
    }

    int cnt = 0;
    for (auto p : pos) {
        cnt++;
        grid[p.first][p.second] = 1;    
        int lin_p = p.first*n + p.second;
        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if (valid(x, y, n, m) && grid[x][y] == 1) {
                int lin_xy = x*n + y;
                if (find(lin_xy, par) != find(lin_p, par)) {
                    cnt--;
                    Union(lin_xy, lin_p, par);
                }
            }
        }
        cout << cnt << endl;
    }

}


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int> > pos(k);
    for (int i = 0; i < k; i++)    cin >> pos[i].first >> pos[i].second;

    solve(n, m, pos);

    return 0;
}
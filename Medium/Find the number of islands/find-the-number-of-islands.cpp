//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find the number of islands.
    void bfs(int start_row, int start_col, vector<vector<char>>& grid, vector<vector<int>>& vis, int& n, int& m) {
        vis[start_row][start_col] = 1;
        queue<pair<int, int>> q;
        q.push({start_row, start_col});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newr = row + i;
                    int newc = col + j;
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && grid[newr][newc] != '0') {
                        vis[newr][newc] = 1;
                        q.push({newr, newc});
                    }
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] != '0') {
                    cnt++;
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
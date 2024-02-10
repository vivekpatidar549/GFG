//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int solve(int i, int j, int n, int m, int maxi, vector<vector<int>>& matrix, vector<vector<int>>& visited,vector<vector<int>>&dp) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1 || maxi >= matrix[i][j]) {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        visited[i][j] = 1;
        int top = 0, bottom = 0, left = 0, right = 0;
        if (maxi == -1 || maxi < matrix[i][j]) {
            top = 1 + solve(i - 1, j, n, m, matrix[i][j], matrix, visited,dp);
            bottom = 1 + solve(i + 1, j, n, m, matrix[i][j], matrix, visited,dp);
            left = 1 + solve(i, j - 1, n, m, matrix[i][j], matrix, visited,dp);
            right = 1 + solve(i, j + 1, n, m, matrix[i][j], matrix, visited,dp);
        }
        visited[i][j] = 0;
        return dp[i][j]= max(top, max(bottom, max(left, right)));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

        // Code here

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, solve(i, j, n, m, -1, matrix, visited,dp));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
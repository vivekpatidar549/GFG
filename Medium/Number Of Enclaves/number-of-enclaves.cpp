//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int visited[n][m] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 ||j==0 ||j== m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
        int delr[4] = {-1, 0, 1, 0}; // Up, Right, Down, Left
        int delc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row+delr[i];
                int newc=col+delc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1  && visited[newr][newc]==0){
                    q.push({newr,newc});
                    visited[newr][newc]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0 ;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    count+=1;
                }
            }
        }
        return count;
            
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
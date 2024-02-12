//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int r[4]={0,0,+1,-1};
  int c[4]={+1,-1,0,0};
  void dfs(int i,int j ,vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>&vec, int r0, int c0 , int n , int m){
      vec.push_back({i-r0,j-c0});
      for(int idx=0;idx<4;idx++){
          int nr=i+r[idx];
          int nc=j+c[idx];
          if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
              vis[nr][nc]=1;
              dfs(nr,nc,grid,vis,vec,r0,c0,n,m);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vis[i][j]=1;
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vis,vec,i,j,n,m);
                    st.insert(vec);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
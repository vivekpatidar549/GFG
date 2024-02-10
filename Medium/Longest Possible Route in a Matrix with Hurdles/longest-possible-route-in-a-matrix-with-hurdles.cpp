//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void solve(vector<vector<int>> matrix, int xs, int ys, int xd, int yd,int count,int &ans){
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(xs < 0 || ys < 0 || xs >= n || ys >= m || !matrix[xs][ys] || !matrix[xd][yd]){
            return;
        }
        
        if(xs == xd && ys == yd){
            ans = max(ans,count);
            return;
        }
        
        matrix[xs][ys] = 0;
        solve(matrix,xs-1,ys,xd,yd,count+1,ans);
        solve(matrix,xs+1,ys,xd,yd,count+1,ans);
        solve(matrix,xs,ys+1,xd,yd,count+1,ans);
        solve(matrix,xs,ys-1,xd,yd,count+1,ans);
        matrix[xs][ys] = 1;
        
    }

    int longestPath(vector<vector<int>>& matrix, int xs, int ys, int xd, int yd)
    {   
        int ans = -1;
        solve(matrix,xs,ys,xd,yd,0,ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
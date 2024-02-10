//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long solve(int i, int j , int n,vector<vector<int>> &arr,int k ,vector<vector<vector<int>>>&dp){
        if(i>=n || j>=n || k<0){
            return 0;
        }
        if(i==n-1 && j==n-1){
            if(k-arr[n-1][n-1]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long right=solve(i,j+1,n,arr,k-arr[i][j],dp);
        long long down=solve(i+1,j,n,arr,k-arr[i][j],dp);
        return dp[i][j][k]= right+down;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        // Code Here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
         return solve(0,0,n,arr,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends
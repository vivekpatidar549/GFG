//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    int solve(int i, int j,int n,vector<vector<int>>&m){
        if(i>=n || i<0 || j<0 || j>=n) return 0;
        
        if(i==n-1){
            return m[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int a=m[i][j]+solve(i+1,j,n,m);
        int b=m[i][j]+solve(i+1,j-1,n,m);
        int c=m[i][j]+solve(i+1,j+1,n,m);
        return dp[i][j]=max(a,max(b,c));
        
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<N;i++){
            ans=max(ans,solve(0,i,N,Matrix));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
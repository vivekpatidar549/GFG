//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    bool solve(int i,int n,int sum,int coins[],vector<vector<int>>&dp){
        if((sum%20==0 || sum%24==0 || sum==2024) && sum!=0){
            return true;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool include=solve(i+1,n,sum+coins[i],coins,dp);
        bool exclude=solve(i+1,n,sum,coins,dp);
        return dp[i][sum]= include || exclude;
    }
    int isPossible(int n , int coins[]) 
    {
        vector<vector<int>>dp(n+1,vector<int>(2025,-1));
        return solve(0,n,0,coins,dp);
    }
    
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends
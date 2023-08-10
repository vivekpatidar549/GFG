//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solve(int n, int m, string &s1, string &s2, vector<vector<int>> &dp, int len1,int len2){
        if(n>=len1 || m>=len2) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s1[n]==s2[m]) return dp[n][m]= 1+solve(n+1,m+1,s1,s2,dp, len1,len2);
        
        return dp[n][m]= 0 + max(solve(n+1,m,s1,s2,dp,len1,len2) , solve(n,m+1,s1,s2,dp,len1,len2));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s1,s2,dp, n,m);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
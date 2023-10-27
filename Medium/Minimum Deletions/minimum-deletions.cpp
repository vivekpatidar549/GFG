//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int solve(string &s1, string& s2, int i,int j,int n,vector<vector<int>>&dp){
      if(i>=n || j>=n){
          return 0;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s1[i]==s2[j]) return dp[i][j]= 1 + solve(s1,s2,i+1,j+1,n,dp);
      return dp[i][j]= max(solve(s1,s2,i+1,j,n,dp), solve(s1,s2,i,j+1,n,dp));
  }
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        string s1=S;
        reverse(s1.begin(),s1.end());
        int k=solve(S,s1,0,0,n,dp);
        return n-k;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
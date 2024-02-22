//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
const int M = 1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
      vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
      return f(0,0,s,t,dp);
    }
    int f(int i,int j,string &s,string &t,vector<vector<int>> &dp){
        int n = s.length(), m = t.length();
        if(j==m) return 1;
        if(i==n) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int match=0;
        if(s[i]==t[j]){
            match = f(i+1,j+1,s,t,dp);
        }
        int mismatch = f(i+1,j,s,t,dp);
        
        return dp[i][j] = (match + mismatch)%M;
    }
};


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
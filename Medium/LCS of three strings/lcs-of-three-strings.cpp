//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int solve(string &A, string &B, string &C, int i, int j, int k, int n1, int n2, int n3,vector<vector<vector<int>>>&dp) {
        if (i == n1 || j == n2 || k == n3) {
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        if (A[i] == B[j] && B[j] == C[k]) {
            return 1 + solve(A, B, C, i + 1, j + 1, k + 1, n1, n2, n3,dp);
        }

        int option1 = solve(A, B, C, i + 1, j, k, n1, n2, n3,dp);
        int option2 = solve(A, B, C, i, j + 1, k, n1, n2, n3,dp);
        int option3 = solve(A, B, C, i, j, k + 1, n1, n2, n3,dp);

        return dp[i][j][k]= max({option1, option2, option3});
    }

    int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3,-1)));
        return solve(A, B, C, 0, 0, 0, n1, n2, n3,dp);
    }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
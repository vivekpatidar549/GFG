//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i,int price[], int buy, int cap,vector<vector<vector<int>>>&dp, int n){
            if(cap==0 || i==n) return 0;
            if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
            int res=0;
            if(buy){
                res=max(-price[i]+solve(i+1,price,0,cap,dp,n),0+solve(i+1,price,1,cap,dp,n));
            }
            else{
                res=max(price[i]+solve(i+1,price,1,cap-1,dp,n),0+solve(i+1,price,0,cap,dp,n));

            }
            return dp[i][buy][cap]=res;
        }
        
    int maxProfit(int k, int n, int A[]) {
        // code here
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
            return solve(0,A,1,k,dp,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends
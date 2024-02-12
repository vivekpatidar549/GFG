//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    ll solve(int i,vector<long long>&prices, int buy, int &fee,vector<vector<ll>>&dp){
        if(i==prices.size()) return 0;
        ll res=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            res=max(-prices[i]+solve(i+1,prices,0,fee,dp),0+solve(i+1,prices,1,fee,dp));
        }
        else{
            res=max((prices[i]-fee)+solve(i+1,prices,1,fee,dp),0+solve(i+1,prices,0,fee,dp));

        }
        return dp[i][buy]= res;
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<ll>>dp(n+1,vector<ll>(2,-1));
        return solve(0,prices,1,fee,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
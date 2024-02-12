//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<vector<long long>>dp;
    long long solve(int i, int buy,vector<long long>&price){
        if(i>=price.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        long long profit=0;
        if(buy){
            profit=max(-price[i]+solve(i+1,0,price),solve(i+1,1,price));
        }
        else{
            profit=max(price[i]+solve(i+2,1,price),solve(i+1,0,price));
        }
        return dp[i][buy]=profit;
    }
    
    long long maximumProfit(vector<long long>&price, int n) {
        // Code here
        dp.resize(n,vector<long long>(2,-1));
        return solve(0,1,price);
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
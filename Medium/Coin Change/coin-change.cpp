//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution {
  public:
    
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<ll>> dp(N,vector<ll>(sum+1,0));
        for(int i=1;i<=sum;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=1;
        }
        
        for(int i=0;i<N;i++)
        dp[i][0]=1;
        
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                ll a,b;
                a=b=0;
                
                a=dp[i-1][j];
                if(j>=coins[i])
                b=dp[i][j-coins[i]];
                
                dp[i][j]=(a+b);
            }
        }
        
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
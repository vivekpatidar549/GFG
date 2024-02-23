//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&Arr){
            //Write your code here..
            int n=Arr.size();
            vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

            for (int ind = n - 1; ind >= 0; ind--) {
                for (int buy = 0; buy <= 1; buy++) {
                    for (int cap = 1; cap <= 2; cap++) {
                        if (buy == 0) { // We can buy the stock
                            dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                                   -Arr[ind] + dp[ind + 1][1][cap]);
                        }
        
                        if (buy == 1) { // We can sell the stock
                            dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                                   Arr[ind] + dp[ind + 1][0][cap - 1]);
                        }
                    }
                }
            }
    return dp[0][0][2];
            
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int i, int buy,vector<int>&price){
        if(i==price.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-price[i]+solve(i+1,0,price),solve(i+1,1,price));
        }
        else{
            profit=max(price[i]+solve(i+1,1,price),solve(i+1,0,price));
        }
        return dp[i][buy]=profit;
    }
    
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        dp.resize(n,vector<int>(2,-1));
        return solve(0,1,prices);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
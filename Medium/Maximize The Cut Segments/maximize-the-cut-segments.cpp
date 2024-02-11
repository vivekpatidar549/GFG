//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

#include <vector>
#include <algorithm> // Include algorithm header for std::max
#include <climits> // Include climits header for INT_MIN

class Solution {
public:
    // Function to find the maximum number of cuts.
     int solveMem(int n, int x, int y, int z, vector<int> &dp) {
        if(n < 0) return INT_MIN;
        
        if(n == 0) return 0;
        
        if(dp[n] != INT_MIN) return dp[n];
        
        int a = solveMem(n-x, x, y, z, dp) + 1;
        int b = solveMem(n-y, x, y, z, dp) + 1;
        int c = solveMem(n-z, x, y, z, dp) + 1;
        
        return dp[n] = max(a, max(b, c));
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> dp(n+1, INT_MIN);
        int ans = solveMem(n, x, y, z, dp);
        return ans < 0 ? 0 : ans; 
    }
};




//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
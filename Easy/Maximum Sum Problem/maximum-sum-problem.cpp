//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int solve(int num){
        if(num <= 0)
         return 0;
         int sum = num;
         int first = solve(num/2);
         int second = solve(num/3);
         int third = solve(num/4);
         int ans = max(sum,first + second + third);
         return ans;
    }
        int maxSum(int n)
        {
            //code here.
            return solve(n);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
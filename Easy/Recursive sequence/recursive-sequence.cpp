//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        int mod = 1e9 + 7;
        int cnt = 0;
        long long ans = 0;
        for(int i=1; i<=n; i++)
        {
            long long int temp = 1;
            for(int j=1; j<=i; j++)
            {
                cnt++;
                temp = (temp * cnt) % mod;
            }
            ans = (ans + temp) % mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long getVal(int N, int A[]) {
        // code here
        long long prod=1;
         int g=A[0];
        for(int i=0;i<N;i++){
            prod=(prod*A[i])%1000000007;
            g=__gcd(A[i],g);
        }
        
    
            
        long long ans=1;
        while(g--){
            ans=(ans*prod)%1000000007;
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.getVal(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends
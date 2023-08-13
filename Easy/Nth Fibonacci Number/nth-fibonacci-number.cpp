//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        vector<int> fbn;
        fbn.push_back(0);
        fbn.push_back(1);
        
        for(int i=2; i<n+1; i++){
            fbn.push_back((fbn[i-1] + fbn[i-2])%1000000007);
        }
        
        return fbn[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
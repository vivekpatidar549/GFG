//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int TotalWays(int n) {
        long long int MOD = 1e9 + 7;
        if (n == 1) return 4;
        if (n == 2) return 9;
        int prev1 = 2;
        int prev2 = 3;
        int current = 0;
        for (int i = 3; i <= n; i++) {
            current = (prev1 + prev2+MOD) % MOD;
            prev1 = prev2;
            prev2 = current;
        }
        return ((current%MOD) * (current%MOD)) % MOD;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
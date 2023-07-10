//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int getSingle(int arr[], int n) {
	    // code here
	    if (n==1){
            return arr[0];
        }
	    sort(arr,arr+n);
        int i=0;
        int ans;
        while(i+1<=n &&i<n){
            if(arr[i]==arr[i+1]){
                i=i+2;
            }
            if(i+1 <=n && arr[i]!=arr[i+1]){
                ans=arr[i];
                i=i+1;
            }

        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getSingle(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
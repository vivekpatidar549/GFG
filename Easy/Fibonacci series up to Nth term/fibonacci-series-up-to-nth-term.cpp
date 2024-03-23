//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        if(n==1) return {0,1};
        vector<int>ans;
        int first=0;
        int second=1;
        ans.push_back(first);
        ans.push_back(second);
        int third;
        for(int i=0;i<n-1;i++){
            third=(first+second)%1000000007;
            ans.push_back(third);
            int temp=second;
            second=third;
            first=temp;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
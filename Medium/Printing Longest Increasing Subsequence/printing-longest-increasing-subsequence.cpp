//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int lastchoosenidx=0;
        int maxlen=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                    if(dp[i]>maxlen){
                        maxlen=dp[i];
                        lastchoosenidx=i;
                    }

                }
            }
        }

        vector<int>res;
        while(lastchoosenidx!=-1){
            res.push_back(nums[lastchoosenidx]);
            lastchoosenidx=prev[lastchoosenidx];
        }
        sort(res.begin(),res.end());
        return res;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
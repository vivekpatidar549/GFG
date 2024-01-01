//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if (nums.size() % 2 == 1) {
            return false;
        }

        unordered_map<int, int> maps;

        for (int i = 0; i < nums.size(); i++) {
            maps[nums[i] % k]++;
        }

        if (maps[0] % 2 == 1) {
            return false;
        }

        for (auto it : maps) {
            if (it.second != maps[(k - it.first) % k]) {
                return false;
            }
        }

        return true;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
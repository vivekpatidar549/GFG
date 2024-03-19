//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
#include <vector>
using namespace std;

class Solution {
public:
    void rearrange(int arr[], int n) {
        // code here
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }
        int i = 0;
        int j = 0;
        int idx = 0;
        bool check = true;
        int s1 = pos.size();
        int s2 = neg.size();
        while (i < s1 && j < s2) {
            if (check == true) {
                arr[idx++] = pos[i++];
                check = false;
            } else {
                arr[idx++] = neg[j++];
                check = true;
            }
        }
        while (i < s1) {
            arr[idx++] = pos[i++];
        }
        while (j < s2) {
            arr[idx++] = neg[j++];
        }
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
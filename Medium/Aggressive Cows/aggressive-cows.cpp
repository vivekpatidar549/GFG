//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution {
public:
    bool possibleanswer(vector<int>&stalls , int k,int mid,int n){
    int cow=1;
    int cowposition = stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-cowposition>=mid){
            cow++;
            if(cow==k){
                return true;
            }
            cowposition = stalls[i];

        }
    }
    return false;
}

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
    sort(stalls.begin(), stalls.end());
    int start =0;
    int end=stalls[n-1];
    int ans=0;

    int mid=start+(end-start)/2;
    while(start<=end){
        if(possibleanswer(stalls,k,mid,n)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
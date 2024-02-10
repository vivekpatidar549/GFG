//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_set<int> seen;

    void recamanSequenceHelper(int n, vector<int> &ans, int current, int index){
        if(index == n){
            return;
        }
        
        if(current - index > 0 && seen.find(current  -index) == seen.end()){
            ans.push_back(current - index);
            seen.insert(current - index);
            recamanSequenceHelper(n, ans, current - index, index+1);
        } else {
            ans.push_back(current + index);
            seen.insert(current + index);
            recamanSequenceHelper(n, ans, current + index, index+1);
        }
        return;
    }

    vector<int> recamanSequence(int n){
        vector<int> ans;
        ans.push_back(0);
        
        seen.insert(0);
        
        recamanSequenceHelper(n, ans, 0, 1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
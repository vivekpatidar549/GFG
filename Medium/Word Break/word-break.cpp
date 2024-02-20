//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    unordered_set<string> s;

    bool solve(int i, string &B, int &n) {
        if (i >= n) return true;
        if (s.find(B.substr(i)) != s.end()) {
            return true;
        }
        for (int idx = 1; idx <= n - i; idx++) {
            string temp = B.substr(i, idx);
            if (s.find(temp) != s.end() && solve(i + idx, B, n)) {
                return true;
            }
        }
        return false;
    }

    int wordBreak(string A, vector<string> &B) {
        for (auto it : B) {
            s.insert(it);
        }
        int n = A.size();
        return solve(0, A, n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
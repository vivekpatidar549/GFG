//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkPossible(string &s1, string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int f=0;
        int s=0;
        while(f<s1.size()){
            if(s<s2.size() && s1[f]==s2[s]){
                f++;
                s++;
            }
            else{
                f++;
            }
            
        }
        if(f == s1.size() && s == s2.size()) return true;
        else return false; 
    }
   static bool cmp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    int longestChain(int n, vector<string>& arr) {
        // Code here
        sort(arr.begin(),arr.end(),cmp);
        vector<int>dp(n+1,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(checkPossible(arr[i],arr[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends
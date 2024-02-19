//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char,int>maps;
        for(int i=0;i<s.size();i++){
            maps[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto it:maps) pq.push(it.second);
        while(k--){
            int top=pq.top();
            pq.pop();
            pq.push(top-1);
        }
        int ans=0;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            ans+=ele*ele;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
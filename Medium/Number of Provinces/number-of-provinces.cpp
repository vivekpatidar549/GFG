//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int i , int visited[],  map<int,list<int>>&maps){
        visited[i]=1;
        for(auto it:maps[i]){
            if(visited[it]==0){
                solve(it,visited,maps);
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        map<int,list<int>>maps;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                if(adj[i][j]==1){
                    maps[i].push_back(j);
                    maps[j].push_back(i);
                }
            }
        }
        int visited[n]={0};
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                solve(i,visited,maps);
                ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
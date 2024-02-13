//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// make all path which a
class Solution {
  public:
    bool dfs(int node, vector<int>adj[], int vis[], int pathvis[], int check[]){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathvis[it]){
                    check[node]=0;
                    return true;
                }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        int vis[n]={0};
        int pathvis[n]={0};
        int check[n]={0};
        vector<int>res;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1) res.push_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
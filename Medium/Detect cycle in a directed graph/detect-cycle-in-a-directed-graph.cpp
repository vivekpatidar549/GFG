//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool check(int i,vector<int> adj[],vector<int>&vis, vector<int>&pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(check(it,adj,vis,pathvis)==true) return true;
            }
            else if(pathvis[it]==1) return true;
        }
        pathvis[i]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V);
        vector<int>pathvis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(check(i,adj,vis, pathvis)) return true;
            }
        }
        return false;
        
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
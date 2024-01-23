//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  bool iscycle(int u,vector<bool>&vis,vector<bool>&rec,vector<int>adj[],stack<int>&st){
      vis[u]=true;
      rec[u]=true;
      for(auto &v:adj[u]){
          if(!vis[v] && iscycle(v,vis,rec,adj,st)) return true;
          if(rec[v]==true) return true;
      }
      rec[u]=false;
      st.push(u);
      return false;
      
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[n+1];
        for(auto &x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<bool>vis(n,false);
        vector<bool>rec(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]&& iscycle(i,vis,rec,adj,st)) return {};
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
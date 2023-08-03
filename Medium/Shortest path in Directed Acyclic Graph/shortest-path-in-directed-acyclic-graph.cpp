//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void getshortestpath(int source,vector<int> & ans, stack<int> &s , int n, unordered_map<int, list<pair<int,int>>> &adj){
        ans[source]=0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(ans[top]!=INT_MAX){
                for(i : adj[top]){
                    if(ans[top]+i.second < ans[i.first]){
                        ans[i.first]= ans[top]+i.second;
                    }
                }
                
            }
            
            
        }
        
    }
    void topo(unordered_map<int, list<pair<int,int>>> &adj, stack<int> & s , int node,unordered_map<int, bool>&visited ){
        visited[node]= true;
        for(auto i : adj[node]){
            if(!visited[i.first]){
                topo(adj,s,i.first,visited);
            }
        }
        s.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int n = edges.size();
        vector<int> ans(N, INT_MAX);
        unordered_map<int, list<pair<int,int>> > adj;
        unordered_map<int, bool> visited;
        stack<int>s;
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v= edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
              topo(adj,s,i, visited);  
            }
        }
        
        getshortestpath(0,ans,s,n , adj); // 0 is source
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX){
                ans[i]= -1;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
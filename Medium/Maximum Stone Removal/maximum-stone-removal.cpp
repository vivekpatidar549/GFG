//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
  vector<int>parent,rank,size;
  public:
  DisjointSet(int n){
      parent.resize(n+1);
      rank.resize(n+1,0);
      size.resize(n+1,1);
      for(int i=0;i<=n;i++) parent[i]=i;
  }
  
  int findUpar(int node){
    if(node==parent[node]){
      return node;
    }
    return parent[node]=findUpar(parent[node]);
  }
  void unionByRank(int u, int v){
      int ulp_u=findUpar(u);
      int ulp_v=findUpar(v);
      if(ulp_u==ulp_v) return;
      if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=ulp_v;
      }
      else if(rank[ulp_v]<rank[ulp_u]){
        parent[ulp_v]=ulp_u;
      }
      else{
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
      }
    }
    void unionBySize(int u,int v){
       int ulp_u=findUpar(u);
       int ulp_v=findUpar(v);
       if(ulp_u==ulp_v) return;
       if(size[ulp_u]<size[ulp_v]){
         parent[ulp_u]=ulp_v;
         size[ulp_v]+=size[ulp_u];
       }
       else{
         parent[ulp_v]=ulp_u;
         size[ulp_u]+=size[ulp_v];
       }
     } 
      
  
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>uniq;
        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxrow+1;
            ds.unionBySize(nodeRow,nodeCol);
            uniq[nodeRow]=1;
            uniq[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:uniq){
            if(ds.findUpar(it.first)==it.first) cnt++;
        }
        return n-cnt;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends
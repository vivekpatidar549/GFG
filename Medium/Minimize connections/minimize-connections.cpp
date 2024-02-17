//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    public:
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

class Solution{
    public:
        int minimumConnections(int n , vector<vector<int>> &edge)
        {
            // code here
            DisjointSet ds(n);
            int countextra=0;
            for(auto it:edge){
                int u=it[0];
                int v=it[1];
                if(ds.findUpar(u)==ds.findUpar(v)){
                    countextra++;
                }
                else{
                    ds.unionBySize(u,v);
                }
            }
            int cntC=0;
            for(int i=0;i<n;i++){
                if(i==ds.parent[i])cntC++;
            }
            int ans=cntC-1;
            if(countextra>=ans) return ans;
            return -1;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> connections(m,vector<int> (2));
        for(auto &j:connections)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(n,connections)<<endl;
    }
    return 0;
}
// } Driver Code Ends
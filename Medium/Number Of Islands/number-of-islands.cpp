//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
class DisjointSet{
    vector<int>parent,rank,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]= findUpar(parent[node]);
    }
    
    void unionBySize(int node1, int node2){
        int node1p=findUpar(node1);
        int node2p=findUpar(node2);
        if(node1p==node2p) return;
        if(size[node1p]>size[node2p]){
            parent[node2p]=node1p; // Update parent of node2's representative to node1's representative
            size[node1p]+=size[node2p]; // Update size of node1's representative
        }
        else{
            parent[node1p]=node2p; // Update parent of node1's representative to node2's representative
            size[node2p]+=size[node1p]; // Update size of node2's representative
        }
}

    
    
};

bool isvalid(int i , int j, int n, int m){
	if(i>=0 && i<n && j>=0 && j<m ){
		return  true;
	}
	return false;
}

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &arr) {
        // code here
        vector<int>ans;
	DisjointSet ds(n*m+1);
	int vis[n][m];
	memset(vis,0,sizeof vis);
	int cnt=0;
	int dr[]={-1,1,0,0};
	int dc[]={0,0,1,-1};
	for(auto it:arr){
		int row=it[0];
		int col=it[1];
		if(vis[row][col]==1){
			ans.push_back(cnt);
			continue;
		}
		vis[row][col]=1;
		cnt++;
		// row-1 col
		// row,col+1
		//row+1,col
		// row,col+1
		for(int idx=0;idx<4;idx++){
			int nr=row+dr[idx];
			int nc=col+dc[idx];
			if(isvalid(nr,nc,n,m)){
				if(vis[nr][nc]==1){
					int nodeNo=row*m+col;
					int adjNodeno=nr*m+nc;
					if(ds.findUpar(nodeNo)!=ds.findUpar(adjNodeno)){
						cnt--;
						ds.unionBySize(nodeNo,adjNodeno);
					}
				}
			}
		}
		ans.push_back(cnt);
		
	}






	return ans;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
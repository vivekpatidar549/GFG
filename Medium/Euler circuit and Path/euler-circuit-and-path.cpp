//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void dfs(int u ,vector<int>adj[], vector<int>&visited ){
        visited[u]=1;
        for(auto it:adj[u]){
            if(visited[it]==0){
                dfs(it,adj,visited);
            }
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    vector<int>visited(V+1,0);
	    dfs(0,adj,visited);
	    for(int i=0;i<V;i++){
	        if(visited[i]==0 && adj[i].size()>0){
	            return 0;  // as graph is not connected
	        }
	    }
	    int count=0;
	    for(int i=0;i<V;i++){
	        if(adj[i].size()%2==1){
	            count++;
	        }
	    }
	    if(count>2){
	        return 0;
	    }
	    if(count==2){
	        return 1;
	    }else{
	        return 2;
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
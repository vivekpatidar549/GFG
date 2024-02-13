//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check (int i, vector<int>&color, vector<int>adj[]){
        color[i]=0;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int parent=q.front();
            q.pop();
            for(auto neigh:adj[parent]){ // Change adj[i] to adj[parent]
                if(color[neigh]==-1){
                    color[neigh]=!color[parent];
                    q.push(neigh);
                }
                else if(color[neigh]==color[parent]){
                    return false; // Return false if neighbor has same color as parent
                }
            }
        }
        return true;
    }
    bool isBipartite(int n, vector<int>adj[]){
        // Code here
        vector<int>colored(n,-1);
        for(int i=0;i<n;i++){
            if(colored[i]==-1){
                if(check(i,colored,adj)==false) return false;
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
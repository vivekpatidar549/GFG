//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dis(n,1e18);
        vector<long long>ways(n,0);
        int mod=(int)1e9+7;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dist=it.first;
            int node=it.second;
            for(auto itr:adj[node]){
                int adjNode=itr.first;
                long long adjDis=itr.second;
                // first way coming
                if(dist + adjDis < dis[adjNode]){
                    dis[adjNode] = dist + adjDis;
                    pq.push({dist + adjDis, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist + adjDis == dis[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }

            }
        }
        return ways[n-1]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
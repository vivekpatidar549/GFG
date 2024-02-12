//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        pair<int,int>src;
        pair<int,int>dest;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    src={i,j};
                }
                else if(grid[i][j]==2){
                    dest={i,j};
                }
            }
        }
        int r[4]={-1,+1,0,0};
        int c[4]={0,0,-1,+1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push(src);
        vis[src.first][src.second]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nwr=x+r[i];
                int nwc=y+c[i];
                if(nwr==dest.first && nwc==dest.second) return true;
                if(nwr>=0 && nwr<n && nwc>=0 && nwc<m && grid[nwr][nwc]!=0 && vis[nwr][nwc]==0){
                    vis[nwr][nwc]=1;
                    q.push({nwr,nwc});
                }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans(image.begin(),image.end());
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        int r[4] = {-1, +1, 0, 0};
        int c[4] = {0, 0, -1, +1};
        while (!q.empty()) {
            int row = q.front().first;           
            int col = q.front().second;
            q.pop();
            ans[row][col] = nc; 
            for (int i = 0; i < 4; i++) {
                int newr = row + r[i];
                int newc = col + c[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && image[newr][newc] == image[sr][sc]) {
                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
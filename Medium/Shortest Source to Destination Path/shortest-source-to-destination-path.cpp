//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(X==0 && Y==0) return 0;
        vector<vector<bool> > visited(N,vector<bool>(M,false));
        queue<pair<int,int>> q;
        pair<int,int> p = make_pair(0,0);
        q.push(p);
        visited[0][0]= true;
        int steps=0;
        int drow[]={1,0,-1,0};
        int dcol[]= {0,1,0,-1};
        while(!q.empty()){
            int size= q.size();
            while(size--){
                int row= q.front().first;
                int col = q. front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol = col + dcol[i];
                    if(nrow>=0 && nrow<N && ncol >=0 && ncol<M && visited[nrow][ncol]==false && A[nrow][ncol]==1){
                        if(nrow==X && ncol==Y){
                            return steps+1;
                        }
                        q.push({nrow, ncol});
                        visited[nrow][ncol]= true;
                        
                        
                    }
                }
                
                
            }
            steps+=1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
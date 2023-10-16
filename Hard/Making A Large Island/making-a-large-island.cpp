//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int help_me(vector<vector<int>>&grid,int &c,int i,int j){
        int n=grid.size();
        int count=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=c;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            count++;
            q.pop();
            for(int p=0;p<4;p++){
                int ni=x+dx[p];
                int nj=y+dy[p];
                if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                    grid[ni][nj]=c;
                    q.push({ni,nj});
                }
            }
        }
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int c=2;
        unordered_map<int,int>mp;
        mp[0]=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mp[c]=help_me(grid,c,i,j);
                    c++;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int c=1;
                    unordered_set<int>s;
                    for(int p=0;p<4;p++){
                    int ni=i+dx[p];
                    int nj=j+dy[p];
                        if(ni>=0 && nj>=0 && ni<n && nj<n){
                            s.insert(grid[ni][nj]);
                        }
                    }
                    for(auto &it:s)c+=mp[it];
                    ans=max(ans,c);
                }
            }
        }
        if(ans==INT_MIN)return n*n;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends
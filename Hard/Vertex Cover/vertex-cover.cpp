//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int ans;
        void helper(int index,int n,vector<pair<int, int>> &edges,unordered_set<int>&st){
            if(index>n){
             for(auto it:edges){
                 if(st.find(it.first)==st.end()&&st.find(it.second)==st.end())
                 return;
             }   
             ans=(st.size()<ans)?st.size():ans;
             return;
            }
            helper(index+1,n,edges,st);
            st.insert(index);
            helper(index+1,n,edges,st);
            st.erase(index);
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                ans=n;
                unordered_set<int>st;
                helper(1,n,edges,st);
                return ans;
            }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends
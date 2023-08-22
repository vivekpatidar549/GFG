//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int rs[n]={0};
        int cs[n]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                rs[i]+=matrix[i][j];
                cs[j]+= matrix[i][j];
            }
        }
        int maxi= INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,max(rs[i],cs[i]));
        }
        
        for(int i=0;i<n;i++){
            rs[i]= maxi-rs[i];
            cs[i]=maxi-cs[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int mini=min(rs[i],cs[j]);
                ans+=mini;
                rs[i]-=mini;
                cs[j]-=mini;
            }
        }
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
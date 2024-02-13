//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &mat, int n, int m)
        {
            // your code here
            int ans=0;
            int count=0;
            for(int i=0;i<n;i++){
                int temp=0;
                for(int j=0;j<m;j++){
                    if(mat[i][j]==0){
                        temp++;
                    }else{
                        break;
                    }
                }
                if(count<m-temp){
                    ans=i;
                    count=m-temp;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends
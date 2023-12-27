//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        //first half
        for(int j=0;j<m;j++){
            int row=0;
            int col=j;
            while(row<n && col >=0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        // traverse left part
        for(int i=1;i<n;i++){
            int row=i;
            int col=m-1;
            while(row<n && col >=0){
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
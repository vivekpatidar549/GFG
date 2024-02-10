//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  vector<int> matrix1d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix1d.push_back(mat[i][j]);
        }
    }

    sort(matrix1d.begin(), matrix1d.end());

    for (int i = 0; i < (n * n); i++) {
        if (i == k - 1) {
            return matrix1d[i];
        }
    }
    return -1;
}

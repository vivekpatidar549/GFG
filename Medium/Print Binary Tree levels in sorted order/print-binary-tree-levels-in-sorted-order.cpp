//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        // Your code here
        vector<vector<int>>ans;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            while(size--){
                int top=q.front();
                q.pop();
                temp.push_back(arr[top]);
                if((2*top+1)<n) q.push(2*top+1);
                if((2*top)+2<n) q.push(2*top+2);
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends
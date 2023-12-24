//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        return a.second<b.second;
    }
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        int count=0;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(i+1,price[i]));
        }
        sort(temp.begin(),temp.end(),cmp);
        int i=0;
        while (k >= 0 && i < n) {
             while (temp[i].first > 0 && k >= temp[i].second) {
                count++;
                k -= temp[i].second;
                temp[i].first--;
            }
            i++;
}
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
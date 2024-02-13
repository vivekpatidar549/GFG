//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int>lis(n,1);
	    vector<int>lds(n,1);
	    
	    for(int i=0;i<n;i++){
	        for(int prev=0;prev<i;prev++){
	            if(nums[i]>nums[prev] && lis[prev]+1>lis[i]){
	                lis[i]=lis[prev]+1;
	            }
	        }
	    }
	    
	    for(int i=n-1;i>=0;i--){
	        for(int prev=n-1;prev>i;prev--){
	            if(nums[i]>nums[prev] && lds[prev]+1>lds[i]){
	                lds[i]=lds[prev]+1;
	            }
	        }
	    }
	     int res=-1;
	     for(int i=0;i<n;i++){
	         res=max(res,(lis[i]+lds[i]-1));
	     }
	     return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
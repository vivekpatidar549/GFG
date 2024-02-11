//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int a[], int n, int x)
    {
        // Your code goes here  
        int count=1;
        int ans=INT_MAX;
        int l=0;int h=0;
        int csum=0;
        csum=a[l];
        while(l<=h && h<n){
            if(csum >x){
                ans=min(ans,count);
                csum=csum-a[l];
                count--;
                l++;
            }
            else if(csum<=x){
                h++;
                csum+=a[h];
                count++;
            }
        }
        if(ans==INT_MAX){
            ans=0;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        const int mod = 1000000007;
        vector<unsigned long long> catalan(n+1,0);
        catalan[0]=catalan[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                catalan[i]=(catalan[i]+(catalan[j]*catalan[i-j-1])%mod)%mod;
            }
        }
        return catalan[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
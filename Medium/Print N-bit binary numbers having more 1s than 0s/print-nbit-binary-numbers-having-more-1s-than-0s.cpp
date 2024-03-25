//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(int i,int n, string temp, vector<string>&ans, int ones, int zeroes){
        if(zeroes>ones) return;
        if(i==n){
            if(zeroes<=ones){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back('1');
        solve(i+1,n,temp,ans,ones+1,zeroes);
        temp.pop_back();
        temp.push_back('0');
        solve(i+1,n,temp,ans,ones,zeroes+1);
        
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	   string temp;
	   vector<string>ans;
	   solve(0,n,temp,ans,0,0);
	   return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
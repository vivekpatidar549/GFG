//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int  find_and(int left, int right ) 
    {
        // Code here.
        int shiftcount=0;
        while(left!=right){
            // longest commom prefix;
            left=left>>1;
            right=right>>1;
            shiftcount++;
        }
        return left<<shiftcount;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int  l, r;
    	cin >> l >> r;
    	Solution ob;
    	int ans = ob.find_and(l, r);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends
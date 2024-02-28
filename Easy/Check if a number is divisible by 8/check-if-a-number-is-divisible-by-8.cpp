//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if(s.size()<3){
            return stoi(s)%8==0?1:-1;
        }
        else{
            int num=stoi(s.substr(s.size()-3,3));
            if(num==0) return 1;
            return num%8==0?1:-1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
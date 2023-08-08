//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int gcdof(int a, int b){
        if(b==0) return a;
        return gcdof(b,a%b);
    }
    int countFractions(int n, int numerator[], int denominator[])
    {
        
        int ans=0;
        map<pair<int,int> , int> mp;
        for(int i=0;i<n;i++){
            int gcd= gcdof(numerator[i],denominator[i]);
            int x= numerator[i]/=gcd;
            int y= denominator[i]/=gcd;
            int z= y-x;
            if(mp.find({z,y})!=mp.end()){
                ans+=mp[{z,y}];
            }
            mp[{numerator[i], denominator[i]}]++;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends
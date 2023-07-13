//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int , int> m;
        map<int,int>seenvalue;
        for(int i=0;i<n;i++){ 
            m[arr[i]]++;
            

        }
        // map<int ,int> :: iterator it;
        for(auto &it : m){
            int value=it.second;
            if(seenvalue[value]>0){ 
                return false;
            }
            seenvalue[value]++;
        }

        
        return true;
       
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int>res;
        long long int ans=0;
        for(long long int i=0;i<N;i++){
            ans^=Arr[i];
        }
        
        int mask=ans&-ans;
        
        int one=0;
        int two=0;
        for(long long int i=0;i<N;i++){
            if((Arr[i]&mask)==mask){
                one^=Arr[i];
            }
            else{
                two^=Arr[i];
            }
        }
        if(one>two){
            res.push_back(one);
        res.push_back(two);
        return res;
            
        }
        res.push_back(two);
            res.push_back(one);
            return res;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
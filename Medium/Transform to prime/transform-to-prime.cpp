//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        int i,sum=0,flag=0,ele=0;
        
        for(i=0;i<N;i++)
        {
            sum = sum+arr[i];
        }
        if(sum==1)
        {
            return 1;
        }
        while(check(sum)==1)
        {
            sum=sum+1;
            ele=ele+1;

        }
        return ele;
    }
    

int check(int sum)
    {
        int i;
         for(i=2;i<=sum-1;i++)
        {
            if(sum%i==0)
            {
              return 1; 
             }
        }
        
    return 0;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
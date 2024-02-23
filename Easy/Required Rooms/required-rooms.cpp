//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int gcd(int N, int M){ // EUCLIDE ALGORITHM : GCD
int rem;
       while(M!=0)
       {
           rem = N%M;
           N=M;
           M=rem;
       }
       // N is answer of GCD
       return N;
}

   int rooms(int N, int M){
       int sum=0,ans=0,l=0;
       sum=N+M; // total no. of foreigners & Indians
       l=gcd(N,M);
       
       if(l>1)
       ans = sum/l; 
       else 
       ans=sum; // room require is equal to all contestant, 1 person stay in each room
       
       return ans;
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        
        Solution ob;
        cout<<ob.rooms(N, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
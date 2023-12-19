//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        if(m==n) return -1;
        int position=0;
        while(m>0 && n>0){
            int bit1;
            int bit2;
            if(m&1) bit1=1;
            else bit1=0;
            if(n&1) bit2=1;
            else bit2=0;
            if(bit1==bit2){
                m=m>>1;
                n=n>>1;
                position+=1;
            }
            else{
                return position +1;
            }
        }
        return position+1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends
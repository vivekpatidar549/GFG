//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int possiblesolution(int A[], int N, int M, int mid){
        int student =1;
        int pagecount=0;
        for(int i=0;i<N;i++){
            if(pagecount+A[i]<=mid){
                pagecount+=A[i];
            }
            else{
                student++;
                if(student>M || A[i]>mid){
                    return false;
                }
                pagecount=0;
                pagecount+=A[i];
                
            }
            
            
        }
        return true;
    }

    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M){
            return -1;
        }
        int start=0;
        int end=0;
        int ans=0;
        for (int i=0;i<N;i++){
            end=end+A[i];
        }
        int mid=start+(end-start)/2;
        
        while(start<=end){
            if(possiblesolution(A,N,M,mid)){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
                
            }
            mid=start+(end-start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
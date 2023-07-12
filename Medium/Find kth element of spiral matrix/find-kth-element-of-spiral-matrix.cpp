//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends



class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        
 		// Your code goes here.
 		int startrow=0;
 		int startcol=0;
 		int endrow=n-1;
 		int endcol=m-1;
 		int temp=1;
 		while(temp<n*m){
 		    for(int i=startcol;i<=endcol;i++){
 		        if(temp==k){
 		            return a[startrow][i];
 		        }
 		        temp++;
 		        
 		    }
 		    startrow++;
 		    
 		    for(int i=startrow;i<=endrow;i++){
 		        if(temp==k){
 		            return a[i][endcol];
 		        }
 		        temp++;
 		        
 		    }
 		    
 		    endcol --;
 		    
 		    for(int i= endcol;i>=startcol;i--){
 		        if(temp==k){
 		            return a[endrow][i];
 		        }
 		        temp++;
 		        
 		    }
 		    endrow--;
 		    
 		    for(int i=endrow;i>=startrow;i--){
 		        if(temp==k){
 		            return a[i][startcol];
 		        }
 		        temp++;
 		        
 		    }
 		    startcol++;
 		    
 		    
 		}
    }
};








//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
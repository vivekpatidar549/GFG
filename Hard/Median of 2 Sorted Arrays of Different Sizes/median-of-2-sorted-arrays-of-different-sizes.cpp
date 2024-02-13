//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        int n1=arr1.size();
        int n2=arr2.size();
        int n=n1+n2;
        int i=0;
        int j=0;
        int ind2=n/2;
        int ind1=ind2-1;
        int count=0;
        int ele1=-1, ele2=-1;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                if(count==ind1) ele1=arr1[i];
                if(count==ind2) ele2=arr1[i];
                i++;
                count++;
            }
            else{
                if(count==ind1) ele1=arr2[j];
                if(count==ind2) ele2=arr2[j];
                j++;
                count++;
            }
        }
        while(i<n1){
            if(count==ind1) ele1=arr1[i];
                if(count==ind2) ele2=arr1[i];
                i++;
                count++;
        }
        while(j<n2){
            if(count==ind1) ele1=arr2[j];
            if(count==ind2) ele2=arr2[j];
                j++;
                count++;
        }
        if(n%2==1) return ele2;
        return (double)(double(ele1+ele2))/2.0;
            
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
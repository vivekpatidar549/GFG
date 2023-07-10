//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int majo=size/2;
        map<int ,int> freq;
        for(int i=0;i<size;i++){
            freq[a[i]] ++;
        }
        for(auto it: freq){
            if(it.second>majo){
                return it.first;
            }
        }
        return -1;
        
        
        // alternative solution with constant space
        // if(size==1){
        //     return a[0];
        // }

        // sort(a,a+size);
        // int i=0;

        // int majo=size/2;
        
        // while(i<size){
        //     int count=1;
        //     while(i+1<size && a[i]==a[i+1]){
        //         count++;
        //         if(count>majo){
        //             return a[i];
        //         }
        //         i++;
        //     }
        //     i++;


        // }
        // return -1;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
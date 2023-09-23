//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1) return a[0];
        if(n==2) return -1;
        int left=0;
        int right=n-1;
        long long leftsum=a[0];
        long long rightsum=a[n-1];
        while(left<right){

            if(leftsum>=rightsum){
                right--;
                rightsum+=a[right];
                
            }
            else if(rightsum>=leftsum){
                left++;
                leftsum+=a[left];
                
            }
            
        }
        if(leftsum==rightsum){
                return left+1;
            }
            
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
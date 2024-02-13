//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here 
            int temparr[n+n],mid,first,last,secondmid,k;
           k=0;
           for(int i=0;i<n;i++)
           {
               temparr[i]=ar1[i];
           }
           for(int i=n;i<n+n;i++)
           {
               temparr[i]=ar2[k];
               k++;
           }
           sort(temparr,temparr+n+n);
           first=0;
           last=n+n-1;
           mid=first+last/2;
           secondmid=mid+1;
           return temparr[mid]+temparr[secondmid];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
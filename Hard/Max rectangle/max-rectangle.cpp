//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

/*You are required to complete this method*/

class Solution{
  public:
  vector<int> nextsmallerelements(int * arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int current=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=current){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> previouselements(int * arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int current=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=current){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    
  int largestRectangleArea(int *arr,int n) {
        if(n==1) return arr[0];
        vector<int>next(n);
        next=nextsmallerelements(arr,n);
        vector<int> prev(n);
        prev=previouselements(arr,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]- prev[i]- 1;
            int newarea= l*b;
            area=max(area,newarea);


        }
        return area;
        
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // compute area for first row
        int area= largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                // row update
                if(M[i][j]!=0){
                    M[i][j]= M[i][j]+M[i-1][j];
                }
                else{
                    M[i][j]=0;
                }
                // entire row updated
                
        }
        area=max(area,largestRectangleArea(M[i],m));
        
    }
    return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
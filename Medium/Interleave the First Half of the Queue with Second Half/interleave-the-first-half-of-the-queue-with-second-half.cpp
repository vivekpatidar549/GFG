//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack <int>s;
        int n=q.size();
        // adding first half elements in stack
        for(int i=0;i<n/2;i++){
            int element= q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element=s.top();
            s.pop();
            q.push(element);
            
        }
        for(int i=0;i<n/2;i++){
            int fr=q.front();    // to bring this elements in front we will pop from front and push in back
            q.pop();
            q.push(fr);
        }
       
    
        // numbers we got from stack were in reversed order so to miligate
        //this issue we will again put in stack and process
        
        for(int i=0;i<n/2;i++){
            int element= q.front();
            q.pop();
            s.push(element);
        }
        while(!s.empty()){
            int element=s.top();
            s.pop();
            q.push(element);
            int fr=q.front();    // to bring this elements in front we will pop from front and push in back
            q.pop();
            q.push(fr);
        }
        vector<int> ans;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            ans.push_back(element);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
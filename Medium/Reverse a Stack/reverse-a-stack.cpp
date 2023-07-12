//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
//User function Template for C++

class Solution{
public:
    void insertatbottom(stack<int> &stack,int num){
    if(stack.empty()){
        stack.push(num);
        return;
    }
    int temp=stack.top();
    stack.pop();
    // recursive call
    insertatbottom(stack, num);
    stack.push(temp);
}
    void Reverse(stack<int> &St){
        if(St.empty()){
        return;
    }
    int num=St.top();
    St.pop();
    // recursive call
    Reverse(St);
    insertatbottom(St,num);
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends



bool matches(char top,char ch){
        if(top=='{' && ch=='}' || top=='(' && ch==')'|| top=='[' && ch==']' ) {
            return true;
        }
        return false;
    }
    
bool valid(string s)
{
    // code here
    stack <char>ans;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch =='(' || ch =='[' || ch =='{'){
                ans.push(ch);
            }
        else{
            if(!ans.empty()){
                char top=ans.top();
                if(matches(top,ch)){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            
        }   
        
        }
        if(ans.empty()){
            return true;
        }
        else{
            return false;
        }
}
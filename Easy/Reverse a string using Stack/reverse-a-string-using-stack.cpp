//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string


//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    string ans="";
    stack<char> temp;
    for(int i=0;i<len;i++){
        char ch=S[i];
        temp.push(ch);
    }
    int i=0;
    while(!temp.empty()){
        char ch=temp.top();
        S[i]=ch;
        temp.pop();
        i++;
    }
    return S;
    
}
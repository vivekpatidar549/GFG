//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node*temp=head;
        Node*evenh=NULL;
        Node*event=NULL;
        Node*oddh=NULL;
        Node*oddt=NULL;
        while(temp){
            if(oddh==NULL && temp->data%2==1){
                oddh=temp;
                oddt=temp;
            }
            else if(evenh==NULL && temp->data%2==0){
                evenh=temp;
                event=temp;
            }
            Node*curr=temp->next;
            if(temp->data%2==0){
                event->next=temp;
                event=event->next;
            }
            else{
                oddt->next=temp;
                oddt=oddt->next;
            }
            temp=curr;
        }
        if(evenh==NULL){
            oddt->next=NULL;
            return oddh;
        }
        else if(oddh==NULL){
            event->next=NULL;
            return evenh;
        }
        event->next=oddh;
        oddt->next=NULL;
        return evenh;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends
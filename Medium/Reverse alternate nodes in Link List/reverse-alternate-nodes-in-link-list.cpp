//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(struct Node* head){
        Node*current=head;
        Node*prev=NULL;
        while(current){
            Node*temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        return prev;
        
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        Node* newlist=new Node(0);
        Node* newtemp = newlist;
        bool flag=false;
        Node *current=odd;
        Node * prev= NULL;
        while(current){
            if(flag==true){
                Node *temp= new Node(current->data);
                newtemp->next=temp;
                newtemp=newtemp->next;
                prev->next=current->next;
                if(current->next!=NULL){
                    current=current->next;
                }
                else{
                    break;
                }
                flag=false;
            }
            else{
                prev=current;
                current=current->next;
                flag=true;
            }
        }
         newlist->next = reverse(newlist->next);
        prev->next=newlist->next;
        
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends
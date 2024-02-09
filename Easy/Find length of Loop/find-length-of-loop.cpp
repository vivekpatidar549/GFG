//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
Node* checkloop(struct Node * head){
         if(head==NULL) return NULL;
         struct Node *slow=head;
         struct Node *fast=head;
         while(fast!=NULL && fast->next!=NULL){
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast){
                 return slow;
             }
         }
         return NULL;
     }
int countNodesinLoop(struct Node *head)
{
    // Code here
    if(checkloop(head)==NULL) return 0;
        struct Node *point=checkloop(head);
        int ans=1;
        struct Node *temp = point->next;
        while(temp!=point){
            ans+=1;
            temp=temp->next;
        }
        return ans;
}

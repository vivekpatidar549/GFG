//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node * reverse(Node* head){
    Node* prev=NULL;
    while(head){
        Node * nextpoint= head->next;
        head->next = prev;
        prev=head;
        head=nextpoint;
    }
    return prev;
}
Node* sumpart(Node* head1, Node* head2) {
    Node* sol = new Node(0);
    Node* ans = sol;
    int carry = 0;

    while (head1 != NULL && head2 != NULL) {
        int sum = (carry + head1->data + head2->data) ;
        carry = sum/ 10;
        sum%=10;
        ans->next = new Node(sum);
        ans = ans->next;
        head1 = head1->next;
        head2 = head2->next;
        
    }

    while (head1 != NULL) {
        int sum = (carry + head1->data) ;
        carry = sum/ 10;
        sum%=10;
        ans->next = new Node(sum);
        ans = ans->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        int sum = (carry + head2->data) ;
        carry = sum/ 10;
        sum%=10;
        ans->next = new Node(sum);
        ans = ans->next;
        head2 = head2->next;
    }

    while (carry != 0) {
        int sum = carry;
        carry = sum/ 10;
        sum%=10;
        ans->next = new Node(sum);
        ans = ans->next;
       
    }

    return sol->next;
}

    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first==NULL) return second;
        if(second==NULL) return first;
        if(first->next==NULL && second->next==NULL ){
            sumpart(first,second);

        }
        first= reverse(first);
        second=reverse(second);
        Node* ans= sumpart(first,second);
        return reverse(ans);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
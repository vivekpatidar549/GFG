//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




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

class Solution{
    private:
    Node * middlepointer(Node* head){
        Node*slow = head;
        Node*fast= head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            // if(fast->next!=NULL){
            //     fast=fast->next;
            // }
            slow=slow->next;
            
        }
        return slow;
        
    }

    Node * reverse(Node * head){
        Node* current=head;
        Node* prev=NULL;
        Node* store=NULL;
        while(current!=NULL){
            store= current->next;
            current->next=prev;
            prev=current;
            current=store;
            
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        /*Node* temp=head;
        vector<int> ans;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp=temp->next;
        }
        
    int start=0;
    int end=ans.size()-1;
    while(start<=end){
        if(ans[start]==ans[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;*/
    
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node *middle= middlepointer(head);
    // reverse list after mid
    Node * temp=middle->next;
    middle->next=reverse(temp);
    // comparing both half
    Node*head1= head;
    Node*head2= middle->next;
    while (head2 != NULL) {
    if (head1->data == head2->data) {
        head1 = head1->next;
        head2 = head2->next;
    } else {
        return false;
    }
}

    // reverse list again
    temp=middle->next;
    middle->next=reverse(temp);
    return true;
    
    
    
    }
};




//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
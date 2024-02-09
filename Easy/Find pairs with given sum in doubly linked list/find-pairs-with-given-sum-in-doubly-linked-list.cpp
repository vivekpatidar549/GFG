//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
    Node *findtail(Node *temp)
    {
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        return temp;
    }
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *temp1=head;
        Node *tail=findtail(head);
        vector<pair<int,int>>ans;
        while(temp1->data<tail->data)
        {
            if(temp1->data+tail->data==target) 
            {
                ans.push_back({temp1->data,tail->data});
                temp1=temp1->next;
                tail=tail->prev;
            }
            else if(temp1->data+tail->data<target) temp1=temp1->next;
            else if(temp1->data+tail->data>target) tail=tail->prev;
            
        }
       
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
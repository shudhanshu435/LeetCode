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
    struct Node* reverse(struct Node* head){
        if(!head||!head->next)return head;
        struct Node* prev=NULL;
        struct Node* curr=head;
        struct Node* temp=NULL;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        l1=reverse(l1);
        l2=reverse(l2);
        struct Node* dummy,*head;
        dummy = head = new struct Node(-1);
        if(!l1)return l2;
        if(!l2)return l1;
        int carry=0,first=0,second=0;
        while(l1||l2){
            if(l1)first=l1->data;
            else first=0;
            if(l2)second=l2->data;
            else second=0;

            int sum=first+second+carry;
            carry=sum/10;
            sum=sum%10;

            struct Node* temp = new struct Node(sum);
            dummy->next=temp;

            dummy=dummy->next;

            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        if(carry)dummy->next=new struct Node(1);

        return reverse(head->next);
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
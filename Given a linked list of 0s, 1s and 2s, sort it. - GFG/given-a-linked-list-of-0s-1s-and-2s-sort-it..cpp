//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        // Add code here
        Node* zero = new Node(-1);
        Node* ztail = zero;
        Node* one = new Node(-1);
        Node* otail = one;
        Node* two = new Node(-1);
        Node* ttail = two;
        Node * temp=head;
        while(temp){
            if(temp->data==0){
                ztail->next=temp;
                ztail=ztail->next;
            }
            else if(temp->data==1){
                otail->next=temp;
                otail=otail->next;
            }
            else {
                ttail->next=temp;
                ttail=ttail->next;
            }
            temp=temp->next;
        }
        if(one->next){
            ztail->next=one->next;
            if(two->next){
                otail->next=two->next;
                ttail->next=NULL;
            }
            else otail->next=NULL;
        }
        else {
            if(two->next){
            ztail->next=two->next;
            ttail->next=NULL;
            }
            else otail->next=NULL;
        }
        
        return zero->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
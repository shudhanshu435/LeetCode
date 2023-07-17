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
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
    
}; */
class Solution{
    public:
    
    
    
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // if(!head->next)return head->data;
        // int count=0;
        // Node *temp=head;
        // while(temp!=NULL){
        //     count++;
        //     temp=temp->next;
        // }
        
        // int len=floor(count/2);
        
        // Node *curr=head;
        // int i=0,ans=0;
        // while(i++<len){
        //     curr=curr->next;
        //     ans=curr->data;
        // }
        
        // return ans
        
        //other approach--------------------------------------------
        if(!head->next)return head->data;
        
        Node *slow = head;
        Node *fast=head->next;
        if(!head->next->next)return head->next->data;
        while(fast){
            fast=fast->next;
            if(fast!=NULL)fast=fast->next;
            slow=slow->next;
        }
        
        return slow->data;
        
        
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
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}

// } Driver Code Ends
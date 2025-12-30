/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node* revers(Node* temp)
{
    Node* prev = NULL;
    Node* curr = temp;
    Node* nextnode = NULL;
    while(curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node* temp1 = revers(head1);
        Node* temp2 = revers(head2);
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        // return temp2;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL || carry)
        {
            int sum = carry;
           
            if(temp1)
            {
                sum += temp1 -> data;
                temp1 = temp1->next;
            }
            if(temp2)
            {
                sum += temp2 -> data;
                temp2 = temp2->next;
            }
                Node* node = new Node(sum%10);
                tail -> next = node;
                tail = tail -> next; 
                carry = sum / 10;
        }
        Node* ans = revers(dummy->next);
        while(ans && ans -> data == 0)
        {
             ans  = ans->next;
        }
        return ans ? ans : new Node(0);
    }
};
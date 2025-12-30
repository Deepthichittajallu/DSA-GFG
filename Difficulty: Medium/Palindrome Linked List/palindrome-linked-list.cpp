/*
class Node {
  public:
    int data;
    Node *next;

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
    bool isPalindrome(Node *head) {
        //  code here
        Node* temp1 = new Node(head->data);
        Node* tempo = head->next;
        Node* dummy = temp1;
        while(tempo != NULL)
        {
            Node* newNode = new Node(tempo -> data);
            dummy-> next = newNode;
            dummy = dummy->next;
            tempo = tempo->next;
        }
         Node* temp2 = revers(head);
        while(temp2 != NULL)
        {
            if(temp2->data != temp1->data) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};
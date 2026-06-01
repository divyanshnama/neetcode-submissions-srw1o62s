/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* curr=head;
       ListNode* prev=nullptr;
       int size =0;
       while(curr)
       {
        curr=curr->next;
        size++;
       }
       size =size-n;
        if (size == 0) {
             ListNode* temp = head;
             head = head->next;
            delete temp;
            return head;
}
       curr=head;


       while(size!=0)
       {
        prev=curr;
        curr=curr->next;
        size--;
       }
       prev->next=curr->next;
       delete(curr);

       return head;

    }
};

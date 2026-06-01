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
    //approch
        //find mid using slow fast pointer
        //divide list into two and reverse second list
        //merge both the list
public:
    void reorderList(ListNode* head) {

        //find mid
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* first = head;
        //reverse
        ListNode* second = reverseList(slow->next);
        slow->next = nullptr;

        //merge
        while(second)
        {
            ListNode* temp1=first->next;
            first->next=second;
            ListNode* temp2 =second->next;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }



    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev =nullptr;
        ListNode* curr =head;
        ListNode* front =nullptr;

        while(curr)
        {
            front = curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        InsertCopyInBetweem(head);
        ConnectRandomPointers(head);
        return DeepCopyList(head);
    }
    void InsertCopyInBetweem(Node* head)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* nextNode = temp->next;
            Node* copy = new Node(temp->val);
            copy->next =nextNode;
            temp->next=copy;
            temp=nextNode;
        }
    }

    void ConnectRandomPointers(Node* head)
    {
        Node*temp =head;
        while(temp!=NULL)
        {
            Node* copyNode =temp->next;
            if(temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = NULL;

            temp=temp->next->next;
        }
    }

    Node* DeepCopyList(Node* head)
    {
        Node* temp =head;
        Node* dummyNode = new Node(-1);
        Node* res=dummyNode;

        while(temp!=NULL)
        {
            res->next=temp->next;
            res =res->next;

            temp->next=temp->next->next;
            temp =temp->next;
        }
        return dummyNode->next;
    }
};

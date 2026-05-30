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
        Node dummy(0);
        Node * tail = &dummy;

        Node * temp = head;
        while(temp!=NULL){
            Node * node = new Node (temp->val);
            tail->next=node;
            tail=tail->next;
            temp=temp->next;
        }
        temp = head;
        unordered_map<Node*,Node*>mp;
        Node * temp2 = dummy.next;
        while(temp!=NULL){
            mp[temp]= temp2;
            temp=temp->next;
            temp2=temp2->next;
        }

        temp = head;
        temp2 = dummy.next;

        while(temp!=NULL){
            temp2->random = mp[temp->random];
            temp2=temp2->next;
            temp=temp->next;
        }

        return dummy.next;

    }
};

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
    int getLen(ListNode* head){
        ListNode* temp = head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next=head;
        
        ListNode * prev = &dummy;
        ListNode * curr = head;
        int len = getLen(head);
        for(int i=0;i<len-n;i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete(curr);
        curr=prev->next;

        return dummy.next;
    }
};

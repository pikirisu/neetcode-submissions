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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode * temp = &dummy;
        
        for(int i=1; i<left; i++){
            temp=temp->next;
        }

        ListNode * revHead = temp->next;

        ListNode * revTail = revHead;

        for(int i=0; i<right-left; i++){
            revTail = revTail->next;
        }

        ListNode * afterRight = revTail->next;
        revTail->next = NULL;

        ListNode * prev = NULL;
        ListNode * newTail = revHead;

        while(revHead!=NULL){
            ListNode * store = revHead->next;
            revHead->next = prev;
            prev=revHead;
            revHead = store;
        }

        temp->next = prev;
        newTail->next = afterRight;

        return dummy.next;
    }
};
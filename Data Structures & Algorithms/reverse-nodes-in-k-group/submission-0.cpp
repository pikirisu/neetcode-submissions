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

pair<ListNode*, ListNode*> reverseNodes(ListNode* head) {
    // Edge case: if the list is empty
    if (head == nullptr) {
        return {nullptr, nullptr};
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* tail = head;

    while (curr != nullptr) {
        ListNode* fwd = curr->next; 
        curr->next = prev;          
        prev = curr;                
        curr = fwd;
    }

    return {prev, tail};
}
int getLen(ListNode * head){
    if(head==NULL) return 0;
    int count = 0;
    ListNode * temp = head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    return count;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        int n = getLen(head);
        ListNode dummy(0);
        ListNode * tail = &dummy;
        ListNode * curr = head;
        while(n>=k){
            ListNode * gr_head = curr;
            ListNode * gr_tail = curr;

            // Reach next tail
            for(int i=0;i<k-1;i++){
                gr_tail = gr_tail->next;
            }
            // Store next
            ListNode * nexthead = gr_tail -> next;
            // Disconnect tail
            gr_tail->next = NULL;

            pair<ListNode *, ListNode *> reversed = reverseNodes(gr_head);

            tail->next = reversed.first;
            tail=reversed.second;

            curr = nexthead;
            n-=k;
        }

        tail->next = curr;
        return dummy.next;
    }
};

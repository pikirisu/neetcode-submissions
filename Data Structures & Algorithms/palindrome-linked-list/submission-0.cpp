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
    ListNode * reverseList(ListNode * head){
        ListNode * prev = nullptr;
        ListNode * curr = head;

        while(curr){
            ListNode * store = curr->next;
            curr->next = prev;
            prev = curr;
            curr = store;
        }

        return prev;
    }

    bool compareList(ListNode * head, ListNode * head2){
        while(head && head2){
            if(head->val!=head2->val)
            return false;

            head=head->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = nullptr;

        while(fast && fast->next){
            fast=fast->next->next;
            prev = slow;
            slow = slow ->next;
        }

        prev->next = nullptr;
        slow = reverseList(slow);

        return compareList(head,slow);
        
    }
};
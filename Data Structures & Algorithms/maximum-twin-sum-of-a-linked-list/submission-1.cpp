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
    int pairSum(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            prev = slow;
            slow=slow->next;
        }

        prev->next = nullptr;
        
        slow = reverseList(slow);
        int maxm = 0;
        while(head && slow){
            int curr_sum = head->val + slow->val;
            maxm = max(maxm,curr_sum);
            head=head->next;
            slow=slow->next;
        }
        return maxm;
    }
};
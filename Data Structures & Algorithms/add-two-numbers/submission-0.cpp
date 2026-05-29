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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode * tail = &dummy;
        while(l1!=NULL && l2!=NULL){
            int data1 = l1->val;
            int data2 = l2->val;

            int sum = data1 + data2 + carry;
            carry = sum/10;

            ListNode * node = new ListNode(sum%10);
            tail->next = node;
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }

        if(l1!=NULL){
            while(l1!=NULL){
            int sum = carry + l1->val;
            carry = sum/10;
            ListNode * node = new ListNode(sum%10);
            tail->next = node;
            tail=tail->next;
            l1=l1->next;
            }
        }
        
        if(l2!=NULL){
            while(l2!=NULL){
            int sum = carry + l2->val;
            carry = sum/10;
            ListNode * node = new ListNode(sum%10);
            tail->next = node;
            tail=tail->next;
            l2=l2->next;
            }
        }

        if(carry){
            ListNode * node = new ListNode(carry);
            tail->next = node;
            tail=tail->next;
        }

        return dummy.next;
    }
};

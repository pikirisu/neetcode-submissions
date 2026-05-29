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
    // ListNode * merge2lists(ListNode* l1, ListNode * l2){
    //     ListNode dummy(0);
    //     ListNode * tail = &dummy;

    //     while(l1!=NULL && l2!=NULL){
    //         if(l1->val<=l2->val){
    //             tail->next = l1;
    //             l1=l1->next;
    //         }
    //         else{
    //             tail->next = l2;
    //             l2=l2->next;
    //         }
    //         tail=tail->next;
    //     }

    //     if(l1!=NULL){
    //         tail->next=l1;
    //     }

    //     if(l2!=NULL){
    //         tail->next = l2;
    //     }

    //     return dummy.next;
    // }

    struct comparator {
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, comparator> pq;

        for(auto head : lists){
            if(head) pq.push(head);
        }
        ListNode dummy(0);
        ListNode * tail = &dummy;
        while(!pq.empty()){
            ListNode * top = pq.top();
            pq.pop();

            tail->next = top;
            tail=tail->next;

            if(top->next) pq.push(top->next);
        }

        return dummy.next;
    }
};

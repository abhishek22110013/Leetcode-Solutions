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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head;
        ListNode* evenhead = head->next;
        ListNode* even = head->next;
        while(even && even->next){
            odd->next = odd->next->next;
            odd = odd->next;
            //if (odd->next == nullptr) break;
            even->next = even->next->next;
            even = even->next;
            //if (even->next == nullptr) break;
        }
        odd->next = evenhead;
        return head;
    }
};
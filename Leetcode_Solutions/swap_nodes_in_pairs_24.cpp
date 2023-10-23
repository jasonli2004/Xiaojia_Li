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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newhead = head->next;
        ListNode* cur = head;
        ListNode* prev = new ListNode(0);
        ListNode* temp;
        while (cur != nullptr && cur->next != nullptr){
            temp = cur->next->next;
            prev->next= cur->next;
            cur->next->next = cur;
            cur->next = temp;
            prev = cur;
            cur = temp;
        }
        return newhead;
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr){
            return head;
        }
        if (head->next == nullptr){
            return head->next;
        }
        ListNode* newhead = new ListNode(0,head);
        ListNode* fast = newhead;
        ListNode* slow = newhead;
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == newhead){
            return head->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
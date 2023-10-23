/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if (!fast || !fast->next){
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;
        while (fast != slow){
            if (!fast || !fast->next){
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        while (fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
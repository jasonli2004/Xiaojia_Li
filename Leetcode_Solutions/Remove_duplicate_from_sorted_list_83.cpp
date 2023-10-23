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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        int prev = head->val;
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr){
            if (cur->next->val == prev){
                cur->next = cur->next->next;
            }
            else{
                prev = cur->next->val;
                cur = cur->next;
            }
        }
        return head;
        
    }
};
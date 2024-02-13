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
        if (head == NULL){
            return head;
        }
        if (head->next == NULL){
            return head->next;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        while (fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == NULL){
            return slow->next;
        }
        else{
            slow->next = slow->next->next;
        }
        return head;
    }

};
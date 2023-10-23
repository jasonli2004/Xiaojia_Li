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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (a != nullptr && b != nullptr){
            if (a->val <= b->val){
                cur->next = a;
                cur = cur->next;
                a = a->next;
            }
            else{
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
        }
        if (a != nullptr){
            cur->next = a;
        }
        if (b != nullptr){
            cur->next = b;
        }
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = nullptr;
        head = sortList(head);
        temp = sortList(temp); 
        ListNode* newhead = merge(head,temp);
        return newhead;
    }
};
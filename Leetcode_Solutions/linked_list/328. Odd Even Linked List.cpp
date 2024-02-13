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
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* odd = new ListNode(0);
        ListNode* odd_head = odd;
        ListNode* even = new ListNode(0);
        ListNode* even_head = even;
        while (head != nullptr && head->next != nullptr){
            odd->next = head;
            odd = odd->next;
            head = head->next;
            even->next = head;
            even = even->next;
            head = head->next;
        }
        if (head != nullptr){
            odd->next = head;
            odd = head;
            even->next = nullptr;
        }
        even_head = even_head->next;
        odd->next = even_head;
        return odd_head->next;
    }
};
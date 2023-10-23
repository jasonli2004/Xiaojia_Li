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
        int num = 0;
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return head;
        }
        ListNode* cur = head;
        ListNode* second = cur->next;
        ListNode* temp;
        while (cur->next->next != nullptr){
            temp = cur->next;
            cur->next = cur->next->next;
            cur = temp;
            num++;
        }
        if (num%2 == 1){
            cur->next->next = second;
            cur->next = nullptr;
        }
        else{
            cur->next = second;
        }
        return head;
    }
};
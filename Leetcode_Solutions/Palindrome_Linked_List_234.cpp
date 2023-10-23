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
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = nullptr;
        ListNode* temp;
        while (head){
            temp = head->next;
            head->next = tail;
            tail = head;
            head = temp;
        }
        return tail;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (true){
            if (fast->next == nullptr || fast->next->next == nullptr){
                fast = slow->next;
                fast = reverseList(fast);
                slow->next = nullptr;
                slow = head;
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        while (slow != nullptr && fast != nullptr){
            if (slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
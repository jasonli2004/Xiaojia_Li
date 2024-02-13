/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         while (head != NULL){
//             if (head->val != 1000001){
//                 head->val = 1000001;
//                 head = head->next;
//             }
//             else{
//                 return 1;
//             }
//         }
//         return 0;
//     }
// };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL){
            return 0;
        }
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                return 1;
            }
        }
        return 0;
    }
};
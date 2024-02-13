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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        head = newHead;
        ListNode* loc = newHead;
        while (head != NULL && head->next != NULL){
            if (head != NULL)    cout << head->val;
            if (head->next->val < x){
                if (loc == head){
                    head = head->next;
                    loc = loc->next;
                    continue;
                }
                ListNode* temp = head->next->next;
                head->next->next = loc->next;
                loc->next = head->next;
                loc = loc->next;
                head->next = temp;                
            }
            else{
                head = head->next;
            }            
        }
        return newHead->next;     
    }
};